#include "GUILayouts/InGameMenu.hpp"
#include "Gui/FunctorField.hpp"
#include "Gui/FunctorButton.hpp"
#include "GUILayouts/Functors.hpp"
#include "Gui/LifeBar.hpp"
#include "Gui/SampleText.hpp"

InGameMenu::InGameMenu(void)
  : Context("InGameMenu", true)
{
  components.push_back(new Gui::SampleText(*this, "class", Ogre::Vector2(0.02, 0.05), Ogre::ColourValue(1, 1, 1)));
  components.push_back(new Gui::SampleText(*this, "level", Ogre::Vector2(0.08, 0.05), Ogre::ColourValue(1, 1, 1)));
  components.push_back(new Gui::LifeBar(*this));
  if (active)
    overlay->show();
}

InGameMenu::InGameMenu(const InGameMenu &o)
    : Context(o) {}

InGameMenu &InGameMenu::operator=(const InGameMenu &o)
{
  return *this;
}

InGameMenu::~InGameMenu(void) {}
