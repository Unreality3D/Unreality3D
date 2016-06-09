//
// RenderSystem.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include/OgreUtilities
// 
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
// 
// Started on  Sun May  1 10:47:02 2016 Enzo Resse
// Last update Wed May  4 07:07:38 2016 Enzo Resse
//

#ifndef CAMERA_HPP_
# define CAMERA_HPP_

#include <Ogre.h>
#include <string>

namespace OgreUtilities
{
  class Camera
  {
  public:
    Camera();
    ~Camera();

    Ogre::Camera *&getCamera();

    void setCamera(Ogre::SceneManager *&sceneManager, std::string const &name);
    void setPosition(Ogre::Vector3 const &position);
    void lookAt(Ogre::Vector3 const &orientation);
    void SetNearClipDistance(int const distance);

    void defaultInit(Ogre::SceneManager *&_sceneManager);
    
  private:
    Ogre::Camera		*_camera;
  };
};

#endif /* CAMERA_HPP_ */
