//
// LifeBar.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 16:12:46 2016 jeremy metereau
// Last update Sat Jun  4 17:06:31 2016 jeremy metereau
//

#include "Gui/Context.hpp"
#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Ogre/Overlay/OgreOverlayContainer.h"
#include "Gui/LifeBar.hpp"

namespace Gui
{

  LifeBar::LifeBar(Context &c) :
    AComponent(c, "LifeBar", Ogre::Vector2(0.0, 0.0), Ogre::Vector2(0.0), false)
  {
    single = this;
    Ogre::OverlayManager &manager = Ogre::OverlayManager::getSingleton();
    Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer *>
      (manager.createOverlayElement("Panel", "lifebar"));
    panel->setPosition(pos.x, pos.y);
    panel->setDimensions(1, 1);
    context.getOverlay()->add2D(panel);
    text = static_cast<Ogre::TextAreaOverlayElement *>
      (manager.createOverlayElement("TextArea", "lifebart"));
    text->setMetricsMode(Ogre::GMM_PIXELS);
    text->setPosition(pos.x, pos.y);
    text->setDimensions(1, 1);
    text->setCaption("Life");
    text->setFontName("OpenSans");
    text->setCharHeight(20);
    text->setColourBottom(Ogre::ColourValue(0, 1, 0));
    text->setColourTop(Ogre::ColourValue(0, 1, 0));
    panel->addChild(text);
    max = 100;
    actual = 75;
  }

  LifeBar::LifeBar(const LifeBar &o) :
    AComponent(o)
  {
  }

  LifeBar &LifeBar::operator=(const LifeBar &o)
  {
    return *this;
  }

  LifeBar::~LifeBar(void)
  {
  }

  void	LifeBar::update(void)
  {
    // 206
    std::string content;
    if (max == 0)
      max = 1;
    int		scale = (actual * 206) / max;

    for (int i = 0; i < scale; ++i)
      content += '|';
    text->setCaption(content);
  }

  LifeBar *LifeBar::single = NULL;

  void	LifeBar::setMax(int n)
  {
    if (single != NULL)
      single->max = n;
  }

  void	LifeBar::setLife(int n)
  {
    if (single != NULL)
      single->actual = n;
  }

};
