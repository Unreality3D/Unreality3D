//
// DebugText.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 17:55:22 2016 jeremy metereau
// Last update Fri Jun  3 15:41:36 2016 jeremy metereau
//

#ifndef DEBUGTEXT_HPP_
# define DEBUGTEXT_HPP_

# include "Ogre/Overlay/OgreTextAreaOverlayElement.h"
# include "Gui/AComponent.hpp"

namespace Gui
{

  class DebugText : public AComponent
  {
  protected:
    Ogre::TextAreaOverlayElement *text;

    std::string content;
    static DebugText *single;

  public:
    DebugText(Context &);
    DebugText(const DebugText &);
    DebugText &operator=(const DebugText&);
    virtual ~DebugText(void);

    virtual void update(void);

    static void addText(const std::string &);
  };

};

#endif /* !DEBUGTEXT_HPP_ */
