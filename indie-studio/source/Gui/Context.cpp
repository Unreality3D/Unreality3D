//
// Context.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sun May 22 17:29:18 2016 jeremy metereau
// Last update Fri Jun  3 11:13:46 2016 jeremy metereau
//

#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Gui/Context.hpp"

namespace Gui
{
  Context::Context(const std::string &name, bool actv) :
    active(actv), name(name), overlay(NULL)
  {
    Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();
    overlay = overlayManager.create(name);
  }

  Context::Context(const Context &o)
  {
  }

  Context &Context::operator=(const Context&o)
  {
    return *this;
  }

  Context::~Context(void)
  {
    for (std::vector<AComponent *>::iterator i = components.begin();
	 i != components.end(); ++i)
      {
	delete *i;
	i = components.erase(i);
      }
  }

  /*
  ** Misc
  */
  void	Context::pollMouse(int x, int y, bool click)
  {
    for (std::vector<AComponent *>::iterator it = components.begin();
	 it != components.end(); ++it)
      {
	if (isActive() || (*it)->isQuiet())
	  {
	    if ((*it)->isIn(x, y))
	      {
		if (click)
		  (*it)->Trigger();
		else
		  (*it)->hover();
	      }
	    else if (click)
	      (*it)->unTrigger();
	  }
	(*it)->update();
      }
    return ;
  }

  void	Context::pollKey(void)
  {
    for (std::vector<AComponent *>::iterator it = components.begin();
	 it != components.end(); ++it)
      {
	if ((*it)->isActive())
	  (*it)->TriggerKey();
      }
    return ;
  }

  bool	Context::isActive(void) const
  {
    return active;
  }

  void	Context::show(void)
  {
    if (!active)
      {
	active = true;
	overlay->show();
      }
    return ;
  }

  void	Context::hide(void)
  {
    if (active)
      {
	active = false;
	overlay->hide();
      }
    return ;
  }

  void	Context::toggleActive(bool state)
  {
    if (state)
      show();
    else
      hide();
    return ;
  }

  Ogre::Overlay	*Context::getOverlay(void)
  {
    return overlay;
  }

  const std::string &Context::getName(void) const
  {
    return name;
  }

};
