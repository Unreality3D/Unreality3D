#include "GUILayouts/Functors.hpp"
#include "IndieStudio/GameManager.hpp"
#include "Gauntlet/Gauntlet.hpp"

void HideMenu::operator()(Gui::Context &c)
{
  c.toggleActive(false);
  return ;
}

void Quit::operator()(Gui::Context &c)
{
  exit(0);
  return ;
}

void NetworkInit::operator()(Gui::Context &c, const std::string &field)
{
  c.toggleActive(false);
  return;
}

void SelectClass::operator()(Gui::Context &c)
{
  c.toggleActive(false);
  indie::GameManager::getGame()->GetScript<Gauntlet>()->startGame();
  // ClassSelectContext::instance->toggleActive(true);
  return ;
}

void SelectMage::operator()(Gui::Context &c)
{
  Gauntlet *game = indie::GameManager::getGame()->GetScript<Gauntlet>();

  c.toggleActive(false);
  game->setPlayerClass("mage.prefab");
  game->startMainMenu();
  // NetContext::instance->toggleActive(true);
  return ;
}

void SelectWarrior::operator()(Gui::Context &c)
{
  Gauntlet *game = indie::GameManager::getGame()->GetScript<Gauntlet>();

  c.toggleActive(false);
  game->setPlayerClass("warrior.prefab");
  game->startMainMenu();
  // NetContext::instance->toggleActive(true);
  return ;
}

void SelectArcher::operator()(Gui::Context &c)
{
  Gauntlet *game = indie::GameManager::getGame()->GetScript<Gauntlet>();

  c.toggleActive(false);
  game->setPlayerClass("archer.prefab");
  game->startMainMenu();
  // NetContext::instance->toggleActive(true);
  return ;
}

void SelectPriest::operator()(Gui::Context &c)
{
  Gauntlet *game = indie::GameManager::getGame()->GetScript<Gauntlet>();

  c.toggleActive(false);
  game->setPlayerClass("priest.prefab");
  game->startMainMenu();
  // NetContext::instance->toggleActive(true);
  return ;
}
