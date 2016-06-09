//
// Serializer.cpp for  in /home/agor_m/epitech/cpp_indie_studio/network/src
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Fri Jun  3 23:25:58 2016 Maxime Agor
// Last update Sun Jun  5 18:58:14 2016 Maxime Agor
//

#include "Network/protocol/Serializer.hpp"

// utils

static inline uint32_t    getStringSize(std::string const &s)
{
  return sizeof(uint16_t) + s.size();
}

namespace IndieProtocol
{

  Serialized	Serializer::operator() (Connect const &packet)
  {
    uint32_t	size = sizeof(Header) + getStringSize(packet.name);
    Serialized	buff;

    buff.data = new char[size];
    serializeHeader(buff, Header(PacketType::CONNECT, size));
    serializeString(buff, packet.name);

    return buff;
  }

  Serialized	Serializer::operator() (List const &packet)
  {
    uint32_t	size = sizeof(Header) + sizeof(uint16_t);
    uint16_t	listSize = packet.clients.size();
    Serialized	buff;

    for (auto it = packet.clients.begin(); it != packet.clients.end(); ++it)
      size += getStringSize(*it);

    buff.data = new char[size];
    serializeHeader(buff, Header(PacketType::LIST, size));
    buff.append(&listSize, sizeof(listSize));
    for (auto it = packet.clients.begin(); it != packet.clients.end(); ++it)
      serializeString(buff, *it);

    return buff;
  }

  Serialized	Serializer::operator() (Message const &packet)
  {
    uint16_t	size =
      sizeof(Header) +
      getStringSize(packet.target) +
      getStringSize(packet.topic) +
      getStringSize(packet.event) +
      sizeof (packet.payloadSize) +
      packet.payloadSize;

    Serialized	buff;
    buff.data = new char[size];

    serializeHeader(buff, Header(PacketType::MESSAGE, size));
    serializeString(buff, packet.target);
    serializeString(buff, packet.topic);
    serializeString(buff, packet.event);
    buff.append(&packet.payloadSize, sizeof(packet.payloadSize));
    buff.append(packet.payload, packet.payloadSize);

    return buff;
  }

  // private

  void		Serializer::serializeString(Serialized &_buffer, std::string const &str)
  {
    uint16_t size = str.size();

    _buffer.append(&size, sizeof(size));
    _buffer.append(str.c_str(), str.size());
  }

  void		Serializer::serializeHeader(Serialized &_buffer, Header h)
  {
    _buffer.append(&h, sizeof(h));
  }

};
