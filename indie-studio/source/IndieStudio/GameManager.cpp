//
// GameManager.cpp for  in /home/agor_m/epitech/cpp_indie_studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sun Jun  5 20:04:34 2016 Maxime Agor
// Last update Sun Jun  5 20:04:38 2016 Maxime Agor
//

#include "IndieStudio/GameManager.hpp"
#include "OgreObject/RenderObject.hpp"
#include "OgreObject/Mesh.hpp"
#include "Gui/MainMenuContext.hpp"
#include "Gui/DebugContext.hpp"
#include "Gui/EscMenuContext.hpp"
#include "Gui/Palette.hpp"
#include "Gui/ClassSelectContext.hpp"
#include "Gui/NetContext.hpp"
#include "IndieStudio/MapDisplayer.hpp"
#include "MapGenerator/MapGenerator.hpp"
#include "Network/NetManager.hpp"

namespace indie
{
  std::vector<GDelete>		GameManager::_deleteList;
  Time::Chrono			GameManager::_time;
  OgreUtilities::InitOgre	*GameManager::_ogre = NULL;
  Gui::Manager			*GameManager::_GuiManager = NULL;
  OgreInput::InputManager	*GameManager::_input = NULL;
  indie::GameObjectManager	GameManager::_gameObjects;
  indie::PrefabCreator		GameManager::_prefabCreator;
  indie::FrameListener		*GameManager::_frameListener = NULL;
  Memory::Thread		GameManager::_thread;
  network::NetManager		GameManager::_networkManager;
  float				GameManager::_deltaTime;
  indie::GameObject		*GameManager::_game;

  GameManager::GameManager(OgreUtilities::InitOgre *ogre)
  {
    _ogre = ogre;
  }

  GameManager::~GameManager()
  {
    stop();
  }

  // public static methode

  void GameManager::start()
  {
    startOgre();
    initInputManager();
    startPresentation();
    initGui();
    _game = instantiate("game.prefab", Ogre::Vector3::ZERO);
    _frameListener = new FrameListener();
    indie::GameManager::getOgreInstance()->root->addFrameListener(_frameListener);
    indie::GameManager::getOgreInstance()->root->startRendering();
  }

  void GameManager::stop()
  {
    if (_input != NULL)
      {
	delete _input;
	_input = NULL;
      }
  }

  void	GameManager::managerUpdate()
  {
    if (!_deleteList.empty())
      {
	for (int i = 0; i < _deleteList.size(); ++i)
	  {
	    if (_deleteList.back().ms == 0)
	      {
		_gameObjects.deleteObject(_deleteList.back().go->getName());
		delete _deleteList.back().go;
		_deleteList.pop_back();
	      }
	    else if (_deleteList.back().ms < getActualTime())
	      {
		_gameObjects.deleteObject(_deleteList.back().go->getName());
		delete _deleteList.back().go;
		_deleteList.pop_back();
	      }
	  }
      }
  }

  OgreUtilities::InitOgre		*&GameManager::getOgreInstance()
  {
    return (_ogre);
  }

  Ogre::RenderSystem			*&GameManager::getRenderSystem()
  {
    return (_ogre->renderSystem.getRenderSystem());
  }

  Ogre::RenderWindow			*&GameManager::getRenderWindow()
  {
    return (_ogre->window.getRenderWindow());
  }

  Ogre::SceneManager			*&GameManager::getSceneManager()
  {
    return (_ogre->sceneManager.getSceneManager());
  }

  Ogre::Camera				*&GameManager::getCamera()
  {
    return (_ogre->camera.getCamera());
  }

  Ogre::Viewport			*&GameManager::getViewport()
  {
    return (_ogre->viewport.getViewport());
  }

  OgreInput::InputManager		*&GameManager::getInputManager()
  {
    return (_input);
  }


  Gui::Manager				*&GameManager::getGuiManager()
  {
    return (_GuiManager);
  }

