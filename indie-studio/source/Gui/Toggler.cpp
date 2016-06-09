//
// Toggler.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 28 10:51:55 2016 jeremy metereau
// Last update Sun Jun  5 08:52:28 2016 Leo Lafon
//

#include "IndieStudio/GameManager.hpp"
#include "Gui/Toggler.hpp"

namespace Gui
{

  Toggler::Toggler(Context &c, const OIS::KeyCode &k) :
    AComponent(c, "Toggler", Ogre::Vector2(0, 0), Ogre::Vector2(0, 0), true),
    key(k)
  {
    active = true;
  }

  Toggler::Toggler(const Toggler &o) :
    AComponent(o)
  {
  }

  Toggler &Toggler::operator=(const Toggler&o)
  {
    return *this;
  }

  Toggler::~Toggler(void)
  {
  }

  void	Toggler::TriggerKey(void)
  {
    if (indie::GameManager::getInputManager()->getKeyDown(key))
      context.toggleActive(!context.isActive());
  }

};
