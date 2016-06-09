#include "Gui/FunctorField.hpp"
#include "GUILayouts/ClassSelectionMenu.hpp"
#include "Gui/FunctorButton.hpp"
#include "GUILayouts/Functors.hpp"
#include "Gui/LifeBar.hpp"

ClassSelectionMenu::ClassSelectionMenu(void)
  : Context("ClassSelectionMenu", true)
{
  components.push_back(new Gui::FunctorButton<SelectMage>(*this, " MAGE",
							  Ogre::Vector2(0.2, 0.5)));
  components.push_back(new Gui::FunctorButton<SelectPriest>(*this, " PRIEST",
							    Ogre::Vector2(0.35, 0.5)));
  components.push_back(new Gui::FunctorButton<SelectArcher>(*this, " ARCHER",
							    Ogre::Vector2(0.5, 0.5)));
  components.push_back(new Gui::FunctorButton<SelectWarrior>(*this, " WARRIOR",
							     Ogre::Vector2(0.65, 0.5)));
  if (active)
    overlay->show();
}

ClassSelectionMenu::ClassSelectionMenu(const ClassSelectionMenu &o)
    : Context(o) {}

ClassSelectionMenu &ClassSelectionMenu::operator=(const ClassSelectionMenu &o)
{
  return *this;
}

ClassSelectionMenu::~ClassSelectionMenu(void) {}
