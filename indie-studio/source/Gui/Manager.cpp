//
// Manager.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/source/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 15:07:34 2016 jeremy metereau
// Last update Sun Jun  5 18:38:51 2016 Leo Lafon
//

#include "InputManager/InputManager.hpp"
#include "IndieStudio/GameManager.hpp"
#include "Gui/Manager.hpp"
#include "Gui/DebugText.hpp"

namespace Gui
{
  System *Manager::sys = NULL;

  /*
  ** Coplien
  */
  Manager::Manager(void) :
    elapsed(0)
  {
    if (sys == NULL)
      sys = new System;
    _im = indie::GameManager::getInputManager();
  }

  Manager::Manager(const Manager &o)
  {
  }

  Manager &Manager::operator=(const Manager &o)
  {
    return *this;
  }

  Manager::~Manager(void)
  {
  }

  /*
  ** Misc
  */

  Manager &Manager::addContext(Context *context)
  {
    contexts.push_back(context);
    return *this;
  }

  Context *Manager::getContext(const std::string &name)
  {
    for (std::vector<Context *>::const_iterator it = contexts.begin();
	 it != contexts.end(); ++it)
      {
	if ((*it)->getName() == name)
	  return *it;
      }
    return NULL;
  }

  void Manager::removeContext(const std::string &name)
  {
    for (std::vector<Context *>::iterator it = contexts.begin();
	 it != contexts.end(); ++it)
      {
	if ((*it)->getName() == name)
	  {
	    contexts.erase(it);
	    return;
	  }
      }
  }

  void	Manager::processInputs(float deltaTime)
  {
    elapsed += deltaTime;
    if (elapsed >= 0.06)
      {
	DebugText::addText("dT:" + std::to_string(deltaTime));
	for (std::vector<Context *>::const_iterator it = contexts.begin();
	     it != contexts.end(); ++it)
	  {
	    (*it)->pollMouse(_im->getMousePosX() + 6, _im->getMousePosY() + 6,
			     _im->getMouseButtonDown(OIS::MouseButtonID::MB_Left));
	    (*it)->pollKey();
	  }
	elapsed = 0;
      }
  }

  /*
  ** Statics
  */
  void	Manager::destroySystem(void)
  {
    delete sys;
  }
};
