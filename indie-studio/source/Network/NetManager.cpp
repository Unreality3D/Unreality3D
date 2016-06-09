//
// NetManager.cpp for  in /home/agor_m/epitech/cpp_indie_studio/network/src
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sun Jun  5 03:34:56 2016 Maxime Agor
// Last update Sun Jun  5 18:57:59 2016 Maxime Agor
//

#include <algorithm>
#include "Network/NetManager.hpp"

namespace network
{
  void	NetClient::subscribe(NetManager &manager, std::string const & topic) const
  {
    manager.subscribe(this, topic);
  }

  void	NetClient::unsubscribe(NetManager &manager, std::string const & topic) const
  {
    manager.unsubscribe(this, topic);
  }

  void	NetClient::publish(NetManager &manager,
			   std::string const & target,
			   std::string const & topic, std::string const & event,
			   void const *payload, size_t size)
  {
    manager.publish(target, topic, event, payload, size);
  }

  void	NetClient::publish(NetManager &manager,
			   std::string const & topic, std::string const & event,
			   void const *payload, size_t size)
  {
    manager.publish(topic, event, payload, size);
  }


  void	NetClient::on(std::string const & topic, std::string const & event,
		      NetEventListener const &callback)
  {
    if (topic == "")
      {
	on(event, callback);
	return ;
      }

    auto topicListener = _topicListeners.find(topic);

    // new topic
    if (topicListener == _topicListeners.end())
      {
	_topicListeners[topic] = std::map<std::string, NetEventListener>();
	topicListener = _topicListeners.find(topic);
      }

    (*topicListener).second[event] = callback;
  }

  void	NetClient::on(std::string const & event, NetEventListener const &callback)
  {
    _globalListeners[event] = callback;
  }

  void	NetClient::removeListener(std::string const & topic, std::string const & event)
  {
    if (topic == "")
      {
	removeListener(event);
	return ;
      }

    auto topicListener = _topicListeners.find(topic);
    if (topicListener != _topicListeners.end())
      {
	auto eventListener = (*topicListener).second.find(event);
	if (eventListener != (*topicListener).second.end())
	  {
	    (*topicListener).second.erase(eventListener);
	  }
      }
  }

  void	NetClient::removeListener(std::string const & event)
  {
    auto eventListener = _globalListeners.find(event);
    if (eventListener != _globalListeners.end())
      {
	_globalListeners.erase(eventListener);
      }
  }

  void	NetClient::message(std::string const &topic,
			   std::string const &event,
			   void const *payload, size_t size) const
  {
    auto topicListener = _topicListeners.find(topic);

    if (topicListener != _topicListeners.end())
      {
	auto eventListener = (*topicListener).second.find(event);
	if (eventListener != (*topicListener).second.end())
	  {
	    (*eventListener).second(topic, event, payload, size);
	  }
      }
    else
      {
	auto eventListener = _globalListeners.find(event);
	if (eventListener != _globalListeners.end())
	  {
	    (*eventListener).second(topic, event, payload, size);
	  }
      }
  }

  // NetManager

  void	NetManager::start(std::string const &name, std::string const &address, int port)
  {
    _tcp.OnDisconnect(
		      [this](Socket::Client &c)
		      {
			this->onDisconnect(c);
		      });
    _tcp.OnReadPossible(
			[this](Socket::Client &c, size_t size)
			{
			  this->onReadPossible(c, size);
			});
    _tcp.OnWritePossible(
			 [this](Socket::Client &c)
			 {
			   this->onWritePossible(c);
			 });

    _deserializer.OnConnect(
			    [this](IndieProtocol::Connect c)
			    {
			      this->onPacketConnect(c);
			    });
    _deserializer.OnList(
			 [this](IndieProtocol::List l)
			 {
			   this->onPacketList(l);
			 });
    _deserializer.OnMessage(
			    [this](IndieProtocol::Message m)
			    {
			      this->onPacketMessage(m);
			    });

    _writeBuffer.push_back(_serializer(IndieProtocol::Connect(name)));

    _tcp.start(address, port);
  }

  void	NetManager::stop()
  {
    _tcp.stop();
  }

