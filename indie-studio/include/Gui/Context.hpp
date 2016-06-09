//
// Context.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/include/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 17:09:22 2016 jeremy metereau
// Last update Sat May 28 10:50:28 2016 jeremy metereau
//

#ifndef CONTEXT_HPP_
# define CONTEXT_HPP_

# include <vector>
# include <string>
# include <OISKeyboard.h>
# include "Ogre/Overlay/OgreOverlay.h"
# include "Gui/AComponent.hpp"

namespace Gui
{

  class Context
  {
  protected:
    std::vector<AComponent *>	components;
    bool			active;
    std::string			name;
    Ogre::Overlay		*overlay;

  public:
    Context(const std::string &, bool active = false);
    Context(const Context &);
    Context &operator=(const Context &);
    virtual ~Context(void);

    virtual void	pollMouse(int x, int y, bool click);
    virtual void	pollKey(void);

    virtual bool	isActive(void) const;
    virtual void	show(void);
    virtual void	hide(void);
    virtual void	toggleActive(bool);

    const std::string	&getName(void) const;
    /*
    ** For component uses
    */
    virtual Ogre::Overlay	*getOverlay(void);
  };
};

#endif /* !CONTEXT_HPP_ */
