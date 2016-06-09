//
// FunctorButton.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 28 16:04:47 2016 jeremy metereau
// Last update Sat May 28 16:22:48 2016 jeremy metereau
//

#ifndef FUNCTORBUTTON_HPP_
# define FUNCTORBUTTON_HPP_

# include "Gui/MenuButton.hpp"

namespace Gui
{

  template <class F>
  class FunctorButton : public MenuButton
  {
    F	callback;

  public:
    FunctorButton(Context &c, const std::string &n, const Ogre::Vector2 &pos) :
      MenuButton(c, n, pos) {}
    FunctorButton(const FunctorButton &o) :
      MenuButton(o) {}
    FunctorButton &operator=(const FunctorButton &o)
    { return *this; }
    virtual ~FunctorButton(void) {}

    virtual void Trigger(void)
    {
      callback(context);
      return ;
    }

  };

};

#endif /* !FUNCTORBUTTON_HPP_ */
