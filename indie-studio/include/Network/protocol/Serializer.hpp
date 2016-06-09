//
// Serializer.hpp for  in /home/agor_m/epitech/cpp_indie_studio/network/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Fri Jun  3 22:48:26 2016 Maxime Agor
// Last update Sun Jun  5 18:53:54 2016 Maxime Agor
//

#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_

#include "Network/protocol/IndieProtocol.hpp"

namespace IndieProtocol
{
  class Serializer
  {
  public:
    Serialized	operator() (Connect const &packet);
    Serialized	operator() (List const &packet);
    Serialized	operator() (Message const &packet);

  private:
    void	serializeString(Serialized &_buff, std::string const &str);
    void	serializeHeader(Serialized &_buff, Header h);

  private:
  };
};

#endif
