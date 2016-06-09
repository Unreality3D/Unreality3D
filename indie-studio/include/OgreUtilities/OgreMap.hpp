//
// RenderSystem.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include/OgreUtilities
// 
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
// 
// Started on  Sun May  1 10:47:02 2016 Enzo Resse
// Last update Mon May  2 18:14:44 2016 Enzo Resse
//

#ifndef OGREMAP_HPP_
# define OGREMAP_HPP_

#include <Ogre.h>
#include <string>

namespace OgreUtilities
{
  class OgreMap
  {
  public:
    OgreMap();
    ~OgreMap();

    Ogre::ConfigOptionMap &getOgreMap();

    void setOgreMap(Ogre::RenderSystem *&renderSystem);
    void dysplaySysOption();

    void defaultInit(Ogre::RenderSystem *&renderSystem);
    
  private:
    Ogre::ConfigOptionMap	_ogreMap;
  };
};

#endif /* OGREMAP_HPP_ */
