//
// DebugText.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 18:09:26 2016 jeremy metereau
// Last update Fri Jun  3 16:16:17 2016 jeremy metereau
//

#include <time.h>
#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Ogre/Overlay/OgreOverlayContainer.h"
#include "Gui/Context.hpp"
#include "Gui/DebugText.hpp"
#include "Gui/Helper.hpp"
#include "IndieStudio/GameManager.hpp"

namespace Gui
{

  DebugText::DebugText(Context &c) :
    AComponent(c, "DebugText", Ogre::Vector2(0.0, 0.0), Ogre::Vector2(0.0), false)
  {
    Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();
    Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer *>
      (overlayManager.createOverlayElement("Panel", "DebugTextPanel"));
    panel->setPosition(0, 0);
    panel->setDimensions(1, 1);
    context.getOverlay()->add2D(panel);
    text = static_cast<Ogre::TextAreaOverlayElement *>
      (overlayManager.createOverlayElement("TextArea", "DebugTextText"));
    text->setMetricsMode(Ogre::GMM_PIXELS);
    text->setPosition(0, 0);
    text->setDimensions(1, 1);
    text->setCaption("Hello world !");
    text->setFontName("OpenSans");
    text->setCharHeight(20);
    text->setColourBottom(Ogre::ColourValue(0, 1, 0));
    text->setColourTop(Ogre::ColourValue(0, 1, 0));
    panel->addChild(text);
    single = this;
  }

  DebugText::DebugText(const DebugText &o) :
    AComponent(o)
  {
  }

  DebugText &DebugText::operator=(const DebugText &o)
  {
    return *this;
  }

  DebugText::~DebugText(void)
  {
  }

  void DebugText::update(void)
  {
    static int init = time(0);

    text->setCaption
      (
       "<--Debug-->\r\n[Gui]\r\nTime: " + std::to_string((time(0) - init) % 10000) + "\r\n" +
       "Mouse: " + std::to_string(indie::GameManager::getInputManager()->getMousePosX() + 6) +
       ":" + std::to_string(indie::GameManager::getInputManager()->getMousePosY() + 6) +
       " " + std::to_string((bool)indie::GameManager::getInputManager()->getMouseButtonDown(OIS::MouseButtonID::MB_Left)) + "\r\n" +
       "" + content
       );
    content.clear();
  }

  DebugText	*DebugText::single = NULL;

  void	DebugText::addText(const std::string &s)
  {
    single->content += s;
    single->content += '\n';
  }
};
