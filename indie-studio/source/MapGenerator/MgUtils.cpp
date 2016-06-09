//
// mg_utils.cpp for mg_utils in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
//
// Made by Korial
// Login   <korial@epitech.net>
//
// Started on  Sat May  7 13:02:21 2016 Korial
// Last update Mon May 23 17:57:28 2016 Korial
//

#include "MapGenerator/MgUtils.hpp"

static int	ids = 0;

int	random_range(int min, int max)
{
  return (min + (rand() % (max - min + 1)));
}

void	Leaf::display_node_info() const
{
  std::cout << "Leaf pos : " << _pos.x << "/" << _pos.y << std::endl;
  std::cout << "Leaf _size : " << _size.x << "/" << _size.y << std::endl;
}

bool	Leaf::split(Size roomMin)
{
  bool	splitB;

  if (leftChild != NULL && rightChild != NULL)
    return false;
  if (_size.x > _size.y)
    splitB = false;
  else
    splitB = true;
  int max = (splitB ? _size.y : _size.x) - (splitB ? roomMin.y : roomMin.x);
  if (max < (splitB ? roomMin.y : roomMin.x))
    return false;
  int splitPos = random_range((splitB ? roomMin.y : roomMin.x), max);
  if (splitB)
    {
      leftChild =  new Leaf(Size(_pos.x, _pos.y), Size(_size.x, splitPos));
      rightChild =  new Leaf(Size(_pos.x, _pos.y + splitPos), Size(_size.x, _size.y - splitPos));
    }
  else
    {
      leftChild =  new Leaf(Size(_pos.x, _pos.y), Size(splitPos, _size.y));
      rightChild =  new Leaf(Size(_pos.x + splitPos, _pos.y), Size(_size.x - splitPos, _size.y));
    }
  return true;
}

void	Leaf::create_rooms(std::vector<Rooms>& _rooms, Size maxS)
{
  if (leftChild != NULL || rightChild != NULL)
    {
      if (leftChild != NULL)
	leftChild->create_rooms(_rooms, maxS);
      if (rightChild != NULL)
	rightChild->create_rooms(_rooms, maxS);
    }
  else
    {
      if (_size.x <= maxS.x && _size.y <= maxS.y)
	{
	  ++ids;
	  _rooms.push_back(Rooms(_pos, _size, ids));
	}
    }
}
