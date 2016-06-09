//
// RenderSystem.hpp for  in /home/resse_e/rendu/cpp_indie_studio/test/include/OgreUtilities
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Sun May  1 10:47:02 2016 Enzo Resse
// Last update Tue May 10 14:02:57 2016 Gandoulf
//

#ifndef RENDERSYSTEM_HPP_
# define RENDERSYSTEM_HPP_

# include <Ogre.h>
# include <string>

# define DIRECTXSYS	"Direct3D9 Rendering Subsystem"
# define OPENGLSYS	"OpenGL Rendering Subsystem"

# ifdef __ANDROID__
#  include <string>
#  include <sstream>

namespace std
{
  template <typename T>
  std::string to_string(T value)
  {
    std::ostringstream os ;
    os << value ;
    return os.str() ;
  }
}
# endif /* __ANDROID__ */

namespace OgreUtilities
{
  class RenderSystem
  {
  public:
    RenderSystem();
    ~RenderSystem();

    Ogre::RenderSystem *&getRenderSystem();

    void setRenderSystem(Ogre::Root *&root, std::string const &system);
    void setFullScreen(bool const &trigger);
    void setVerticalSync(bool const &trigger);
    void setScreenSize(int const &x, int const &y);

    void setConfigOption(char const *spe, char const *param);

    void defaultInit(Ogre::Root *&root, std::string const &system);

  private:
    Ogre::RenderSystem		*_renderSystem;
  };
};

#endif /* RENDERSYSTEM_HPP_ */
