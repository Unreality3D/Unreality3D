//
// Camera.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source/OgreUtilities
// 
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
// 
// Started on  Sun May  1 15:06:59 2016 Enzo Resse
// Last update Wed May  4 07:08:02 2016 Enzo Resse
//

#include "OgreUtilities/Camera.hpp"

namespace OgreUtilities
{
  Camera::Camera()
    :_camera(0)
  {

  }

  Camera::~Camera()
  {

  }

  Ogre::Camera *&Camera::getCamera()
  {
    return (_camera);
  }

  void Camera::setCamera(Ogre::SceneManager *&sceneManager, std::string const &name)
  {
    _camera = sceneManager->createCamera(name.c_str());
  }

  void Camera::setPosition(Ogre::Vector3 const &position)
  {
    _camera->setPosition(position);
  }

  void Camera::lookAt(Ogre::Vector3 const &orientation)
  {
    _camera->lookAt(orientation);
  }

  void Camera::SetNearClipDistance(int const distance)
  {
    _camera->setNearClipDistance(distance);
  }

  void Camera::defaultInit(Ogre::SceneManager *&sceneManager)
  {
    _camera = sceneManager->createCamera("PlayerCam");
    _camera->setPosition(Ogre::Vector3(0,0,100));
    _camera->lookAt(Ogre::Vector3(0,0,0));
    _camera->setNearClipDistance(5);
  }
}
