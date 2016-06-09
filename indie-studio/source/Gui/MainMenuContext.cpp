//
// MainMenuContext.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 10:39:45 2016 jeremy metereau
// Last update Sun Jun  5 18:52:35 2016 jeremy metereau
//

#include <iostream>
#include "Gui/FunctorField.hpp"
#include "Gui/MainMenuContext.hpp"
#include "Gui/FunctorButton.hpp"
#include "Gui/CallBacks.hpp"
#include "Gui/LifeBar.hpp"
#include "Gui/Helper.hpp"
#include "Gui/SampleText.hpp"

namespace Gui
{

  MainMenuContext::MainMenuContext(void) :
    Context("MainMenu", true)
  {
    components.push_back(new FunctorButton<Quit>(*this, " QUIT",
					Ogre::Vector2(0.05, 0.9)));
    components.push_back(new FunctorButton<SelectClass>(*this, " START",
							Ogre::Vector2(0.05, 0.85)));
    components.push_back(new LifeBar(*this));
    if (active)
      overlay->show();
  }

  MainMenuContext::MainMenuContext(const MainMenuContext &o) :
    Context(o)
  {
  }

  MainMenuContext &MainMenuContext::operator=(const MainMenuContext &o)
  {
    return *this;
  }

  MainMenuContext::~MainMenuContext(void)
  {
  }

};
