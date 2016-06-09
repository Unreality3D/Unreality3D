//
// SampleText.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 16:06:58 2016 jeremy metereau
// Last update Sun Jun  5 18:51:14 2016 jeremy metereau
//

#ifndef SAMPLETEXT_HPP_
# define SAMPLETEXT_HPP_

# include <map>
# include "Ogre/Overlay/OgreTextAreaOverlayElement.h"
# include"Gui/AComponent.hpp"

namespace Gui
{

  class SampleText : public AComponent
  {
  protected:
    Ogre::TextAreaOverlayElement *text;

    static std::map<std::string, SampleText *>	elms;

  public:
    SampleText(Context &, const std::string &, const Ogre::Vector2 &, const Ogre::ColourValue &);
    SampleText(const SampleText &);
    SampleText &operator=(const SampleText &);
    virtual ~SampleText(void);

    static void setText(const std::string &, const std::string &);
  };

};

#endif /* !SAMPLETEXT_HPP_ */
