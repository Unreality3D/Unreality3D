//
// RenderSystem.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include/OgreUtilities
// 
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
// 
// Started on  Sun May  1 10:47:02 2016 Enzo Resse
// Last update Wed May  4 06:58:19 2016 Enzo Resse
//

#ifndef SCENEMANAGER_HPP_
# define SCENEMANAGER_HPP_

#include <Ogre.h>
#include <string>

namespace OgreUtilities
{
  class SceneManager
  {
  public:
    SceneManager();
    ~SceneManager();

    Ogre::SceneManager *&getSceneManager();

    void setSceneManager(Ogre::Root *&root, std::string const &SMtype, std::string const &SMname);
    void setAmbientLight(float const R, float const G, float const B);

    void defaultInit(Ogre::Root *&root, std::string const &SMname);
    
  private:
    Ogre::SceneManager		*_sceneManager;
  };
};

#endif /* SCENEMANAGER_HPP_ */
