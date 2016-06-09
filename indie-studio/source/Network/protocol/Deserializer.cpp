//
// Deserializer.cpp for  in /home/agor_m/epitech/cpp_indie_studio/network/src
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sat Jun  4 01:05:48 2016 Maxime Agor
// Last update Sun Jun  5 18:58:07 2016 Maxime Agor
//

#include "Network/protocol/Deserializer.hpp"

namespace IndieProtocol
{
  size_t	Deserializer::operator() (Serialized const &to_handle)
  {
    Serialized	tmp;

    if (!to_handle.size || !to_handle.data)
      return 0;

    std::cout << "old buffer : " << std::endl;
    std::cout << _buffer << std::endl;

    _buffer += to_handle;

    std::cout << "new buffer : " << std::endl;
    std::cout << _buffer << std::endl;

    if (!_isReading)
      {
	if (to_handle.size >= sizeof(Header))
	  {
	    // get the header data
	    _isReading = true;
	    memcpy(&_header, to_handle.data, sizeof(Header));
	  }
	else
	  return 0;
      }
    tmp = _buffer + sizeof(Header);

    // can read the whole packet
    if (tmp.size + sizeof(Header) >= _header.size)
      {
	size_t to_return = _header.size;
	switch (_header.messageType)
	  {
	  case PacketType::CONNECT:
	    deserializeConnect(tmp);
	    break;
	  case PacketType::LIST:
	    deserializeList(tmp);
	    break;
	  case PacketType::MESSAGE:
	    deserializeMessage(tmp);
	    break;
	  default: // error or not implemented
	    break;
	  }
	reset();
	return to_return;
      }
    return 0;
  }

  void	Deserializer::OnList(std::function <void(List)> const &callback)
  {
    _OnList = callback;
  }

  void	Deserializer::OnConnect(std::function <void(Connect)> const &callback)
  {
    _OnConnect = callback;
  }

  void	Deserializer::OnMessage(std::function <void(Message)> const &callback)
  {
    _OnMessage = callback;
  }

  void	Deserializer::deserializeList(Serialized const &to_handle)
  {
    List	list;
    uint16_t	listSize;
    uint32_t	pos = 0;
    std::string tmp;

    if (!_OnList)
      return ;

    memcpy(&listSize, to_handle.data, sizeof(listSize));
    pos += sizeof(listSize);

    for (uint16_t i = 0; i < listSize; ++i)
      {
	if (!deserializeString(to_handle, pos, tmp))
	    return ;
	list.clients.push_back(tmp);
      }
    _OnList(list);
  }

  void	Deserializer::deserializeConnect(Serialized const &to_handle)
  {
    Connect	conn;
    uint32_t	pos = 0;

    if (!_OnConnect)
      return ;

    if (!deserializeString(to_handle, pos, conn.name))
      return ;

    _OnConnect(conn);
  }

  void	Deserializer::deserializeMessage(Serialized const &to_handle)
  {
    Message	msg;
    uint32_t	pos = 0;
    void	*payload;

    if (!_OnMessage)
      return ;

    if (!deserializeString(to_handle, pos, msg.target))
      return ;
    if (!deserializeString(to_handle, pos, msg.topic))
      return ;
    if (!deserializeString(to_handle, pos, msg.event))
      return ;

    memcpy(&msg.payloadSize, to_handle.data + pos, sizeof(msg.payloadSize));
    pos += sizeof(msg.payloadSize);
    // error
    if (pos + msg.payloadSize + sizeof(Header) > _header.size)
      return ;
    payload = new char[msg.payloadSize];
    memcpy(payload, to_handle.data + pos, msg.payloadSize);

    msg.payload = payload;
    _OnMessage(msg);
  }

  void	Deserializer::reset()
  {
    _buffer += _header.size;
    _header = Header();
    _isReading = false;
  }

  bool	Deserializer::deserializeString
  (Serialized const &to_handle, uint32_t &pos, std::string &to_change)
  {
    uint16_t	size;

    memcpy(&size, to_handle.data + pos, sizeof(size));
    pos += sizeof(size);
    // error
    if (pos + size + sizeof(Header) > _header.size)
      return false;

    char buffer[size + 1];
    memcpy(buffer, to_handle.data + pos, size);
    buffer[size] = '\0';
    pos += size;
    to_change = std::string(buffer);
    return true;
  }

};
