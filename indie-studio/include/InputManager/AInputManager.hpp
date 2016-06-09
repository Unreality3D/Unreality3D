//
// AInputManager.hpp for indie in /home/lafon_l/Rendu/cpp_indie_studio/basic_tuto1
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Thu May  5 10:46:27 2016 Leo Lafon
// Last update Thu May  5 10:49:12 2016 Leo Lafon
//

#ifndef AINPUTMANAGER_HPP_
# define AINPUTMANAGER_HPP_

# include <OISEvents.h>
# include <OISInputManager.h>
# include <OISKeyboard.h>
# include <OISMouse.h>

class AInputManager
{
protected:
  OIS::InputManager	*_inputManager;
  OIS::Keyboard		*_keyboard;
  OIS::Mouse		*_mouse;

public:
  AInputManager() {}
  virtual ~AInputManager() {}

public:
  virtual void		capture() = 0;
};

#endif /* !AINPUTMANAGER_HPP_ */
