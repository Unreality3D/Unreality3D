//
// MenuButton.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 11:04:59 2016 jeremy metereau
// Last update Sat Jun  4 14:04:45 2016 jeremy metereau
//

#include <iostream>

#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Ogre/Overlay/OgreOverlayContainer.h"
#include "Ogre/Overlay/OgreTextAreaOverlayElement.h"

#include "Gui/Helper.hpp"
#include "Gui/MenuButton.hpp"
#include "Gui/Context.hpp"

namespace Gui
{

  MenuButton::MenuButton(Context &ctxt, const std::string &n,
			 const Ogre::Vector2 &pos) :
    AComponent(ctxt, n, pos, Ogre::Vector2(Helper::getScalePx(200),
						       Helper::getScalePy(25)), false)
  {
    Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();
    Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer *>
      (overlayManager.createOverlayElement("Panel", ctxt.getName() + n + "P"));
    panel->setPosition(pos.x, pos.y);
    panel->setDimensions(dim.x, dim.y);
    panel->setMaterialName("Gold");
    context.getOverlay()->add2D(panel);
    // text
    Ogre::TextAreaOverlayElement *textArea = static_cast<Ogre::TextAreaOverlayElement *>
      (overlayManager.createOverlayElement("TextArea", ctxt.getName() + n + "PT"));
    textArea->setMetricsMode(Ogre::GMM_PIXELS);
    textArea->setPosition(0, 0);
    textArea->setDimensions(100, 100);
    textArea->setCaption("  " + n);
    textArea->setFontName("OpenSans");
    textArea->setCharHeight(Helper::getFontSize());
    textArea->setColourBottom(Ogre::ColourValue(0.0, 0.0, 0.0));
    textArea->setColourTop(Ogre::ColourValue(0.5, 0.5, 0.5));
    panel->addChild(textArea);
  }

  MenuButton::MenuButton(const MenuButton &o) :
    AComponent(o)
  {
  }

  MenuButton &MenuButton::operator=(const MenuButton &o)
  {
    return *this;
  }

  MenuButton::~MenuButton(void)
  {
  }

  void	MenuButton::Trigger(void)
  {
    return ;
  }

};
