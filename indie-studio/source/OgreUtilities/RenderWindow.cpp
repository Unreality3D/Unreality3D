//
// RenderWindow.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source/OgreUtilities
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Sun May  1 11:12:11 2016 Enzo Resse
// Last update Fri May 20 13:38:45 2016 Gandoulf
//

#include "OgreUtilities/RenderWindow.hpp"

namespace OgreUtilities
{
  RenderWindow::RenderWindow()
    : _window(0)
  {

  }

  RenderWindow::~RenderWindow()
  {

  }

  Ogre::RenderWindow *&RenderWindow::getRenderWindow()
  {
    return (_window);
  }

  void RenderWindow::setRenderWindow(Ogre::Root *&root, std::string const &name)
  {
    if ((_window = root->initialise(true, name.c_str())) == 0)
      throw std::string("root getRenderWindow error");
  }

  void RenderWindow::setNumMipmaps(int const &nbr)
  {
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
  }

  void RenderWindow::defaultInit(Ogre::Root  *&root)
  {
    if ((_window = root->initialise(true, "defaultApplication")) == 0)
      throw std::string("root getRenderWindow error");
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
  }
};
