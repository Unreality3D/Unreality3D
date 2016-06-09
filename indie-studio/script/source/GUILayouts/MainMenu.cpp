#include "Gui/FunctorField.hpp"
#include "GUILayouts/MainMenu.hpp"
#include "Gui/FunctorButton.hpp"
#include "GUILayouts/Functors.hpp"
#include "Gui/LifeBar.hpp"
#include "Gui/SampleText.hpp"

MainMenu::MainMenu(void)
  : Context("MainMenu", false)
{
  components.push_back(new Gui::FunctorButton<Quit>(*this, " QUIT",
						    Ogre::Vector2(0.5, 0.3)));
  components.push_back(new Gui::FunctorButton<SelectClass>(*this, " START",
  							   Ogre::Vector2(0.35, 0.3)));
  if (active)
    overlay->show();
}

MainMenu::MainMenu(const MainMenu &o)
    : Context(o) {}

MainMenu &MainMenu::operator=(const MainMenu &o)
{
  return *this;
}

MainMenu::~MainMenu(void) {}
