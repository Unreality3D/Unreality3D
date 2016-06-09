//
// IndieParser.cpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 24 13:17:31 2016 Leo Lafon
// Last update Tue May 31 00:47:45 2016 Leo Lafon
//

#include "IndieStudio/IndieParser.hpp"

namespace indie
{
  IndieParser::IndieParser() {}

  IndieParser::~IndieParser() {}

  //
  // PUBLIC
  //

  bool					IndieParser::loadFile(std::string const& path)
  {
    std::string		line;

    _file.open(path.c_str());
    if (!_file.is_open())
      return false;
    _map.erase(_map.begin(), _map.end());
    while (getline(_file, line))
      {
	_insertInMap(line);
      }
    _file.close();
    return true;
  }

  int					IndieParser::stoi(std::string const& str) const
  {
    return atoi(str.c_str());
  }

  float					IndieParser::stof(std::string const& str) const
  {
    return atof(str.c_str());
  }

  long					IndieParser::stol(std::string const& str) const
  {
    return atol(str.c_str());
  }

  bool					IndieParser::stob(std::string const& str) const
  {
    if (str == "1")
      return (true);
    return (false);
  }

  std::vector<std::string>		IndieParser::stoa(std::string const& str, char const delim)
  {
    std::vector<std::string> elems;

    _split(str, delim, elems);
    return elems;
  }

  std::string const&			IndieParser::getValue(std::string const& key) const
  {
    std::map<std::string, std::string>::const_iterator	it;

    it = _map.find(key);
    return it == _map.end() ? _empty : it->second;
  }

  //
  // PRIVATE
  //

  void					IndieParser::_insertInMap(std::string str)
  {
    std::string		key;
    std::string		value;
    size_t		separator_pos;

    separator_pos = str.find(KEY_VAL_SEPARATOR_CHAR);
    if (separator_pos == std::string::npos)
      return;
    key = str.substr(0, separator_pos);
    value = str.substr(separator_pos + 1);
    _map.insert(std::pair<std::string, std::string>(key, value));
  }

  std::vector<std::string>		&IndieParser::_split(std::string const& s,
							     char delim,
							     std::vector<std::string> &elems)
  {
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim))
      {
	elems.push_back(item);
      }
    return elems;
  }
};
