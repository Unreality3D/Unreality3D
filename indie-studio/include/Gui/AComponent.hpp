//
// AComponent.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/include/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 17:10:53 2016 jeremy metereau
// Last update Fri Jun  3 10:49:08 2016 jeremy metereau
//

#ifndef ACOMPONENT_HPP_
# define ACOMPONENT_HPP_

# include <string>
# include <OISKeyboard.h>
# include "Ogre/OgreVector2.h"

namespace Gui
{

  class Context;

  class AComponent
  {
  protected:
    Context		&context;
    Ogre::Vector2	pos;
    Ogre::Vector2	dim;
    bool		active;
    bool		quiet;
    std::string		name;

  public:
    AComponent(Context &, const std::string &,
	       const Ogre::Vector2 &, const Ogre::Vector2 &,
	       bool Q = false);
    AComponent(const AComponent &);
    AComponent &operator=(const AComponent &);
    virtual ~AComponent();
    /*
    ** Should be used for Buttons and other click dependent elemens;
    */
    bool		isQuiet(void) const;
    virtual bool	isIn(int x, int y) const;
    virtual void	Trigger(void);
    virtual void	unTrigger(void);
    virtual void	hover(void);

    /*
    ** Shoud be used for "passive" keyboard dependent entities;
    */
    virtual bool	isActive(void) const;
    virtual void	setActive(bool);
    virtual void	TriggerKey(void);

    virtual void	update(void);
    const std::string &getName(void) const;
    virtual const std::string &getValue(void) const;
  };
};

#endif /* !ACOMPONENT_HPP_ */
