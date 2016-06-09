//
// EscMenuContext.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 28 15:52:36 2016 jeremy metereau
// Last update Sat May 28 16:39:35 2016 jeremy metereau
//

#include "Gui/FunctorButton.hpp"
#include "Gui/CallBacks.hpp"
#include "Gui/Toggler.hpp"
#include "Gui/EscMenuContext.hpp"

namespace Gui
{

  EscMenuContext::EscMenuContext(void) :
    Context("EscMenu", false)
  {
    components.push_back(new Toggler(*this, OIS::KC_ESCAPE));
    components.push_back(new FunctorButton<HideMenu>(*this, "CONTINUE",
						    Ogre::Vector2(0.4, 0.4)));
    components.push_back(new FunctorButton<Quit>(*this, "QUIT ",
						 Ogre::Vector2(0.4, 0.5)));
    std::cout << "[GUI] EscMenuContext Loaded." << std::endl;

  }

  EscMenuContext::EscMenuContext(const EscMenuContext &o) :
    Context(0)
  {
  }

  EscMenuContext &EscMenuContext::operator=(const EscMenuContext &o)
  {
    return *this;
  }

  EscMenuContext::~EscMenuContext(void)
  {
  }

};
