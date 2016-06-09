//
// OgreMap.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source/OgreUtilities
// 
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
// 
// Started on  Sun May  1 11:04:19 2016 Enzo Resse
// Last update Wed May  4 06:28:11 2016 Enzo Resse
//

#include "OgreUtilities/OgreMap.hpp"

namespace OgreUtilities
{
  OgreMap::OgreMap()
  {

  }

  OgreMap::~OgreMap()
  {

  }

  Ogre::ConfigOptionMap &OgreMap::getOgreMap()
  {
    return (_ogreMap);
  }

  void OgreMap::setOgreMap(Ogre::RenderSystem *&renderSystem)
  {
    _ogreMap = renderSystem->getConfigOptions();
  }

  void OgreMap::dysplaySysOption()
  {
    for(Ogre::ConfigOptionMap::const_iterator it = _ogreMap.begin();
        it != _ogreMap.end(); it++)
      {
	std::cout << it->first << std::endl;
        for(int i = 0; i < it->second.possibleValues.size(); i++)
	  std::cout << "  " << it->second.possibleValues[i] << std::endl;
      }
  }

  void OgreMap::defaultInit(Ogre::RenderSystem *&renderSystem)
  {
    _ogreMap = renderSystem->getConfigOptions();
    for(Ogre::ConfigOptionMap::const_iterator it = _ogreMap.begin();
        it != _ogreMap.end(); it++)
      {
	std::cout << it->first << std::endl;
        for(int i = 0; i < it->second.possibleValues.size(); i++)
	  std::cout << "  " << it->second.possibleValues[i] << std::endl;
      }
  }
};
