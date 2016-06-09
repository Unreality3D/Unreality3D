//
// InputField.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri Jun  3 09:51:26 2016 jeremy metereau
// Last update Sat Jun  4 15:26:01 2016 jeremy metereau
//

#ifndef INPUTFIELD_HPP_
# define INPUTFIELD_HPP_

# include "Ogre/Overlay/OgreTextAreaOverlayElement.h"
# include "Gui/AComponent.hpp"

namespace Gui
{

  class InputField : public AComponent
  {
  protected:
    std::string content;
    std::string clean;
    bool	clickedOnce;
    Ogre::TextAreaOverlayElement *text;
    int		max;

  public:
    InputField(Context &, const std::string &, const std::string &,
	       int, const Ogre::Vector2 &);
    InputField(const InputField &o);
    InputField &operator=(const InputField &o);
    virtual ~InputField(void);

    virtual void	Trigger(void);
    virtual void	unTrigger(void);

    virtual void	TriggerKey(void);

    virtual void	update(void);
    virtual const std::string &getValue(void) const;
  };

};

#endif /* !INPUTFIELD_HPP_ */
