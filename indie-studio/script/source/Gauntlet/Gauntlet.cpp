#include "Gauntlet/Gauntlet.hpp"
#include "IndieStudio/GameManager.hpp"
#include "MapGenerator/SMapGenerator.hpp"
#include "GUILayouts/GUILayouts.hpp"
#include "Gui/SampleText.hpp"

Gauntlet::Gauntlet(indie::GameObject *&_gameObject)
  : AScript(_gameObject) {}

Gauntlet::~Gauntlet() {}

void Gauntlet::Start()
{
  gui = indie::GameManager::instantiate("gui.prefab", Ogre::Vector3::ZERO);
  guiManager = indie::GameManager::getGuiManager();
  GUILayouts *guiScript = gui->GetScript<GUILayouts>();

  guiManager->addContext(guiScript->getClassSelectionMenu());
  guiManager->addContext(guiScript->getMainMenu());
  guiManager->addContext(guiScript->getEscMenu());
  guiManager->addContext(guiScript->getInGameMenu());

  guiManager->getContext("MainMenu")->toggleActive(false);
  guiManager->getContext("EscMenu")->toggleActive(false);
  guiManager->getContext("InGameMenu")->toggleActive(false);
}

void Gauntlet::startMainMenu()
{
  indie::GameManager::getGuiManager()->getContext("MainMenu")->toggleActive(true);
  if (gameObject->getSounds().size() > 0)
    {
      gameObject->getSounds()[0]->startLoop();
      gameObject->getSounds()[0]->setVolume(30);
      gameObject->getSounds()[0]->start();
    }
}

void Gauntlet::startGame()
{
  Gui::Manager		*guiManager;
  indie::IndieParser	parser;

  map = indie::GameManager::instantiate("gameManager.prefab", Ogre::Vector3::ZERO);
  player = indie::GameManager::instantiate(playerClass.empty() ? "archer.prefab" : playerClass,
					   map->GetScript<SMapGenerator>()->getMapStart());
  Gui::SampleText::setText("level", std::to_string(1));
  Gui::SampleText::setText("class", playerClass);
  indie::GameManager::getGuiManager()->getContext("InGameMenu")->toggleActive(true);
}

void Gauntlet::newMap()
{
  map->GetScript<SMapGenerator>()->GenerateNewMap();
  player->setPositionF(map->GetScript<SMapGenerator>()->getMapStart());
}

void Gauntlet::setPlayerClass(std::string const& pClass)
{
  playerClass = pClass;
}

std::string const& Gauntlet::getPlayerClass() const
{
  return playerClass;
}
