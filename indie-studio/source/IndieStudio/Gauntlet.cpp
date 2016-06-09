//
// Gauntlet.cpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Thu May 26 18:47:54 2016 Leo Lafon
// Last update Sun Jun  5 22:03:00 2016 Korial
//

#include "IndieStudio/Gauntlet.hpp"

typedef std::map <std::string, indie::GameObject *> MapType;

namespace indie
{
  Gauntlet::Gauntlet()
  {
    _map = Map(NB_ROOM, Size(MAP_SIZE, MAP_SIZE),
	       Size(ROOM_MAX_SIZE, ROOM_MAX_SIZE),
	       Size(ROOM_MIN_SIZE, ROOM_MIN_SIZE));
    //_map.set_seed(MAP_SEED);
    _im = indie::GameManager::getInputManager();
    _win = indie::GameManager::getRenderWindow();
  }

  Gauntlet::~Gauntlet() {}

  void		Gauntlet::start()
  {
    _map.generate_map();
    _md.fill_units(_map._map);
    _player = new indie::Player(indie::GameManager::getInputManager(),
				*(indie::GameManager::getCamera()));
    _player->GetComponent<OgreObject::Mesh *>()
      ->addNode("player", NULL, Ogre::Vector3(800, 30, 200))
      ->addMesh("pinguin", "archer.mesh")
      ->setScale(Ogre::Vector3(5, 5, 5));
    _player->setCollider();
    _player->Start();
    indie::GameManager::getGameObjects().addObject(_player, GameObjectManager::DYNAMIC);
    Ogre::LogManager::getSingletonPtr()->logMessage
      (indie::GameManager::getGameObjects().getObject("pinguin")->getName());
    indie::GameManager::getOgreInstance()->root->addFrameListener(this);
    indie::GameManager::getOgreInstance()->root->startRendering();
  }

  bool		Gauntlet::frameRenderingQueued(const Ogre::FrameEvent& fe)
  {
    if (_win->isClosed())
      return false;
    _im->capture();
    indie::GameManager::getGuiManager()->processInputs(fe.timeSinceLastFrame);
    _player->setDeltaTime(fe.timeSinceLastFrame)->Update();
    std::map<std::string, GameObject *> m = indie::GameManager::getGameObjects()
      .getDynamicObjects();
    for(MapType::iterator it = m.begin(); it != m.end(); ++it ) {
      //std::cout << it->second->getName() << std::endl;
      it->second->Update();
    }
    return true;
  }
};
