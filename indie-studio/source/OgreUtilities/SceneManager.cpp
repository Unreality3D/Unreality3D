//
// SceneManager.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source/OgreUtilities
// 
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
// 
// Started on  Sun May  1 11:17:16 2016 Enzo Resse
// Last update Wed May  4 06:58:57 2016 Enzo Resse
//

#include "OgreUtilities/SceneManager.hpp"

namespace OgreUtilities
{
  SceneManager::SceneManager()
    :_sceneManager(0)
  {
    
  }

  SceneManager::~SceneManager()
  {

  }

  Ogre::SceneManager *&SceneManager::getSceneManager()
  {
    return (_sceneManager);
  }

  void SceneManager::setSceneManager(Ogre::Root *&root, std::string const &SMtype,
				     std::string const &SMname)
  {
    _sceneManager = root->createSceneManager(SMtype.c_str(), SMname.c_str());
  }

  void SceneManager::setAmbientLight(float const R, float const G, float const B)
  {
    _sceneManager->setAmbientLight(Ogre::ColourValue(R, G, B));
  }

  void SceneManager::defaultInit(Ogre::Root *&root, std::string const &SMname)
  {
    _sceneManager = root->createSceneManager("DefaultSceneManager", SMname.c_str());
    _sceneManager->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
  }
}
