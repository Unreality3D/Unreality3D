#include <errno.h>
#include <algorithm>

#ifndef _WIN32
# include <sys/select.h>
#endif

#include <iostream>
#include <fcntl.h>


#include "Network/sockets/Client.hpp"

namespace Socket
{
  static inline int getError()
  {
#ifdef _WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
  }

  static bool setNonBloccking(SOCKET sock)
  {
#ifdef _WIN32
    u_long mode = 1;
    if ((ioctlsocket(sock, FIONBIO, &mode)) == -1)
      return false;
#else
    if ((fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) | O_NONBLOCK)) == -1)
      return false;
#endif
    return true;
  }

  Client::Client()
  {
    _stateThread = std::thread();
    _OnDisconnect = NULL;
    _OnReadPossible = NULL;
    _OnWritePossible = NULL;
    _OnStart = NULL;
    _isRunning = false;
    _timeout.tv_sec = 10;
    _timeout.tv_usec = 0;
  }

  Client::~Client()
  {
  }

  void  Client::start(std::string address, int port)
  {
    SOCKADDR_IN	addr;
    PROTOENT	*proto;

    // port checking
    if (port <= 0 || port > 0xFFFF)
      throw SocketCreateError(std::string("client : bad port"));
    _address = address;
    _port = port;

    // create socket
    proto = getprotobyname("tcp");

    if ((_fd = socket(AF_INET, SOCK_STREAM, proto ? proto->p_proto : 0)) == -1)
      throw SocketCreateError(std::string("client : ") +
			      std::string(strerror(getError())));

    if (!setNonBloccking(_fd))
      throw SocketCreateError(std::string("client : ") +
			      std::string("cannot set non blocking mode for the client fd"));

    // bind
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, address.c_str(), &addr.sin_addr) < 0)
      throw SocketConnectError("client : " + std::string(strerror(getError())));

    if (connect(_fd, (SOCKADDR *)&addr, sizeof(addr)) < 0)
      {
	if (errno != EINPROGRESS)
	  throw SocketConnectError("client : " + std::string(strerror(getError())));
      }

    // create select() sets
    FD_ZERO(&_fd_set);
    FD_SET(_fd, &_fd_set);

    // run the event loop
    _isRunning = true;
    if (!_stateThread.joinable())
      _stateThread = std::thread(&Client::stateChecker, this);

    // start event
    if (_OnStart)
      _OnStart(*this, _address, _port);
  }

  void  Client::stop()
  {
    _isRunning = false;
    if (_stateThread.joinable())
      _stateThread.join();
  }

  void  Client::setTimeout(float t)
  {
    _timeout.tv_sec = t / 1000;
    _timeout.tv_usec = (int)(t * 1000) % (1000 * 1000);
  }

  float Client::getTimeout() const
  {
    return (_timeout.tv_sec * 1000) + ((float)(_timeout.tv_usec) / 1000);
  }

  void  Client::OnDisconnect(std::function < void (Socket::Client &) > const &callback)
  {
    _OnDisconnect = callback;
  }

  void  Client::OnReadPossible(std::function < void (Socket::Client &, size_t) > const &callback)
  {
    _OnReadPossible = callback;
  }

  void  Client::OnWritePossible(std::function < void (Socket::Client &) > const &callback)
  {
    _OnWritePossible = callback;
  }

  void  Client::OnStart(std::function < void (Socket::Client &, std::string const &, int) > const &callback)
  {
    _OnStart = callback;
  }

  int  Client::read(void *buffer, size_t size)
  {
    int tmp;

    if ((tmp = ::recv(_fd, (char *)buffer, size, 0)) == -1)
      {
	throw SocketIOError(std::string(strerror(getError())));
      }
    if (size != 0 && tmp == 0)
      disconnect();
    return tmp;
  }

  int  Client::write(void const *buffer, size_t size)
  {
    int tmp;

    if ((tmp = ::send(_fd, (char *)buffer, size, 0)) == -1)
      {
	if (errno == ECONNRESET)
	  disconnect();
	else
	  throw SocketIOError(std::string(strerror(getError())));
      }
    return tmp;
  }

  size_t Client::bytesAvailables() const
  {
#ifdef _WIN32
    u_long bytes = 0;
#else
    size_t bytes = 0;
#endif

    if (::ioctl(_fd, FIONREAD, &bytes) == -1)
      {
	throw SocketIOError(std::string(strerror(getError())));
      }
    return bytes;
  }

  void Client::disconnect()
  {
    closesocket(_fd);
    if (_OnDisconnect)
      _OnDisconnect(*this);
  }

  void Client::stateChecker()
  {
    int fd;
    int nb_fd;
    fd_set read_set, write_set;
    timeval timeout;

    // event loop
    while (_isRunning)
      {
	SLEEPMS(0);
	memcpy(&read_set, &_fd_set, sizeof(_fd_set));
	memcpy(&write_set, &_fd_set, sizeof(_fd_set));

	timeout = _timeout;
	// wait for an event
	nb_fd = select(_fd + 1, &read_set, &write_set, NULL, &timeout);
	if (nb_fd < 0 && errno != EINTR)
	  throw SocketIOError(std::string(strerror(getError())));

	if (FD_ISSET(_fd, &read_set))
	  {
	    // read event
	    if (bytesAvailables() == 0)
	      {
		break;
	      }
	    else if (_OnReadPossible)
	      _OnReadPossible(*this, bytesAvailables());
	  }

	// write event
	if (FD_ISSET(_fd, &write_set))
	  {
	    if (_OnWritePossible)
	      _OnWritePossible(*this);
	  }
      }
    disconnect();
  }
};
