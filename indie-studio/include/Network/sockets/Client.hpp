//
// Client.hpp for  in /home/agor_m/github/tests_with_cpp_sockets/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Mon May  2 15:20:47 2016 Maxime Agor
// Last update Sun Jun  5 18:54:05 2016 Maxime Agor
//

#ifndef CLIENT_HPP_
# define CLIENT_HPP_

# include <functional>
# include <thread>
# include <atomic>
# include <sys/time.h>

# include "Network/sockets/Sockets.hpp"

namespace Socket
{
  class Client
  {
  public:
    Client();
    virtual ~Client();

    /* CLIENT CONFIGURATION API */

    void start(std::string address, int port);
    void stop();

    // set the timeout in ms
    void	setTimeout(float t);
    float	getTimeout() const;

    /* CALLBACKS API */
    // param0 : *this

    // called on client read accessibility
    // param1 : size_t : size possible to read (can change meanwhile)
    void  OnReadPossible(std::function < void (Client &, size_t) > const &callback);
    // called on client write accessibility
    void  OnWritePossible(std::function < void (Client &) > const &callback);
    // called on client start
    void  OnStart(std::function < void (Client &, std::string const &address, int port) > const &callback);
    // called on client stop
    void  OnDisconnect(std::function < void (Client &) > const &callback);


    /* I/O API */
    int     read(void *buffer, size_t size);
    int     write(void const *buffer, size_t size);
    size_t  bytesAvailables() const;

  protected:
    std::string						_address;
    int							_port;
    SOCKET						_fd;
    std::thread						_stateThread;
    timeval						_timeout;

    std::function < void (Client &) >			_OnConnect;
    std::function < void (Client &) >			_OnDisconnect;
    std::function < void (Client &, size_t) >		_OnReadPossible;
    std::function < void (Client &) >			_OnWritePossible;
    std::function < void (Client &, std::string const &, int) >	_OnStart;

  private:
    void  stateChecker();
    void disconnect();
    fd_set						_fd_set;
    std::atomic<bool>					_isRunning;
  };
};

#endif
