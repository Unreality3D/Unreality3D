//
// SampleButton.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Mon May 23 10:23:17 2016 jeremy metereau
// Last update Fri May 27 10:23:48 2016 jeremy metereau
//

#ifndef SAMPLEBUTTON_HPP_
# define SAMPLEBUTTON_HPP_

# include "Ogre/Overlay/OgreOverlayContainer.h"
# include "Gui/AComponent.hpp"

namespace Gui
{

  class SampleButton : public AComponent
  {
  protected:
    Ogre::OverlayContainer	*panel;

  public:
    SampleButton(Context &, const std::string &);
    SampleButton(const SampleButton &);
    SampleButton &operator=(const SampleButton &);
    virtual ~SampleButton();

    virtual void	Trigger(void);
  };

};

#endif /* !SAMPLEBUTTON_HPP_ */
