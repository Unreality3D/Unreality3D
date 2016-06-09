//
// IndieProtocol.hpp for  in /home/agor_m/epitech/cpp_indie_studio/network/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Fri Jun  3 22:25:33 2016 Maxime Agor
// Last update Sun Jun  5 18:53:34 2016 Maxime Agor
//

#ifndef INDIE_PROTOCOL_HPP_
# define INDIE_PROTOCOL_HPP_

# include <cstdint>
# include <string>
# include <vector>
# include <cstring>
# include <iostream>
# include <iomanip>

namespace IndieProtocol
{
  enum PacketType : uint16_t
    {
      UNKNOWN = 0,
      CONNECT = 1,
      LIST = 2,
      MESSAGE = 3
    };

  struct __attribute__ ((__packed__)) Header
  {
    uint32_t			size;
    PacketType			messageType;

    Header(PacketType type = PacketType::UNKNOWN, uint32_t _size = 0) : messageType(type), size(_size){}
  };

  struct Connect
  {
    std::string			name;

    Connect(std::string _name = "") : name(_name) {}
  };

  struct List
  {
    std::vector	<std::string>	clients;
  };

  struct Message
  {
    std::string			target;
    std::string			topic;
    std::string			event;
    uint32_t			payloadSize;
    void const *		payload;

    Message(std::string _target = "", std::string _topic = "", std::string _event = "")
      : target(_target), topic(_topic), event(_event) {}
  };

  struct Serialized
  {
    uint32_t			size;
    char *			data;

    Serialized (uint32_t _size = 0, void const *_data = NULL) : size(_size)
    {
      data = new char [size ? size : 1];
      if (size)
	memcpy(data, _data, size);
    }

    Serialized (Serialized const &oth)
      : Serialized(0, NULL)
    {
      *this = oth;
    }

    ~Serialized()
    {
      // std::cout << "delete[] Serialized : " << size << " " << (size_t)data << std::endl;
      // void *array[10];
      // size_t asize;
      // asize = backtrace(array, 10);
      // backtrace_symbols_fd(array, asize, 1);

      if (data)
	delete[] data;
    }

    void append(void const *_data, size_t _size)
    {
      memcpy(data + size, _data, _size);
      size += _size;
    }

    Serialized &operator= (Serialized const &oth)
    {
      size = oth.size;
      if (data)
	delete[] data;
      data = new char[size];
      memcpy(data, oth.data, size);
      return *this;
    }

    Serialized operator+ (size_t bytes) const
    {
      return Serialized(size - bytes, data + bytes);
    }

    Serialized operator+ (Serialized const &oth) const
    {
      Serialized result;

      result.size = size + oth.size;
      result.data = new char[result.size];
      memcpy(result.data, data, size);
      memcpy(result.data + size, oth.data, oth.size);
      return result;
    }

    Serialized &operator+= (size_t bytes)
    {
      *this = *this + bytes;
      return *this;
    }

    Serialized &operator+= (Serialized const &oth)
    {
      *this = *this + oth;
      return *this;
    }
  };

inline std::ostream &operator<< (std::ostream &s, IndieProtocol::Serialized const &data)
{
  auto flags = s.flags();

  s << std::endl << "===== SERIALIZED PACKET =====" << std::endl;
  s << "size : " << data.size << " bytes" << std::endl;

  s << "hex:" << std::endl;
  for (int i = 0; i < data.size; ++i)
    {
      s << std::setw(2) << std::setfill('0') << std::hex << (int)(data.data[i]) << " ";

      if (i%16 == 15)
	s << std::endl;
    }
  s << std::endl << "raw : " << std::endl;

  s.flags(flags);
  for (int i = 0; i < data.size; ++i)
    {
      s << data.data[i];
    }
  s << std::endl << "===== END OF PACKET =====" << std::endl;
  return s;
}

};

#endif
