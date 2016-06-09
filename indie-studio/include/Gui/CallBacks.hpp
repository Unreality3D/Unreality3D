//
// CallBacks.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 28 16:10:55 2016 jeremy metereau
// Last update Sat Jun  4 15:32:59 2016 jeremy metereau
//

#ifndef CALLBACKS_HPP_
# define CALLBACKS_HPP_

# include "Gui/Context.hpp"

namespace Gui
{

  class HideMenu
  {
  public:
    void operator()(Context &);
  };

  class Quit
  {
  public:
    void operator()(Context &);
  };

  class NetworkInit
  {
  public:
    void operator()(Context &, const std::string &);
  };

  class SelectClass
  {
  public:
    void operator()(Context &);
  };

  class SelectMage
  {
  public:
    void operator()(Context &);
  };

  class SelectWarrior
  {
  public:
    void operator()(Context &);
  };

  class SelectArcher
  {
  public:
    void operator()(Context &);
  };

  class SelectPriest
  {
  public:
    void operator()(Context &);
  };

};

#endif /* !CALLBACKS_HPP_ */
