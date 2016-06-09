//
// InitOgre.cpp for  in /home/resse_e/rendu/cpp_indie_studio/test/source
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Wed Apr 27 16:02:04 2016 Enzo Resse
// Last update Fri May 20 16:41:29 2016 Gandoulf
//

#include "OgreUtilities/InitOgre.hpp"

namespace OgreUtilities
{
  InitOgre::InitOgre()
    : root(0)
  {

  }

  InitOgre::~InitOgre()
  {
    delete root;
  }

  void InitOgre::startOgre(OgreConfig mode, bool recover, std::string const &resFolder)
  {
    root = new Ogre::Root(std::string(resFolder + "plugins.cfg").c_str(),
			   std::string(resFolder + "ogre.cfg").c_str(),
			   std::string(resFolder + "Ogre.log").c_str());

    resInit(resFolder);
    switch (mode)
      {
      case DEFAULT :
	defaultInit(recover);
	break;
      case MANUAL :
	break;
      case DIALOG :
	throw std::string("not implemented");
	break;
      default :
	defaultInit(recover);
	break;
      }
  }

  void InitOgre::resInit(std::string const &resFolder)
  {
    Ogre::ConfigFile configFile;
    Ogre::String secName, typeName, archName;

    configFile.load(std::string(resFolder + "resources.cfg").c_str());
    Ogre::ConfigFile::SectionIterator seci = configFile.getSectionIterator();
    while (seci.hasMoreElements())
      {
	secName = seci.peekNextKey();
	Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
	Ogre::ConfigFile::SettingsMultiMap::iterator i;
	for (i = settings->begin(); i != settings->end(); ++i)
	  {
	    typeName = i->first;
	    archName = i->second;
	    Ogre::ResourceGroupManager::getSingleton()
	      .addResourceLocation(archName, typeName, secName);
	  }
      }
  }

  void InitOgre::defaultInit(bool const &recover)
  {
    if (recover && !root->restoreConfig())
      {
	std::cout << "can't recover config set the default" << std::endl;
#ifdef WINDOWS
	renderSystem.defaultInit(root, DIRECTXSYS);
#else
	renderSystem.defaultInit(root, OPENGLSYS);
#endif
      }
    else if (!recover)
      {
	std::cout << "dont recover" << std::cout;
#ifdef WINDOWS
	renderSystem.defaultInit(root, DIRECTXSYS);
#else
	renderSystem.defaultInit(root, OPENGLSYS);
#endif
      }
    ogreMap.defaultInit(renderSystem.getRenderSystem());
    window.defaultInit(root);
    sceneManager.defaultInit(root, "default");
    camera.defaultInit(sceneManager.getSceneManager());
    viewport.defaultInit(camera.getCamera(), window.getRenderWindow());
  }
}
