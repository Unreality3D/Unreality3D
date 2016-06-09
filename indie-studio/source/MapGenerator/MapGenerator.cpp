//
// map_generator.cpp for map_generator in /home/korial/rendu/Tek2/cpp_indie_studio/map_generator
//
// Made by Korial
// Login   <korial@epitech.net>
//
// Started on  Wed May  4 12:40:18 2016 Korial
// Last update Wed Jun  1 16:47:30 2016 Maxime Agor
//

#include "MapGenerator/MapGenerator.hpp"

int	Map::get_room_nbr() const
{
  return this->room_nbr;
}

int	Map::get_room_max_x() const
{
  return this->room_max_size.x;
}

int	Map::get_room_max_y() const
{
  return this->room_max_size.y;
}

Size	Map::get_map_size() const
{
  return this->map_size;
}

void				Map::set_seed(std::string seed)
{
  int		nbr = 0;

  for(size_t i = 0; i < seed.length();i++)
    nbr += static_cast<int>(seed[i]);
  _seed = nbr;
}

std::vector<std::string> const&		Map::get_map() const
{
  return _map;
}

int const				Map::get_startX() const
{
  return startX;
}

int const				Map::get_startY() const
{
  return startY;
}

void				Map::generate_map()
{
  std::ofstream			debug;
  Leaf				_root = Leaf(Size(0, 0), Size(map_size.x, map_size.y));
  std::vector<Rooms>		tmpRooms;

  if (_seed != -1)
    srand(_seed);
  else
    srand(time(NULL));
  debug.open("map.txt");
  _leafs.push_back(_root);
  split();
  for(size_t i = 0; i < _leafs.size();i++)
    _leafs[i].create_rooms(tmpRooms, room_max_size);
  for (int i = 0; i < room_nbr;i++)
    _rooms.push_back(tmpRooms[rand() % tmpRooms.size()]);
  for(size_t i = 0; i < _leafs.size();i++)
    {
      delete(_leafs[i].leftChild);
      delete(_leafs[i].rightChild);
    }
  blank_map();
  draw_rooms();
  draw_better_walls();
  draw_hallways();
  draw_hallways_walls();
  draw_angles();
  add_misc();
  draw_rooms_pattern();
  draw_in_out();
  for (size_t i = 0; i < _map.size() ; i++)
    debug << _map[i] << std::endl;
  debug.close();
}

void	Map::split()
{
  bool				split = true;

  while (split)
    {
      split = false;
      for(size_t i = 0; i < _leafs.size();i++)
	{
	  if ((_leafs[i].leftChild == NULL && _leafs[i].rightChild == NULL)
	      && (_leafs[i]._size.x > room_max_size.x || _leafs[i]._size.y > room_max_size.y)
	      && (_leafs[i].split(room_min_size)))
	    {
	      _leafs.push_back(*_leafs[i].leftChild);
	      _leafs.push_back(*_leafs[i].rightChild);
	      split = true;
	    }
	}
    }
}

void	Map::blank_map()
{
  std::string	tmp;
  for (int x = 0; x < map_size.x + 4; x++)
    tmp += ".";
  for (int i = 0; i < map_size.y + 4; i++)
    _map.push_back(tmp);
}

void	Map::draw_rooms()
{
  int	x = 0;
  int	y = 0;

  for (size_t i = 0;i < _rooms.size();i++)
    {
      x = _rooms[i]._size.x + _rooms[i]._pos.x + 2;
      y = _rooms[i]._size.y + _rooms[i]._pos.y + 2;
      for (int p = _rooms[i]._pos.y + 1; p <= y;p++)
	{
	  for (int o = _rooms[i]._pos.x + 1; o <= x;o++)
	    {
	      if (o == x || o == _rooms[i]._pos.x + 1)
		_map[p][o] = '#';
	      else if  (p == y || p == _rooms[i]._pos.y + 1)
	      	_map[p][o] = '#';
	      else
		_map[p][o] = ' ';
	    }
	}
    }
}

