//
// Broker.cpp for  in /home/agor_m/epitech/cpp_indie_studio/network/src
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sat Jun  4 18:09:46 2016 Maxime Agor
// Last update Sun Jun  5 18:57:50 2016 Maxime Agor
//

#include <algorithm>
#include "Network/Broker.hpp"

namespace network
{
  // broker start/stop
  void	Broker::start(int port, size_t maxClients)
  {
    _server.OnConnect(
		      [this](Socket::Server &s, int fd)
		      {
			this->onConnect(s, fd);
		      });
    _server.OnDisconnect(
			 [this](Socket::Server &s, int fd)
			 {
			   this->onDisconnect(s, fd);
			 });
    _server.OnReadPossible(
			   [this](Socket::Server &s, int fd, size_t size)
		      {
			this->onReadPossible(s, fd, size);
		      });
    _server.OnWritePossible(
		      [this](Socket::Server &s, int fd)
		      {
			this->onWritePossible(s, fd);
		      });

    _server.start(port, maxClients);
  }

  void	Broker::stop()
  {
    _server.stop();
  }

  // TCP server callbacks
  void	Broker::onConnect(Socket::Server &s, int fd)
  {
    std::cout << "connexion etablished" << std::endl;
    _clients[fd] = network::Client(fd);
    _clients[fd].deserializer.OnConnect(
					[fd, this] (IndieProtocol::Connect c)
					{
					  this->onPacketConnect(fd, c);
					});
    _clients[fd].deserializer.OnList(
					[fd, this] (IndieProtocol::List l)
					{
					  this->onPacketList(fd, l);
					});
    _clients[fd].deserializer.OnMessage(
					[fd, this] (IndieProtocol::Message m)
					{
					  this->onPacketMessage(fd, m);
					});
  }

  void	Broker::onDisconnect(Socket::Server &s, int fd)
  {
    std::cout << "connexion interrupted" << std::endl;
    auto found = _clients.find(fd);
    if (found != _clients.end())
      _clients.erase(found);
  }

  void	Broker::onReadPossible(Socket::Server &s, int fd, size_t size)
  {
    auto found = _clients.find(fd);
    char *tmp;

    if (found != _clients.end())
      {
	tmp = new char[size];
	s.read(fd, tmp, size);
	(*found).second.deserializer(IndieProtocol::Serialized(size, tmp));
	delete[] tmp;
      }
  }

  void	Broker::onWritePossible(Socket::Server &s, int fd)
  {
    auto found = _clients.find(fd);
    IndieProtocol::Serialized tmp;

    if (found != _clients.end())
      {
	while ((*found).second.writeBuffer.size())
	  {
	    tmp = (*found).second.writeBuffer.back();
	    (*found).second.writeBuffer.pop_back();
	    s.write(fd, tmp.data, tmp.size);
	  }
      }
  }

  // Client class
  void	Client::deserialize(void *buff, size_t size)
  {
    deserializer(IndieProtocol::Serialized(size, buff));
  }

  // Deserializer callbacks
  void	Broker::onPacketConnect(int fd, IndieProtocol::Connect conn)
  {
    std::cout << "FD : " << fd << " : CONNECT" << std::endl;
    std::cout << conn.name << std::endl;

    auto found = _clients.find(fd);
    if (found == _clients.end())
      {
	_clients[fd] = Client(fd);
	found = _clients.find(fd);
      }
    (*found).second.connected = true;
    (*found).second.name = conn.name;
  }

  // the broker should not receive any LIST message, but... Anyway...
  void	Broker::onPacketList(int fd, IndieProtocol::List list)
  {
    std::cout << "FD : " << fd << " : LIST" << std::endl;
    for (auto it = list.clients.begin(); it != list.clients.end(); ++it)
      {
	std::cout << *it << std::endl;
      }

  }

  void	Broker::onPacketMessage(int fd, IndieProtocol::Message msg)
  {
    std::cout << "FD : " << fd << " : MESSAGE" << std::endl;
    std::cout << msg.target << std::endl;
    std::cout << msg.topic << std::endl;
    std::cout << msg.event << std::endl;

    auto from = _clients.find(fd);
    if (from == _clients.end() || !(*from).second.connected)
      {
	std::cout << "FROM client not connected. Not forwarding the message" << std::endl;
	return ;
      }

    IndieProtocol::Serialized serialed = _serializer(msg);

    // broadcast
    if (msg.target == "")
      {
	IndieProtocol::Serialized tmpSerialed;
	for (auto c = _clients.begin(); c != _clients.end(); ++c)
	  {
	    if ((*c).second.connected && (*c).second.fd != fd)
	      {
		std::cout << "Forwarding to " << (*c).second.name << std::endl;
		tmpSerialed = serialed;
		(*c).second.writeBuffer.push_back(tmpSerialed);
	      }
	  }
      }
    else
      {
	auto c = std::find_if(_clients.begin(), _clients.end(),
			      [&msg](std::pair<SOCKET, Client> const &elem)
			      {
				return (elem.second.name == msg.target && elem.second.connected);
			      });
	if (c != _clients.end())
	  {
	    std::cout << "Forwarding to " << (*c).second.name << std::endl;
	    (*c).second.writeBuffer.push_back(serialed);
	  }
      }
  }
};
