//
// InputField.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri Jun  3 10:13:58 2016 jeremy metereau
// Last update Sat Jun  4 15:26:12 2016 jeremy metereau
//

#include "Ogre/Overlay/OgreOverlayManager.h"
#include "Ogre/Overlay/OgreOverlayContainer.h"
#include "IndieStudio/GameManager.hpp"
#include "Gui/Helper.hpp"
#include "Gui/DebugText.hpp"
#include "Gui/Context.hpp"
#include "Gui/InputField.hpp"

namespace Gui
{

  InputField::InputField(Context &ctxt, const std::string &n,
			 const std::string &def, int mx, const Ogre::Vector2 &pos) :
    AComponent(ctxt, n, pos, Ogre::Vector2(Helper::getScalePx(200),
					 Helper::getScalePy(25))),
    content(def), clickedOnce(false), text(NULL), clean(def), max(mx)
  {
    Ogre::OverlayManager &manager = Ogre::OverlayManager::getSingleton();
    Ogre::OverlayContainer *panel = static_cast<Ogre::OverlayContainer *>
      (manager.createOverlayElement("Panel", n + "P"));
    panel->setPosition(pos.x, pos.y);
    panel->setDimensions(dim.x, dim.y);
    panel->setMaterialName("Gold");
    context.getOverlay()->add2D(panel);
    //text
    text = static_cast<Ogre::TextAreaOverlayElement *>
      (manager.createOverlayElement("TextArea", n + "PT"));
    text->setMetricsMode(Ogre::GMM_PIXELS);
    text->setPosition(0, 0);
    text->setDimensions(100, 100);
    text->setCaption(def);
    text->setFontName("OpenSans");
    text->setCharHeight(Helper::getFontSize());
    text->setColourBottom(Ogre::ColourValue(0.8, 0.8, 0.8));
    text->setColourTop(Ogre::ColourValue(0.7, 0.7, 0.7));
    panel->addChild(text);
  }

  InputField::InputField(const InputField &o) :
    AComponent(o)
  {
  }

  InputField &InputField::operator=(const InputField &o)
  {
    return *this;
  }

  InputField::~InputField(void)
  {
  }

  void	InputField::Trigger(void)
  {
    Ogre::ColourValue col(0.3, 0.3, 0.3);

    if (!clickedOnce)
      {
	clickedOnce = true;
	content = "";
	text->setCaption(content + "|");
      }
    setActive(true);
    text->setColourBottom(col);
    text->setColourBottom(col);
  }

  void	InputField::unTrigger(void)
  {
    Ogre::ColourValue col(0.7, 0.7, 0.7);

    setActive(false);
    text->setColourBottom(col);
    text->setColourBottom(col);
  }

  void	InputField::TriggerKey(void)
  {
    OgreInput::InputManager &inputs = *(indie::GameManager::getInputManager());
    for (int i = OIS::KeyCode::KC_UNASSIGNED; i < OIS::KeyCode::KC_MAIL; ++i)
      {
	if (inputs.getKeyDown((OIS::KeyCode)i))
	  {
	    DebugText::addText(("Key: " + Helper::keyToChar(i) + "/" + std::to_string(i)));
	    if (Helper::keyToChar(i) == "\r" && content.size() != 0)
	      content.pop_back();
	    else if (Helper::keyToChar(i) != "\r"
		     && Helper::keyToChar(i) != "\n"
		     && content.size() < max)
	      {
		if (content.back() == '|')
		  content.pop_back();
		content += Helper::keyToChar(i);
	      }
	  }
      }
  }

  void	InputField::update(void)
  {
    if (!context.isActive())
      {
	setActive(false);
	return ;
      }
    else
      {
	if (active)
	  {
	    if (time(0) % 2 == 1 && content.back() == '|')
	      content.pop_back();
	    else if (time(0) % 2 == 0 && content.back() != '|')
	      content += '|';
	  }
	else
	  if (content.back() == '|')
	    content.pop_back();
	text->setCaption(content);
	clean = content;
	if (clean.back() == '|')
	  clean.pop_back();
	DebugText::addText("[Input]\ncontent: " + clean);
      }
    return ;
  }

  const std::string &InputField::getValue(void) const
  {
    return clean;
  }

};
