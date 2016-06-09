//
// FrameListener.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Jun  3 15:24:42 2016 Gandoulf
// Last update Fri Jun  3 15:42:39 2016 Gandoulf
//

#ifndef FRAMELISTENER_HPP_
# define FRAMELISTENER_HPP_

# include "IndieStudio/GameManager.hpp"

namespace indie
{
  class GameManager;

  class FrameListener : public Ogre::FrameListener
  {
  public:
    FrameListener();
    ~FrameListener();

    virtual bool frameRenderingQueued(const Ogre::FrameEvent&);

  private:
    OgreInput::InputManager	*_im;
    Ogre::RenderWindow		*_win;
  };
};

#endif /* FRAMELISTENER_HPP_ */
