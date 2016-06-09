//
// MListener.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/source/InputManager
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat May 21 10:45:20 2016 Gandoulf
// Last update Sat May 21 10:46:37 2016 Gandoulf
//

#include <iostream>
#include "InputManager/MListener.hpp"

namespace OgreInput
{
  MListener::MListener()
    : _onMouseMoved(NULL), _onMousePressed(NULL), _onMouseReleased(NULL) {}

  MListener::MListener(bool (*onMouseMoved)(const OIS::MouseEvent& me),
		       bool (*onMousePressed)(const OIS::MouseEvent& me, OIS::MouseButtonID id),
		       bool (*onMouseReleased)(const OIS::MouseEvent& me, OIS::MouseButtonID id))
    : _onMouseMoved(onMouseMoved),
      _onMousePressed(onMousePressed),
      _onMouseReleased(onMouseReleased) {}

  MListener::~MListener() {}

  bool		MListener::mouseMoved(const OIS::MouseEvent& me)
  {
    return _onMouseMoved ? _onMouseMoved(me) : false;
  }

  bool		MListener::mousePressed(const OIS::MouseEvent& me, OIS::MouseButtonID id)
  {
    return _onMousePressed ? _onMousePressed(me, id) : false;
  }

  bool		MListener::mouseReleased(const OIS::MouseEvent& me, OIS::MouseButtonID id)
  {
    return _onMouseReleased ? _onMouseReleased(me, id) : false;
  }

  void		MListener::setOnMouseMoved(bool (*onMouseMoved)(const OIS::MouseEvent& me))
  {
    _onMouseMoved = onMouseMoved;
  }

  void		MListener::setOnMousePressed(bool (*onMousePressed)(const OIS::MouseEvent& me,
								    OIS::MouseButtonID id))
  {
    _onMousePressed = onMousePressed;
  }

  void		MListener::setOnMouseReleased(bool (*onMouseReleased)(const OIS::MouseEvent& me,
								      OIS::MouseButtonID id))
  {
    _onMouseReleased = onMouseReleased;
  }
};
