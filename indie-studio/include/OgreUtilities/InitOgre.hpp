//
// InitOgre.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Wed Apr 27 16:00:31 2016 Enzo Resse
// Last update Sun Jun  5 14:58:58 2016 Gandoulf
//

#ifndef INITOGRE_HPP_
# define INITOGRE_HPP_

# include <Ogre.h>
# include <iostream>
# include "OgreUtilities/RenderSystem.hpp"
# include "OgreUtilities/RenderWindow.hpp"
# include "OgreUtilities/SceneManager.hpp"
# include "OgreUtilities/Camera.hpp"
# include "OgreUtilities/Viewport.hpp"
# include "OgreUtilities/OgreMap.hpp"

# define RESOURCE "indie-studio/resource/"

namespace OgreUtilities
{
  enum OgreConfig
    {
      DEFAULT,
      MANUAL,
      DIALOG
    };

  class InitOgre
  {
  public:
    InitOgre();
    ~InitOgre();

    void startOgre(OgreConfig mode, bool recover, std::string const &resFolder);

  private:
    //loading of ressource.cfg
    void resInit(std::string const &resFolder);

    //default initialisastion of ogre

    void defaultInit(bool const &recover);

  public:
    Ogre::Root				*root;
    OgreUtilities::RenderSystem		renderSystem;
    OgreUtilities::OgreMap		ogreMap;
    OgreUtilities::RenderWindow		window;
    OgreUtilities::SceneManager		sceneManager;
    OgreUtilities::Camera		camera;
    OgreUtilities::Viewport		viewport;
  };
};

#endif /* INITOGRE_HPP_ */