void	Map::draw_hallways()
{
  Size	r1;
  Size	r2;
  int	w = 0;
  int	h = 0;

  for (size_t i = 0;i < _rooms.size() - 1;i++)
    {
      r1.y = (_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2;
      r1.x = (_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2;
      r2.y = (_rooms[i + 1]._size.y / 2) + _rooms[i + 1]._pos.y + 2;
      r2.x = (_rooms[i + 1]._size.x / 2) + _rooms[i + 1]._pos.x + 2;

      w = r2.x - r1.x;
      h = r2.y - r1.y;
      if (w > 0 && h > 0)
	{
	  for (int x = 0; x < w; x++)
	    _map[r1.y][r1.x + x] = ' ';
	  for (int y = h; y > 0; y--)
	    _map[r2.y - y][r2.x] = ' ';
	}
      else if (w > 0 && h < 0)
	{
	  for (int x = 0; x < w; x++)
	    _map[r1.y][r1.x + x] = ' ';
	  for (int y = (h * -1); y > 0; y--)
	    _map[r2.y + y][r2.x] = ' ';
	}
      else if (w < 0 && h > 0)
	{
	  for (int x = 0; x < (w * -1); x++)
	    _map[r1.y][r1.x - x] = ' ';
	  for (int y = h; y > 0; y--)
	    _map[r2.y - y][r2.x] = ' ';
	}
      else
	{
	  for (int x = 0; x < (w * -1); x++)
	    _map[r1.y][r1.x - x] = ' ';
	  for (int y = (h * -1); y > 0; y--)
	    _map[r2.y + y][r2.x] = ' ';
	}
    }
}

void		Map::draw_in_out()
{
  _map[(_rooms[0]._size.y / 2) + _rooms[0]._pos.y + 2][(_rooms[0]._size.x / 2) + _rooms[0]._pos.x + 2] = 'E';
  startX = (_rooms[0]._size.y / 2) + _rooms[0]._pos.y + 2;
  startY = (_rooms[0]._size.x / 2) + _rooms[0]._pos.x + 2;
  _map[(_rooms[_rooms.size() - 1]._size.y / 2) + _rooms[_rooms.size() - 1]._pos.y + 2][(_rooms[_rooms.size() - 1]._size.x / 2) + _rooms[_rooms.size() - 1]._pos.x + 2] = 'S';
}

void		Map::draw_rooms_pattern()
{
  for(int i = 0; i < _rooms.size();i++)
    {
      if (_rooms[i]._size.y > _rooms[i]._size.x && _rooms[i]._size.y >= 12 && _rooms[i]._size.x >= 6)
	rand() % 100 > 50 ? _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'H' : _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'T';
      else if (_rooms[i]._size.y > _rooms[i]._size.x && _rooms[i]._size.y >= 6 && _rooms[i]._size.x >= 5)
	rand() % 100 > 50 ? _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'h' : _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 't';
      else if (_rooms[i]._size.y < _rooms[i]._size.x && _rooms[i]._size.x >= 12 && _rooms[i]._size.x >= 6)
	(rand() % 100) > 50 ? _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'B' : _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'G';
     else if (_rooms[i]._size.y < _rooms[i]._size.x && _rooms[i]._size.x >= 6 && _rooms[i]._size.x >= 5)
       (rand() % 100) > 50 ? _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'b' : _map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'g';
     else if (_rooms[i]._size.y == _rooms[i]._size.x
	      && (_rooms[i]._size.x >= 5 && _rooms[i]._size.y >= 5)
	      && (_rooms[i]._size.x <= 7 && _rooms[i]._size.y <= 7))
	_map[(_rooms[i]._size.y / 2) + _rooms[i]._pos.y + 2][(_rooms[i]._size.x / 2) + _rooms[i]._pos.x + 2] = 'C';
    }
}

void		Map::draw_hallways_walls()
{
  for (size_t i = 1;i < _map.size() - 1;i++)
    {
      for (size_t x = 1;x < _map[i].length()- 1;x++)
	{
	  if ((_map[i][x] == '.' && _map[i][x + 1] == ' ')
	      || (_map[i][x] == '.' && _map[i][x - 1] == ' '))
	    _map[i][x] = '|';
	  else if ((_map[i][x] == '.' && _map[i-1][x] == ' ')
	      || (_map[i][x] == '.' && _map[i+1][x] == ' '))
	    _map[i][x] = '-';
	}
    }
}

void		Map::draw_better_walls()
{
  for (size_t i = 1;i < _map.size() - 1;i++)
    {
      for (size_t x = 1;x < _map[i].length()- 1;x++)
	{
	  if (_map[i][x] == '#' && _map[i][x + 1] == '#' && _map[i + 1][x] == '#')
	    _map[i][x] = 'X';
	  else if (_map[i][x] == '#' && _map[i][x - 1] == '-' && _map[i + 1][x] == '#')
	    _map[i][x] = 'X';
	  else if ((_map[i][x] == '#' && _map[i][x - 1] == '-' && _map[i - 1][x] == '|')
		   || (_map[i][x] == '#' && _map[i][x - 1] == 'X' && _map[i - 1][x] == '|')
		   || (_map[i][x] == '#' && _map[i][x - 1] == '-' && _map[i - 1][x] == 'X'))
	    _map[i][x] = 'X';
	  else if (_map[i][x] == '#' && _map[i - 1][x] == '|' && _map[i][x + 1] == '#')
	    _map[i][x] = 'X';
	  else if (_map[i][x] == '#' && _map[i][x + 1] == '#')
	    _map[i][x] = '-';
	  else if (_map[i][x] == '#' && _map[i + 1][x] == '#')
	    _map[i][x] = '|';
	}
    }
}

void		Map::draw_angles()
{
  for (size_t i = 1;i < _map.size() - 1;i++)
    {
      for (size_t x = 1;x < _map[i].length()- 1;x++)
	{
	  if (_map[i][x] == '|' && _map[i][x + 1] == 'O')
	    _map[i][x] = 'X';
	  else if (_map[i][x] == '|' && _map[i][x - 1] == 'O')
	    _map[i][x] = 'X';
	  else if (_map[i][x] == '-' && _map[i + 1][x] == 'O')
	    _map[i][x] = 'X';
	  else if (_map[i][x] == '-' && _map[i - 1][x] == 'O')
	    _map[i][x] = 'X';
	}
    }
  for (size_t i = 1;i < _map.size() - 1;i++)
    {
      for (size_t x = 1;x < _map[i].length()- 1;x++)
  	{
  	  if (_map[i][x] == '|' && _map[i + 1][x] == ' ')
  	    _map[i][x] = 'X';
  	  else if (_map[i][x] == '|' && _map[i - 1][x] == ' ')
  	    _map[i][x] = 'X';
  	  else if (_map[i][x] == '-' && _map[i][x + 1] == ' ')
  	    _map[i][x] = 'X';
  	  else if (_map[i][x] == '-' && _map[i][x - 1] == ' ')
  	    _map[i][x] = 'X';
  	}
    }
  for (size_t i = 1;i < _map.size() - 1;i++)
    {
      for (size_t x = 1;x < _map[i].length()- 1;x++)
  	{
  	  if (_map[i][x] == '.' && _map[i + 1][x] == '|')
  	    _map[i][x] = 'X';
  	  else if (_map[i][x] == '.' && _map[i - 1][x] == '|')
  	    _map[i][x] = 'X';
  	  else if (_map[i][x] == '.' && _map[i][x + 1] == '-')
  	    _map[i][x] = 'X';
  	  else if (_map[i][x] == '.' && _map[i][x - 1] == '-')
  	    _map[i][x] = 'X';
  	}
    }
}

void			Map::add_misc()
{
  for (size_t i = 1;i < _map.size() - 1;i++)
    {
      for (size_t x = 1;x < _map[i].length()- 1;x++)
  	{
	  if ((_map[i][x] == ' ' && _map[i][x - 1] == '|' && _map[i][x + 1] == ' ')
	      || (_map[i][x] == ' ' && _map[i][x + 1] == '|' && _map[i][x - 1] == ' ')
	      || (_map[i][x] == ' ' && _map[i + 1][x] == '-' && _map[i - 1][x] == ' ')
	      || (_map[i][x] == ' ' && _map[i - 1][x] == '-' && _map[i + 1][x] == ' '))
	    _map[i][x] = 'M';
	}
    }
}