  void	NetManager::subscribe(NetClient const *client, std::string const &topic)
  {
    // global
    if (topic == "")
      {
	auto c = std::find(_fullClients.begin(), _fullClients.end(), client);
	if (c == _fullClients.end())
	  _fullClients.push_back(client);
      }
    // topic
    else
      {
	auto topicSubs = _netClients.find(topic);
	// new topic
	if (topicSubs == _netClients.end())
	  {
	    _netClients[topic] = std::vector<NetClient const *>();
	    topicSubs = _netClients.find(topic);
	  }
	auto c = std::find((*topicSubs).second.begin(),
			   (*topicSubs).second.end(),
			   client);
	if (c == (*topicSubs).second.end())
	  (*topicSubs).second.push_back(client);
      }
  }

  void	NetManager::unsubscribe(NetClient const *client, std::string const &topic)
  {
    // global
    if (topic == "")
      {
	auto c = std::find(_fullClients.begin(), _fullClients.end(), client);
	if (c != _fullClients.end())
	  _fullClients.erase(c);
      }
    // topic
    else
      {
	auto topicSubs = _netClients.find(topic);
	// new topic
	if (topicSubs != _netClients.end())
	  {
	    auto c = std::find((*topicSubs).second.begin(),
			       (*topicSubs).second.end(),
			       client);
	    if (c != (*topicSubs).second.end())
	      (*topicSubs).second.erase(c);

	    if ((*topicSubs).second.size() == 0)
	      _netClients.erase(topicSubs);
	  }
      }
  }

  void	NetManager::publish(std::string const &target,
			    std::string const &topic,
			    std::string const &event,
			    void const *payload, size_t size)
  {
    IndieProtocol::Message	m;

    m.target = target;
    m.topic = topic;
    m.event = event;

    m.payloadSize = size;
    m.payload = payload;

    _writeBuffer.push_back(_serializer(m));
  }

  void	NetManager::publish(std::string const &topic,
			    std::string const &event,
			    void const *payload, size_t size)
  {
    publish("", topic, event, payload, size);
  }

  // TCP callbacks

  void  NetManager::onDisconnect(Socket::Client &c)
  {
    std::cout << "connexion interrupted" << std::endl;
  }

  void  NetManager::onReadPossible(Socket::Client &c, size_t size)
  {
    char *tmp;

    tmp = new char[size];
    c.read(tmp, size);
    _deserializer(IndieProtocol::Serialized(size, tmp));
    delete[] tmp;
  }

  void  NetManager::onWritePossible(Socket::Client &c)
  {
    if (!_writeBuffer.size())
      return;

    IndieProtocol::Serialized tmp;

    while (_writeBuffer.size())
      {
	tmp = _writeBuffer.back();
	_writeBuffer.pop_back();
	c.write(tmp.data, tmp.size);
      }
  }

  // Deserializer callbacks
  void  NetManager::onPacketConnect(IndieProtocol::Connect conn)
  {
    std::cout << "CONNECT" << std::endl;
    std::cout << conn.name << std::endl;
  }

  void  NetManager::onPacketList(IndieProtocol::List list)
  {
    std::cout << "LIST" << std::endl;
    for (auto it = list.clients.begin(); it != list.clients.end(); ++it)
      {
	std::cout << *it << std::endl;
      }
  }

  void  NetManager::onPacketMessage(IndieProtocol::Message msg)
  {
    std::cout << "MESSAGE" << std::endl;
    std::cout << msg.target << std::endl;
    std::cout << msg.topic << std::endl;
    std::cout << msg.event << std::endl;

    if (msg.topic != "")
      {
	auto topicSubs = _netClients.find(msg.topic);
	if (topicSubs != _netClients.end())
	  {
	    for (auto it = (*topicSubs).second.begin();
		 it != (*topicSubs).second.end(); ++it)
	      {
		if (*it)
		  (*it)->message(msg.topic, msg.event, msg.payload, msg.payloadSize);
	      }

	  }
	// warning : if subscribed to the topic and to the global, event will fire twice
	for (auto client = _fullClients.begin(); client != _fullClients.end(); ++client)
	  {
	    if (*client)
	      (*client)->message(msg.topic, msg.event, msg.payload, msg.payloadSize);
	  }
      }
  }

};
