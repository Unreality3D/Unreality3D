#include <OgreWindowEventUtilities.h>

#include "OgreUtilities/InitOgre.hpp"
#include "OgreObject/RenderObject.hpp"
#include "OgreObject/Mesh.hpp"
#include "InputManager/InputManager.hpp"
#include "IndieStudio/Unit.hpp"
#include "IndieStudio/Player.hpp"

class AppDemarrage
{
public:
  AppDemarrage();
  ~AppDemarrage();

  bool start();

private:
  static OgreUtilities::InitOgre	_ogre;
};
