//
// mg_utils.hpp for mg_utils in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Sat May  7 12:34:34 2016 Korial
// Last update Mon May  9 13:14:36 2016 Korial
//

#ifndef MG_UTILS_HPP_
# define MG_UTILS_HPP_

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

struct        Size
{
  Size(int X = 0, int Y = 0) : x(X), y(Y) { }
  int         x;
  int         y;
};

class Rooms
{
public:
  Size        _pos;
  Size        _size;
  int         _id;
public:
  Rooms(Size pos, Size size, int id) : _pos(pos), _size(size), _id(id) { }
  ~Rooms() { }
};

class Hallways
{
public:
  Size        _pos;
  int         _height;
  int         _width;
  
public:
  Hallways(Size pos, int height, int width) : _pos(pos), _height(height), _width(width) { \
  }
  ~Hallways() { }
};

class Leaf
{
public:
  Size	_pos;
  Size	_size;
  Leaf	*leftChild;
  Leaf	*rightChild;
  
public:
  Leaf(Size pos, Size size) : _pos(pos), _size(size), leftChild(NULL), rightChild(NULL) { }
  ~Leaf() { }

public:
  bool	split(Size roomMin);
  void	create_rooms(std::vector<Rooms>&, Size);
  void	display_node_info() const;
};

#endif /*!MG_UTILS_HPP_*/
