#include "appDemarrage.hpp"

OgreUtilities::InitOgre  AppDemarrage::_ogre;

AppDemarrage::AppDemarrage()
//  : _ogre()
{

}

AppDemarrage::~AppDemarrage()
{

}

bool AppDemarrage::start()
{
  OgreUtilities::OgreConfig mode = OgreUtilities::MANUAL;

  _ogre.startOgre(mode, true, RESOURCE);
  if (mode == OgreUtilities::MANUAL)
    {
      std::cout << "MANUAL" << std::endl;
      _ogre.renderSystem.setRenderSystem(_ogre.root, OPENGLSYS);
      _ogre.renderSystem.setFullScreen(false);
      _ogre.renderSystem.setVerticalSync(false);
      _ogre.renderSystem.setScreenSize(1200, 800);

      _ogre.ogreMap.setOgreMap(_ogre.renderSystem.getRenderSystem());
      //_ogre.ogreMap.dysplaySysOption();

      _ogre.window.setRenderWindow(_ogre.root, std::string("toto"));
      _ogre.window.setNumMipmaps(5);

      _ogre.sceneManager.setSceneManager(_ogre.root, std::string("DefaultSceneManager"),
					 std::string("Default"));
      _ogre.sceneManager.setAmbientLight(1.0f, 1.0f, 1.0f);

      _ogre.camera.setCamera(_ogre.sceneManager.getSceneManager(), std::string("player"));
      _ogre.camera.setPosition(Ogre::Vector3(0, 400, 300));
      _ogre.camera.lookAt(Ogre::Vector3(0, 0, 0));
      _ogre.camera.SetNearClipDistance(5);

      _ogre.viewport.setViewport(_ogre.camera.getCamera(), _ogre.window.getRenderWindow());
      _ogre.viewport.setDimensions(0, 0, 1, 1);
      _ogre.viewport.setBackgroundColour(Ogre::ColourValue(0, 0, 0));
    }

  Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
  InputManager *inputManager = new InputManager(_ogre.window.getRenderWindow());

  OgreObject::RenderObject::addSceneManager(_ogre.sceneManager.getSceneManager());

  OgreObject::Mesh		*obj;
  indie::Player			toto(inputManager, _ogre.camera);

  obj = toto.GetComponent<OgreObject::Mesh *>();
  obj->addNode("toto", NULL, Ogre::Vector3(0, 0, 0));
  obj->addMesh("pinguin", "penguin.mesh");

  OgreObject::Mesh		*tata;
  indie::GameObject		*tutu = new indie::GameObject();
  tutu->create<OgreObject::Mesh>();

  tata = tutu->GetComponent<OgreObject::Mesh *>();
  tata->addNode("tutu", NULL, Ogre::Vector3(300, 0, 0));
  tata->addMesh("ninja", "penguin.mesh");

  while(true)
    {
      Ogre::WindowEventUtilities::messagePump();

      if(_ogre.window.getRenderWindow()->isClosed())
        return false;
      if(!_ogre.root->renderOneFrame())
  	{
  	  std::cout << "et merde" << std::endl;
  	  return false;
  	}
      inputManager->capture();

      if(inputManager->getKeyDown(OIS::KC_ESCAPE))
	return false;

      toto.Update();
    }
  return true;
}
