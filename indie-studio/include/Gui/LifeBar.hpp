//
// LifeBar.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 16:06:58 2016 jeremy metereau
// Last update Sat Jun  4 16:11:57 2016 jeremy metereau
//

#ifndef LIFEBAR_HPP_
# define LIFEBAR_HPP_

# include "Ogre/Overlay/OgreTextAreaOverlayElement.h"
# include"Gui/AComponent.hpp"

namespace Gui
{

  class LifeBar : public AComponent
  {
  protected:
    Ogre::TextAreaOverlayElement *text;
    int	max;
    int actual;

    static LifeBar *single;

  public:
    LifeBar(Context &);
    LifeBar(const LifeBar &);
    LifeBar &operator=(const LifeBar &);
    virtual ~LifeBar(void);

    virtual void update(void);
    static void setMax(int);
    static void setLife(int);
  };

};

#endif /* !LIFEBAR_HPP_ */
