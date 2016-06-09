#include "GUILayouts/GUILayouts.hpp"
#include "GUILayouts/MainMenu.hpp"
#include "GUILayouts/EscMenu.hpp"
#include "GUILayouts/ClassSelectionMenu.hpp"
#include "GUILayouts/InGameMenu.hpp"

GUILayouts::GUILayouts(indie::GameObject *&_go)
  : AScript(_go) {}

GUILayouts::~GUILayouts() {}

void			GUILayouts::Start()
{
  _mainMenu = new MainMenu();
  _escMenu = new EscMenu();
  _classSelectionMenu = new ClassSelectionMenu();
  _inGameMenu = new InGameMenu();
}

Gui::Context		*GUILayouts::getMainMenu()
{
  return _mainMenu;
}

Gui::Context		*GUILayouts::getEscMenu()
{
  return _escMenu;
}

Gui::Context		*GUILayouts::getClassSelectionMenu()
{
  return _classSelectionMenu;
}

Gui::Context		*GUILayouts::getInGameMenu()
{
  return _inGameMenu;
}
