//
// TextRegistrar.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/source/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 15:42:57 2016 jeremy metereau
// Last update Mon May 23 18:11:03 2016 jeremy metereau
//

#include <string>
#include "Ogre/Overlay/OgreFontManager.h"
#include "Gui/TextRegistrar.hpp"

namespace Gui
{
  /*
  ** Coplien
  */
  TextRegistrar::TextRegistrar(const std::string &_pool) :
    pool(_pool)
  {
  }

  TextRegistrar::TextRegistrar(const TextRegistrar &o) :
    pool(o.pool)
  {
  }

  TextRegistrar &TextRegistrar::operator=(const TextRegistrar &o)
  {
    return *this;
  }

  TextRegistrar::~TextRegistrar(void)
  {
  }

  /*
  ** Misc
  */
  void	TextRegistrar::addFont(const std::string &name, const std::string &fileName) const
  {
    Ogre::FontPtr mFont = Ogre::FontManager::getSingleton().create(name, "General");
    mFont->setType(Ogre::FT_TRUETYPE);
    mFont->setSource(pool + fileName);
    mFont->setTrueTypeSize(16);
    mFont->setTrueTypeResolution(96);
    mFont->addCodePointRange(Ogre::Font::CodePointRange(33, 255));
    return ;
  }

};
