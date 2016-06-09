//
// IndieParser.hpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 24 12:58:35 2016 Leo Lafon
// Last update Tue May 31 00:47:04 2016 Leo Lafon
//

#ifndef INDIEPARSER_HPP_
# define INDIEPARSER_HPP_

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <vector>
# include <map>
# include <cstdlib>

# define KEY_VAL_SEPARATOR_CHAR		":"

namespace indie
{
  class IndieParser
  {
  private:
    std::map<std::string, std::string>	_map;
    std::ifstream			_file;
    std::string				_empty;

  private:
    void				_insertInMap(std::string str);
    std::vector<std::string>		&_split(std::string const& s,
					char delim,
					std::vector<std::string> &elems);

  public:
    IndieParser();
    ~IndieParser();

    bool				loadFile(std::string const& path);
    std::string const&			getValue(std::string const& key) const;
    int					stoi(std::string const& str) const;
    float				stof(std::string const& str) const;
    long				stol(std::string const& str) const;
    bool				stob(std::string const& str) const;
    std::vector<std::string>		stoa(std::string const& str, char const delim);
  };
};

#endif /* !INDIEPARSER_HPP_ */
