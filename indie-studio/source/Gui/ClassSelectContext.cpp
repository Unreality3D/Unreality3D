//
// ClassSelectContext.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 14:10:41 2016 jeremy metereau
// Last update Sat Jun  4 15:40:18 2016 jeremy metereau
//

#include "Gui/FunctorButton.hpp"
#include "Gui/CallBacks.hpp"
#include "Gui/ClassSelectContext.hpp"

namespace Gui
{

  ClassSelectContext *ClassSelectContext::instance = NULL;

  ClassSelectContext::ClassSelectContext(void) :
    Context("ClassSelectContext")
  {
    components.push_back(new FunctorButton<Quit>(*this, " QUIT",
						 Ogre::Vector2(0.05, 0.9)));
    components.push_back(new FunctorButton<SelectMage>(*this, "MAGE",
						 Ogre::Vector2(0.05, 0.8)));
    components.push_back(new FunctorButton<SelectWarrior>(*this, "WARRIOR",
						 Ogre::Vector2(0.05, 0.65)));
    components.push_back(new FunctorButton<SelectPriest>(*this, "PRIEST",
						 Ogre::Vector2(0.05, 0.75)));
    components.push_back(new FunctorButton<SelectArcher>(*this, "ARCHER",
						 Ogre::Vector2(0.05, 0.7)));

    if (active)
      overlay->show();
    instance = this;
  }

  ClassSelectContext::ClassSelectContext(const ClassSelectContext &o) :
    Context(o)
  {
  }

  ClassSelectContext &ClassSelectContext::operator=(const ClassSelectContext &o)
  {
    return *this;
  }

  ClassSelectContext::~ClassSelectContext(void)
  {
  }

};
