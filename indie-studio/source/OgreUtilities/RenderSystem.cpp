//
// RenderSystem.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source/OgreUtilities
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Sun May  1 10:54:42 2016 Enzo Resse
// Last update Tue May 10 13:41:28 2016 Gandoulf
//

#include "OgreUtilities/RenderSystem.hpp"

namespace OgreUtilities
{
  RenderSystem::RenderSystem()
    :_renderSystem(0)
  {

  }

  RenderSystem::~RenderSystem()
  {

  }

  Ogre::RenderSystem *&RenderSystem::getRenderSystem()
  {
    return (_renderSystem);
  }

  void RenderSystem::setRenderSystem(Ogre::Root *&root, std::string const &system)
  {
    if ((_renderSystem = root->getRenderSystemByName(system.c_str())) == NULL)
      throw std::string("root getRenderSystem error");
    root->setRenderSystem(_renderSystem);
  }

  void RenderSystem::setFullScreen(bool const &trigger)
  {
    if (trigger)
      _renderSystem->setConfigOption("Full Screen", "Yes");
    else
      _renderSystem->setConfigOption("Full Screen", "No");
  }

  void RenderSystem::setVerticalSync(bool const &trigger)
  {
    if (trigger)
      _renderSystem->setConfigOption("VSync", "Yes");
    else
      _renderSystem->setConfigOption("VSync", "No");
  }

  void RenderSystem::setScreenSize(int const &x, int const &y)
  {
    _renderSystem->setConfigOption
      ("Video Mode", std::string(std::to_string(x) + " x " + std::to_string(y) + " @ 32-bit colour").c_str());
  }

  void RenderSystem::setConfigOption(char const *spe, char const *param)
  {
    _renderSystem->setConfigOption(spe, param);
  }

  void RenderSystem::defaultInit(Ogre::Root *&root, std::string const &system)
  {
    if ((_renderSystem = root->getRenderSystemByName(system.c_str())) == NULL)
      throw std::string("root getRenderSystem error");
    root->setRenderSystem(_renderSystem);
    _renderSystem->setConfigOption("Full Screen", "No");
    _renderSystem->setConfigOption("Video Mode", "1280 x 800 @ 32-bit colour");
    _renderSystem->setConfigOption("VSync", "Yes");
  }
}
