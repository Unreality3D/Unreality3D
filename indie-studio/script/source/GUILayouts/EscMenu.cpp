#include "GUILayouts/EscMenu.hpp"
#include "GUILayouts/Functors.hpp"
#include "Gui/Toggler.hpp"
#include "Gui/FunctorButton.hpp"

EscMenu::EscMenu(void)
  : Context("EscMenu", false)
{
  components.push_back(new Gui::Toggler(*this, OIS::KC_ESCAPE));
  components.push_back(new Gui::FunctorButton<HideMenu>(*this, "CONTINUE",
						   Ogre::Vector2(0.4, 0.4)));
  components.push_back(new Gui::FunctorButton<Quit>(*this, "QUIT ",
					       Ogre::Vector2(0.4, 0.5)));
  std::cout << "[GUI] EscMenu Loaded." << std::endl;
}

EscMenu::EscMenu(const EscMenu &o)
  : Context(0) {}

EscMenu &EscMenu::operator=(const EscMenu &o)
{
  return *this;
}

EscMenu::~EscMenu(void) {}
