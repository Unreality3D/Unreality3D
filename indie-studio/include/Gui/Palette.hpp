//
// Palette.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Tue May 24 17:28:33 2016 jeremy metereau
// Last update Wed May 25 10:20:20 2016 jeremy metereau
//

#ifndef PALETTE_HPP_
# define PALETTE_HPP_

# include <string>

namespace Gui
{

  class Palette
  {
  public:
    Palette(void);
    Palette(const Palette &);
    Palette &operator=(const Palette &);
    ~Palette(void);

    void add(const std::string &, float r, float g, float b);
    void add(const std::string &, int hex);
  };

};

#endif /* !PALETTe_HPP_ */
