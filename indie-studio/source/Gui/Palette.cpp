//
// Palette.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Tue May 24 17:42:07 2016 jeremy metereau
// Last update Wed May 25 10:28:33 2016 jeremy metereau
//

#include "Ogre.h"
#include "Gui/Palette.hpp"

namespace Gui
{

  Palette::Palette(void)
  {
  }

  Palette::Palette(const Palette &o)
  {
  }

  Palette &Palette::operator=(const Palette &o)
  {
    return *this;
  }

  Palette::~Palette(void)
  {
  }

  void	Palette::add(const std::string &n, float r, float g, float b)
  {
    Ogre::MaterialPtr mMat =
      Ogre::MaterialManager::getSingleton().create(n, "General", true);
    Ogre::Technique *mTech = mMat->createTechnique();
    Ogre::Pass *mPass = mTech->createPass();
    Ogre::TextureUnitState *mTexUnitState = mPass->createTextureUnitState();
    mPass = mMat->getTechnique(0)->getPass(0);
    mPass->setDiffuse(Ogre::ColourValue(r, g, b));
  }

  void	Palette::add(const std::string &n, int hex)
  {
    add(n, hex >> 16 & 0xFF, hex >> 8 & 0xFF, hex & 0xFF);
  }

};
