//
// InputManager.hpp for indie in /home/lafon_l/Rendu/cpp_indie_studio/basic_tuto1
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Thu May  5 09:45:33 2016 Leo Lafon
// Last update Sat May 21 10:47:19 2016 Gandoulf
//

#ifndef INPUTMANAGER_HPP_
# define INPUTMANAGER_HPP_

# include <Ogre.h>
# include <OgreWindowEventUtilities.h>

# include "AInputManager.hpp"
# include "MListener.hpp"
# include "KListener.hpp"

namespace OgreInput
{
  class InputManager : public AInputManager, public Ogre::WindowEventListener
  {
  protected:
    Ogre::RenderWindow	*_window;
    MListener		*_mListener;
    KListener		*_kListener;

  protected:
    virtual void	windowResized(Ogre::RenderWindow *);
    virtual void	windowClosed(Ogre::RenderWindow *);

  public:
    InputManager();
    InputManager(Ogre::RenderWindow *);
    virtual ~InputManager();

  public:
    virtual void	capture();

    bool		getKeyDown(OIS::KeyCode const&) const;
    bool		getMouseButtonDown(OIS::MouseButtonID const&) const;
    int		getMousePosX() const;
    int		getMousePosY() const;
    int		getMousePosZ() const;
    const OIS::MouseState&	getMouseState() const;

    void		setOnMouseMoved(bool (*)(const OIS::MouseEvent&));
    void		setOnMousePressed(bool (*)(const OIS::MouseEvent&, OIS::MouseButtonID));
    void		setOnMouseReleased(bool (*)(const OIS::MouseEvent&, OIS::MouseButtonID));
  };
};

#endif /* !INPUTMANAGER_HPP_ */

