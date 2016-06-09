//
// FrameListener.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/source/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Jun  3 15:30:07 2016 Gandoulf
// Last update Sat Jun  4 15:08:16 2016 jeremy metereau
//

#include "IndieStudio/FrameListener.hpp"

typedef std::map <std::string, indie::GameObject *> MapType;

namespace indie
{
  FrameListener::FrameListener()
  {
    _im = indie::GameManager::getInputManager();
    _win = indie::GameManager::getRenderWindow();
  }

  FrameListener::~FrameListener()
  {

  }

  bool FrameListener::frameRenderingQueued(const Ogre::FrameEvent &fe)
  {
    if (_win->isClosed())
      return false;
    _im->capture();
    indie::GameManager::getGuiManager()->processInputs(fe.timeSinceLastFrame);
    indie::GameManager::managerUpdate();
    indie::GameManager::setDeltaTime(fe.timeSinceLastFrame);
    std::map<std::string, GameObject *> m = indie::GameManager::getGameObjects()
      .getDynamicObjects();
    for(MapType::iterator it = m.begin(); it != m.end(); ++it )
      {
	// std::cout << it->second->getName() << std::endl;
	it->second->Update();
      }
    return true;
  }
};
