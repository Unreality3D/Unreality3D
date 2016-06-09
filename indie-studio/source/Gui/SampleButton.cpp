//
// SampleButton.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Mon May 23 10:34:39 2016 jeremy metereau
// Last update Fri May 27 18:27:42 2016 jeremy metereau
//

#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Ogre/Overlay/OgreTextAreaOverlayElement.h"
#include "Gui/Context.hpp"
#include "Gui/SampleButton.hpp"

namespace Gui
{

  SampleButton::SampleButton(Context &ctxt, const std::string &n) :
    AComponent(ctxt, n, Ogre::Vector2(0.0, 0.0), Ogre::Vector2(0.1, 0.1), true)
  {
    Ogre::OverlayManager &overlayManager = Ogre::OverlayManager::getSingleton();
    Ogre::OverlayContainer *pnel = static_cast<Ogre::OverlayContainer *>
      (overlayManager.createOverlayElement("Panel", n));
    pnel->setPosition(pos.x, pos.y);
    pnel->setDimensions(dim.x, dim.y);
    pnel->setMaterialName("Gold");
    context.getOverlay()->add2D(pnel);
    panel = pnel;
    // text
    Ogre::TextAreaOverlayElement *textArea = static_cast<Ogre::TextAreaOverlayElement *>
      (overlayManager.createOverlayElement("TextArea", n + "text"));
    textArea->setMetricsMode(Ogre::GMM_PIXELS);
    textArea->setPosition(0, 0);
    textArea->setDimensions(100, 100);
    textArea->setCaption("Hello, World!");
    textArea->setFontName("OpenSans");
    textArea->setCharHeight(16);
    textArea->setColourBottom(Ogre::ColourValue(1, 0.5, 0.2));
    textArea->setColourTop(Ogre::ColourValue(0.4, 1, 0.8));
    panel->addChild(textArea);
  }

  SampleButton::SampleButton(const SampleButton &o) :
    AComponent(o)
  {
  }

  SampleButton &SampleButton::operator=(const SampleButton &o)
  {
    return *this;
  }

  SampleButton::~SampleButton()
  {
  }

  void	SampleButton::Trigger(void)
  {
    std::cout << "I'm hit !" << std::endl;
  }
};
