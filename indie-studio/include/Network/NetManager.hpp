//
// NetManager.hpp for  in /home/agor_m/epitech/cpp_indie_studio/network/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sat Jun  4 15:36:16 2016 Maxime Agor
// Last update Sun Jun  5 18:52:56 2016 Maxime Agor
//

#ifndef NET_MANAGER_HPP_
# define NET_MANAGER_HPP_

# include <map>
# include <vector>
# include <functional>

# include "Network/sockets/Client.hpp"

# include "Network/protocol/Serializer.hpp"
# include "Network/protocol/Deserializer.hpp"

namespace network
{
  typedef std::function<void (std::string const &,
			      std::string const &,
			      void const *, size_t)> NetEventListener;

  class NetManager;

  class NetClient
  {
  public:
    void	subscribe(NetManager &manager, std::string const & topic = "") const;
    void	unsubscribe(NetManager &manager, std::string const & topic = "") const;

    // add a topic event listener
    void	on(std::string const & topic, std::string const & event, NetEventListener const &callback);
    // add a "global" event listener
    void	on(std::string const & event, NetEventListener const &callback);

    // remove a topic event listener
    void	removeListener(std::string const & topic, std::string const & event);
    // remove a "global" event listener
    void	removeListener(std::string const & event);

    void	message(std::string const &topic,
			std::string const &event,
			void const *payload, size_t size) const;

    void	publish(NetManager &manager,
			std::string const & target,
			std::string const & topic,
			std::string const & event,
			void const *payload, size_t size);
    void	publish(NetManager &manager,
			std::string const & topic,
			std::string const & event,
			void const *payload, size_t size);


  private:
    // [MAP : topic => [MAP : event => listener ] ]
    std::map<std::string, std::map<std::string, NetEventListener> > _topicListeners;
    // [MAP : event => listener]
    std::map<std::string, NetEventListener> _globalListeners;
  };

  class NetManager
  {
  public:

    void	start(std::string const &name, std::string const &address, int port);
    void	stop();

    void	subscribe(NetClient const *client, std::string const &topic = "");
    void	unsubscribe(NetClient const *client, std::string const &topic = "");

    // publish to a specific client
    void	publish(std::string const &target,
			std::string const &topic,
			std::string const &event,
			void const *payload, size_t size);

    // publish to every clients connected to the broker
    void	publish(std::string const &topic,
			std::string const &event,
			void const *payload, size_t size);

  public:
    void        onConnect(Socket::Client &);
    void        onDisconnect(Socket::Client &);
    void        onReadPossible(Socket::Client &, size_t size);
    void        onWritePossible(Socket::Client &);

    void        onPacketConnect(IndieProtocol::Connect);
    void        onPacketList(IndieProtocol::List);
    void        onPacketMessage(IndieProtocol::Message);

  private:
    Socket::Client		_tcp;
    IndieProtocol::Serializer	_serializer;
    IndieProtocol::Deserializer	_deserializer;

    // topic => client
    std::map<std::string, std::vector<NetClient const *> >	_netClients;
    // non-topic specific clients
    std::vector<NetClient const *>				_fullClients;

    std::vector<IndieProtocol::Serialized>		_writeBuffer;
  };
};


#endif
