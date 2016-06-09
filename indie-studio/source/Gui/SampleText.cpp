//
// SampleText.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 16:12:46 2016 jeremy metereau
// Last update Sun Jun  5 18:51:03 2016 jeremy metereau
//

#include "Gui/Context.hpp"
#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Ogre/Overlay/OgreOverlayContainer.h"
#include "Gui/SampleText.hpp"

namespace Gui
{

  SampleText::SampleText(Context &c, const std::string &n, const Ogre::Vector2 &pos, const Ogre::ColourValue &col) :
    AComponent(c, n, pos, Ogre::Vector2(0.0), false)
  {
    elms[n] = this;
    Ogre::OverlayManager &manager = Ogre::OverlayManager::getSingleton();
    Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer *>
      (manager.createOverlayElement("Panel", n + "P"));
    panel->setPosition(pos.x, pos.y);
    panel->setDimensions(1, 1);
    context.getOverlay()->add2D(panel);
    text = static_cast<Ogre::TextAreaOverlayElement *>
      (manager.createOverlayElement("TextArea", n + "PT"));
    text->setMetricsMode(Ogre::GMM_PIXELS);
    text->setPosition(pos.x, pos.y);
    text->setDimensions(1, 1);
    text->setCaption(n);
    text->setFontName("OpenSans");
    text->setCharHeight(20);
    text->setColourBottom(col);
    text->setColourTop(col);
    panel->addChild(text);
  }

  SampleText::SampleText(const SampleText &o) :
    AComponent(o)
  {
  }

  SampleText &SampleText::operator=(const SampleText &o)
  {
    return *this;
  }

  SampleText::~SampleText(void)
  {
  }

  std::map<std::string, SampleText *> SampleText::elms;

  void	SampleText::setText(const std::string &n, const std::string &content)
  {
    try
      {
	elms[n]->text->setCaption(content);
      }
    catch (std::exception e)
      {
	(void) e;
      }
    return ;
  }

};
