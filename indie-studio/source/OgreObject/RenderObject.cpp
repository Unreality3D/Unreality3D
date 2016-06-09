//
// RenderObject.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/test/source/OgreObject
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon May  9 08:49:59 2016 Gandoulf
// Last update Mon May  9 17:38:57 2016 Gandoulf
//

#include "OgreObject/RenderObject.hpp"

namespace OgreObject
{
  Ogre::SceneManager *RenderObject::_sceneManager = NULL;

  RenderObject::RenderObject()
    : type(UNKNOWN)
  {

  }

  RenderObject::~RenderObject()
  {

  }

  void RenderObject::addSceneManager(Ogre::SceneManager *&sceneManager)
  {
    _sceneManager = sceneManager;
  }
};
