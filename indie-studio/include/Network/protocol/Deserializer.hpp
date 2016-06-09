//
// Deserializer.hpp for  in /home/agor_m/epitech/cpp_indie_studio/network/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Fri Jun  3 22:48:26 2016 Maxime Agor
// Last update Sun Jun  5 18:53:07 2016 Maxime Agor
//

#ifndef DESERIALIZER_HPP_
# define DESERIALIZER_HPP_

#include <functional>
#include "Network/protocol/IndieProtocol.hpp"

namespace IndieProtocol
{
  class Deserializer
  {
  public:
    Deserializer() : _isReading(false), _buffer() {}

    size_t	operator() (Serialized const &);

    void	OnList(std::function <void(List)> const &callback);
    void	OnConnect(std::function <void(Connect)> const &callback);
    void	OnMessage(std::function <void(Message)> const &callback);

  private:
    void	deserializeList(Serialized const &);
    void	deserializeConnect(Serialized const &);
    void	deserializeMessage(Serialized const &);

    void	reset();

    bool	deserializeString(Serialized const &, uint32_t &pos, std::string &to_change);

  private:
    Header				_header;
    Serialized				_buffer;
    bool				_isReading;

    std::function <void(List)>		_OnList;
    std::function <void(Connect)>	_OnConnect;
    std::function <void(Message)>	_OnMessage;

  };
};

#endif
