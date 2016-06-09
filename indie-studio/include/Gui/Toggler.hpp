//
// Toggler.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 18:34:00 2016 jeremy metereau
// Last update Sat Jun  4 15:25:47 2016 jeremy metereau
//

#ifndef TOGGLER_HPP_
# define TOGGLER_HPP_

# include <OISKeyboard.h>
# include "Gui/AComponent.hpp"

namespace Gui
{

  class Toggler : public AComponent
  {
  protected:
    OIS::KeyCode key;

  public:
    Toggler(Context &, const OIS::KeyCode &);
    Toggler(const Toggler &);
    Toggler &operator=(const Toggler &);
    virtual ~Toggler(void);

    virtual void TriggerKey(void);
  };

};

#endif /* !TOGGLER_HPP_ */
