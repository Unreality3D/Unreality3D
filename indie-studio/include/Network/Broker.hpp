//
// Broker.hpp for  in /home/agor_m/epitech/cpp_indie_studio/network/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sat Jun  4 14:38:21 2016 Maxime Agor
// Last update Sun Jun  5 18:52:29 2016 Maxime Agor
//

#ifndef BROKER_HPP_
# define BROKER_HPP_

#include <map>

# include "Network/sockets/Server.hpp"

# include "Network/protocol/Serializer.hpp"
# include "Network/protocol/Deserializer.hpp"

namespace network
{
  struct Client
  {
    bool					connected;
    SOCKET					fd;
    std::string					name;
    IndieProtocol::Deserializer			deserializer;
    IndieProtocol::Serialized			readBuffer;
    std::vector<IndieProtocol::Serialized>	writeBuffer;

    void					deserialize(void *buff, size_t size);
    Client() {}
    Client(SOCKET _fd) : fd(_fd) {}
  };

  class Broker
  {
  public:
    void				start(int port, size_t maxClients = 10);
    void				stop();

    void				onConnect(Socket::Server &, int fd);
    void				onDisconnect(Socket::Server &, int fd);
    void				onReadPossible(Socket::Server &, int fd, size_t size);
    void				onWritePossible(Socket::Server &, int fd);

    void				onPacketConnect(int fd, IndieProtocol::Connect);
    void				onPacketList(int fd, IndieProtocol::List);
    void				onPacketMessage(int fd, IndieProtocol::Message);
  private:

  private:
    IndieProtocol::Serializer		_serializer;
    Socket::Server			_server;

    std::map<SOCKET, Client>		_clients;
  };
};

#endif
