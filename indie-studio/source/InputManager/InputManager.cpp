//
// InputManager.cpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Sun May 22 16:55:25 2016 Leo Lafon
// Last update Mon May 23 11:38:37 2016 Leo Lafon
//

#include "InputManager/InputManager.hpp"

namespace OgreInput
{
  InputManager::InputManager(Ogre::RenderWindow *window)
    : _window(window)
  {
    OIS::ParamList	pl;
    size_t		windowHnd;
    std::ostringstream	windowHndStr;

    _window->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));


    /**
     * Enable mouse cursor
     */
#if defined OIS_WIN32_PLATFORM
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
    pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
    pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
#elif defined OIS_LINUX_PLATFORM
    pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
    pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
    pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("true")));
    pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
#endif

    _inputManager = OIS::InputManager::createInputSystem(pl);
    _keyboard = static_cast<OIS::Keyboard*>
      (_inputManager->createInputObject(OIS::OISKeyboard, true));
    _mouse = static_cast<OIS::Mouse*>
      (_inputManager->createInputObject(OIS::OISMouse, true));
    _mListener = new MListener();
    _kListener = new KListener();
    _mouse->setEventCallback(_mListener);
    _keyboard->setEventCallback(_kListener);
    windowResized(_window);
    Ogre::WindowEventUtilities::addWindowEventListener(_window, this);
  }

  InputManager::~InputManager()
  {
    Ogre::WindowEventUtilities::removeWindowEventListener(_window, this);
    // windowClosed(_window);
    delete _mListener;
    delete _kListener;
    if (!_window->isClosed())
    {
      delete _keyboard;
      delete _mouse;
    }
  }

  //
  // PUBLIC
  //

  void				InputManager::capture()
  {
    _keyboard->capture();
    _mouse->capture();
  }

  bool				InputManager::getKeyDown(OIS::KeyCode const& kc) const
  {
    return _keyboard->isKeyDown(kc);
  }

  bool				InputManager::getMouseButtonDown(OIS::MouseButtonID const& id) const
  {
    return _mouse->getMouseState().buttonDown(id);
  }

  void				InputManager::setOnMouseMoved(bool (*onMouseMoved)(const OIS::MouseEvent&))
  {
    _mListener->setOnMouseMoved(onMouseMoved);
  }

  void				InputManager::setOnMousePressed(bool (*onMousePressed)(const OIS::MouseEvent&,
										       OIS::MouseButtonID))
  {
    _mListener->setOnMousePressed(onMousePressed);
  }

  void				InputManager::setOnMouseReleased(bool (*onMouseReleased)(const OIS::MouseEvent&,
											 OIS::MouseButtonID))
  {
    _mListener->setOnMouseReleased(onMouseReleased);
  }

  int				InputManager::getMousePosX() const
  {
    return _mouse->getMouseState().X.abs;
  }

  int				InputManager::getMousePosY() const
  {
    return _mouse->getMouseState().Y.abs;
  }

  int				InputManager::getMousePosZ() const
  {
    return _mouse->getMouseState().Z.abs;
  }

  const OIS::MouseState&		InputManager::getMouseState() const
  {
    return _mouse->getMouseState();
  }

  //
  // PROTECTED
  //

  //Adjust mouse clipping area
  void				InputManager::windowResized(Ogre::RenderWindow* rw)
  {
    unsigned int			width, height, depth;
    int				left, top;
    const OIS::MouseState&	ms = _mouse->getMouseState();

    rw->getMetrics(width, height, depth, left, top);
    ms.width = width;
    ms.height = height;
  }

  //Unattach OIS before window shutdown (very important under Linux)
  void				InputManager::windowClosed(Ogre::RenderWindow* rw)
  {
    //Only close for window that created OIS (the main window in these demos)
    if(rw == _window)
      {
	if(_inputManager)
	  {
	    _inputManager->destroyInputObject(_mouse);
	    _inputManager->destroyInputObject(_keyboard);

	    OIS::InputManager::destroyInputSystem(_inputManager);
	    _inputManager = 0;
	  }
      }
  }
};
