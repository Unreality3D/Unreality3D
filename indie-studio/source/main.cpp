//#include "Sound/Music.hpp"
#include "IndieStudio/GameManager.hpp"
//#include "appDemarrage.hpp"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
# define WIN32_LEAN_AND_MEAN
# include "windows.h"
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
  int main(int argc, char *argv[])
#endif
{
  OgreUtilities::InitOgre	ogre;
  indie::GameManager		GM(&ogre);

  try {
    GM.start();
   }
  catch( Ogre::Exception& e )
    {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!",
		  MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
      std::cerr << "An exception has occured: " <<
	e.getFullDescription().c_str() << std::endl;
#endif
    }
  return 0;
}

/*Sound::Music son("./media/Sound/testWav.wav");
son.startLoop();
son.setVolume(10);
son.start();*/
