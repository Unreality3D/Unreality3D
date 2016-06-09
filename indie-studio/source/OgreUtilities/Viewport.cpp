//
// Viewport.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source/OgreUtilities
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Sun May  1 15:12:23 2016 Enzo Resse
// Last update Mon Jun  6 17:36:36 2016 jeremy metereau
//

#include "OgreUtilities/Viewport.hpp"

namespace OgreUtilities
{
  Viewport::Viewport()
    : _viewport(0)
  {

  }

  Viewport::~Viewport()
  {

  }

  Ogre::Viewport *&Viewport::getViewport()
  {
    return (_viewport);
  }

  void Viewport::setViewport(Ogre::Camera *&camera, Ogre::RenderWindow *&window)
  {
    _viewport = window->addViewport(camera);
    camera->setAspectRatio(Ogre::Real(_viewport->getActualWidth()) /
			   Ogre::Real(_viewport->getActualHeight()));
  }

  void Viewport::setDimensions(float const left, float const top,
			       float const width, float const height)
  {
    _viewport->setDimensions(Ogre::Real(left), Ogre::Real(top),
			     Ogre::Real(width), Ogre::Real(height));
  }

  void Viewport::setBackgroundColour(Ogre::ColourValue const & color)
  {
    _viewport->setBackgroundColour(color);
  }

  void Viewport::setAspectRatio(Ogre::Camera *&camera, int const width, int const height)
  {
    camera->setAspectRatio(Ogre::Real(width)/ Ogre::Real(height));
  }

  void Viewport::defaultInit(Ogre::Camera *&camera, Ogre::RenderWindow *&window)
  {
    _viewport = window->addViewport(camera);
    _viewport->setBackgroundColour(Ogre::ColourValue(0,0,0));
    camera->setAspectRatio(Ogre::Real(_viewport->getActualWidth()) /
			    Ogre::Real(_viewport->getActualHeight()));
  }

  int Viewport::getActualWidth(void)
  {
    return _viewport->getActualWidth();
  }

  int Viewport::getActualHeight(void)
  {
    return _viewport->getActualHeight();
  }

}