  indie::GameObjectManager		&GameManager::getGameObjects()
  {
    return (_gameObjects);
  }

  indie::PrefabCreator			&GameManager::getPrefabCreator()
  {
    return (_prefabCreator);
  }

  network::NetManager			&GameManager::getNetworkManager()
  {
    return (_networkManager);
  }

  indie::GameObject			*GameManager::instantiate(std::string const &prefabFile,
								  Ogre::Vector3 const & position,
								  Ogre::Quaternion const &rotation,
								  Ogre::Vector3 const & scale)
  {
    return (_prefabCreator.instantiate(prefabFile, position, rotation, scale));
  }

  void					GameManager::destroy(GameObject *gameObject, int ms)
  {
    if (gameObject == NULL)
      return ;
    if (_gameObjects.getObject(gameObject->getName()) != NULL &&
	checkDeleteList(gameObject->getName()) == false)
      {
	if (ms == 0)
	  _deleteList.push_back(GDelete(gameObject, ms));
	else
	  {
	    _deleteList.push_back(GDelete(gameObject, getActualTime() + ms));
	  }
      }
  }

  long					GameManager::getActualTime()
  {
    _time.getActualTime();
  }

  void					GameManager::setDeltaTime(float deltaTime)
  {
    _deltaTime = deltaTime;
  }

  float					GameManager::getDeltaTime()
  {
    return _deltaTime;
  }

  indie::GameObject			*GameManager::getGame()
  {
    return _game;
  }

  // private static methode

  inline bool GameManager::checkDeleteList(std::string const &name)
  {
    for (int i = 0; i < _deleteList.size(); ++i)
      if (_deleteList[i].go->getName() == name)
	{
	  return (true);
	}
    return (false);
  }

  void GameManager::startOgre()
  {
    _ogre->startOgre(OgreUtilities::MANUAL, true, RESOURCE);
    _ogre->renderSystem.setRenderSystem(_ogre->root, OPENGLSYS);
    _ogre->renderSystem.setFullScreen(false);
    _ogre->renderSystem.setVerticalSync(false);
    _ogre->renderSystem.setScreenSize(1920, 1080);

    _ogre->ogreMap.setOgreMap(_ogre->renderSystem.getRenderSystem());

    _ogre->window.setRenderWindow(_ogre->root, std::string("IndieStudio"));
    _ogre->window.setNumMipmaps(5);

    _ogre->sceneManager.setSceneManager(_ogre->root, std::string("DefaultSceneManager"),
				       std::string("Default"));
    _ogre->sceneManager.setAmbientLight(1.0f, 1.0f, 1.0f);

    _ogre->camera.setCamera(_ogre->sceneManager.getSceneManager(), std::string("player"));
    _ogre->camera.setPosition(Ogre::Vector3(0, 400, 300));
    _ogre->camera.lookAt(Ogre::Vector3(0, 0, 0));
    _ogre->camera.SetNearClipDistance(5);

    _ogre->viewport.setViewport(_ogre->camera.getCamera(), _ogre->window.getRenderWindow());
    _ogre->viewport.setDimensions(0, 0, 1, 1);
    _ogre->viewport.setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    OgreObject::RenderObject::addSceneManager(_ogre->sceneManager.getSceneManager());
  }

  void GameManager::initInputManager()
  {
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    _input = new OgreInput::InputManager(_ogre->window.getRenderWindow());
  }

  void GameManager::initGui()
  {
    _GuiManager = new Gui::Manager;

    Gui::Palette colors;
    colors.add("Gray", 0xA9A9A9);
    colors.add("Peru", 0xCD853F);
    colors.add("SaddleBrown", 0x8B4513);
    colors.add("Goldenrod", 0xDAA520);
    colors.add("Gold", 0xFFD700);

    _GuiManager->addContext(new Gui::DebugContext());
  }

  void GameManager::startPresentation()
  {
    return ;
  }
};
