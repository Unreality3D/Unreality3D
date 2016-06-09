//
// System.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/source/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 14:44:06 2016 jeremy metereau
// Last update Fri May 27 15:59:39 2016 jeremy metereau
//

#include <Ogre.h>
#include "Ogre/Overlay/OgreOverlaySystem.h"
#include "Gui/System.hpp"
#include "Gui/TextRegistrar.hpp"
#include "IndieStudio/GameManager.hpp"

namespace Gui
{
  int	System::instances = 0;

  System::System(void) : isInit(false)
  {
    if (instances == 0)
      {
	isInit = true;
	instances++;
	Ogre::OverlaySystem *overlaySystem = new Ogre::OverlaySystem;
	Ogre::SceneManager *sceneManager = indie::GameManager::getSceneManager();
	sceneManager->addRenderQueueListener(overlaySystem);
	// Registering fonts
	TextRegistrar	fontPool("./resource/fonts/");
	fontPool.addFont("OpenSans", "OpenSans-Semibold.ttf");
      }
  }

  System::System(const System &) : isInit(false)
  {
  }

  System &System::operator=(const System &o)
  {
    return *this;
  }

  System::~System(void)
  {
    if (isInit)
      {
	instances--;
      }
  }

};
