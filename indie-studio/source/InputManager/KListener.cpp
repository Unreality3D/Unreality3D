//
// KListener.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/source/InputManager
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat May 21 10:44:51 2016 Gandoulf
// Last update Sat May 21 10:45:09 2016 Gandoulf
//

#include "InputManager/KListener.hpp"

namespace OgreInput
{
  KListener::KListener()
    : _onKeyPressed(NULL), _onKeyReleased(NULL) {}

  KListener::KListener(bool (*onKeyPressed)(const OIS::KeyEvent&),
		       bool (*onKeyReleased)(const OIS::KeyEvent&))
    : _onKeyPressed(onKeyPressed), _onKeyReleased(onKeyReleased) {}

  KListener::~KListener() {}

  bool		KListener::keyPressed(const OIS::KeyEvent& ke)
  {
    return _onKeyPressed ? _onKeyPressed(ke) : false;
  }

  bool		KListener::keyReleased(const OIS::KeyEvent& ke)
  {
    return _onKeyReleased ? _onKeyReleased(ke) : false;
  }

  void		KListener::setOnKeyPressed(bool (*onKeyPressed)(const OIS::KeyEvent&))
  {
    _onKeyPressed = onKeyPressed;
  }

  void		KListener::setOnKeyReleased(bool (*onKeyReleased)(const OIS::KeyEvent&))
  {
    _onKeyReleased = onKeyReleased;
  }
};
