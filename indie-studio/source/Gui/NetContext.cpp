//
// NetContext.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 13:57:09 2016 jeremy metereau
// Last update Sat Jun  4 15:43:25 2016 jeremy metereau
//

#include <iostream>
#include "Gui/FunctorButton.hpp"
#include "Gui/FunctorField.hpp"
#include "Gui/CallBacks.hpp"
#include "Gui/NetContext.hpp"

namespace Gui
{

  NetContext *NetContext::instance = NULL;

  NetContext::NetContext(void) :
    Context("NetContext")
  {
    components.push_back(new FunctorButton<Quit>(*this, "  QUIT",
						 Ogre::Vector2(0.05, 0.9)));
    components.push_back(new FunctorField<NetworkInit>(*this, "network", "Server IP", 16,
						       Ogre::Vector2(0.05, 0.8)));

    if (active)
      overlay->show();
    instance = this;
  }

  NetContext::NetContext(const NetContext &o) :
    Context(o)
  {
  }

  NetContext &NetContext::operator=(const NetContext &o)
  {
    return *this;
  }

  NetContext::~NetContext(void)
  {
  }

};
