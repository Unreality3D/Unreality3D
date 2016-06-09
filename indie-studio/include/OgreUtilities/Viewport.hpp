//
// RenderSystem.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include/OgreUtilities
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Sun May  1 10:47:02 2016 Enzo Resse
// Last update Mon Jun  6 17:34:34 2016 jeremy metereau


#ifndef VIEWPORT_HPP_
# define VIEWPORT_HPP_

#include <Ogre.h>
#include <string>

namespace OgreUtilities
{
  class Viewport
  {
  public:
    Viewport();
    ~Viewport();

    Ogre::Viewport *&getViewport();

    void setViewport(Ogre::Camera *&camera, Ogre::RenderWindow *&window);
    void setDimensions(float const left, float const top, float const width, float const height);
    void setBackgroundColour(Ogre::ColourValue const & color);
    void setAspectRatio(Ogre::Camera *&camera, int const width, int const height);

    void defaultInit(Ogre::Camera *&camera, Ogre::RenderWindow *&window);

    int getActualWidth();
    int	getActualHeight();
  private:
    Ogre::Viewport		*_viewport;
  };
};

#endif /* VIEWPORT_HPP_ */
