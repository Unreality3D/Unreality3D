//
// RenderSystem.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include/OgreUtilities
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Sun May  1 10:47:02 2016 Enzo Resse
// Last update Fri May 20 13:38:44 2016 Gandoulf
//

#ifndef RENDERWINDOW_HPP_
# define RENDERWINDOW_HPP_

#include <Ogre.h>
#include <string>

namespace OgreUtilities
{
  class RenderWindow
  {
  public:
    RenderWindow();
    ~RenderWindow();

    Ogre::RenderWindow *&getRenderWindow();

    void setRenderWindow(Ogre::Root *&root, std::string const &name);
    void setNumMipmaps(int const &nbr);

    void defaultInit(Ogre::Root *&root);

  private:
    Ogre::RenderWindow		*_window;
  };
};

#endif /* RENDERWINDOW_HPP_ */
