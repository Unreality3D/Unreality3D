//
// MenuButton.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 10:51:26 2016 jeremy metereau
// Last update Sat May 28 16:00:40 2016 jeremy metereau
//

#ifndef MENUBUTTON_HPP_
# define MENUBUTTON_HPP_

# include "Gui/AComponent.hpp"

namespace Gui
{

  class MenuButton : public AComponent
  {
  public:
    MenuButton(Context &, const std::string &, const Ogre::Vector2 &pos);
    MenuButton(const MenuButton &);
    MenuButton &operator=(const MenuButton &);
    virtual ~MenuButton(void);

    virtual void	Trigger(void);
  };

};

#endif /* !MENUBUTTON_HPP_ */
