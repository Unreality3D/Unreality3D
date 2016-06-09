//
// PrefabCreator.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/source/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed May 25 14:52:49 2016 Gandoulf
// Last update Mon Jun  6 11:54:02 2016 Gandoulf
//

#include "IndieStudio/PrefabCreator.hpp"
#include "IndieStudio/GameManager.hpp"
#include "OgreObject/Mesh.hpp"
#include "OgreObject/Empty.hpp"
#include "Sound/Music.hpp"
#include <time.h>

namespace indie
{
  PrefabCreator::PrefabCreator()
    : _rootNode(NULL)
  {
    srand (time(NULL));
  }

  PrefabCreator::~PrefabCreator()
  {

  }

  GameObject *PrefabCreator::instantiate(std::string const &prefabFile,
					 Ogre::Vector3 const & position,
					 Ogre::Quaternion const &rotation,
					 Ogre::Vector3 const & scale)
  {
    std::map<std::string, Prefab>::iterator it;
    std::string	_prefabFile;

#if defined(__GNUC__)
    _prefabFile = std::string("indie-studio/prefab/" + prefabFile);
#elif defined(_MSC_VER)
    _prefabFile = std::string("../prefab/" + prefabFile);
#endif
    try {
      loadFile(_prefabFile);
    } catch (PrefabLoadFileError e) {
      Ogre::LogManager::getSingletonPtr()->logMessage(e.what());
      return (NULL);
    }
    if ((it = _prefab.find(_prefabFile)) == _prefab.end())
      {
	Ogre::LogManager::getSingletonPtr()->logMessage("can't instantiate gameobject");
	return (NULL);
      }
    if (it->second._usable)
      {
	GameObject *gameObject;

	gameObject = new GameObject();
	instantiateRenderObject(it->second._properties, gameObject, position, rotation, scale);
	if (gameObject == NULL)
	  {
	    return (gameObject);
	  }
	for (int i = 0; i < it->second._properties.sound.size(); ++i)
	  gameObject->getSounds().push_back(new Sound::Music(it->second._properties.sound[i]));
	gameObject->setTag(it->second._properties.tag);
	if (!it->second._properties.skillFunction.empty())
	  {
	    Ogre::LogManager::getSingletonPtr()->logMessage("push Dynamic gameObject");
	    for (int i = 0; i < it->second._properties.skillFunction.size(); ++i)
	      gameObject->setScript(it->second._properties.skillFunction[i](gameObject));
	    indie::GameManager::getGameObjects()
	      .addObject(gameObject, GameObjectManager::DYNAMIC);
	  }
	else
	  {
	    Ogre::LogManager::getSingletonPtr()->logMessage("push Static gameObject");
	    indie::GameManager::getGameObjects()
	      .addObject(gameObject, GameObjectManager::STATIC);
	  }
	return (gameObject);
      }
  }

  void PrefabCreator::setRootNode(GameObject *node)
  {
    if (node == NULL)
      _rootNode = NULL;
    else
      _rootNode = node->getNode();
  }

  //private methode

  void PrefabCreator::loadFile(std::string const &prefabFile)
  {
    std::map<std::string, Prefab>::iterator it;

    if ((it = _prefab.find(prefabFile)) != _prefab.end())
      return;

    if (!_parser.loadFile(prefabFile))
      {
	Ogre::LogManager::getSingletonPtr()->logMessage("File not Found.");
	return ;
      }
    else{
      _prefab[prefabFile] = Prefab();
      it = _prefab.find(prefabFile);

      try {
	getRenderObjectType(it->second._properties, it->second._usable);
      } catch (PrefabRenderObjectTypeError e) {
	Ogre::LogManager::getSingletonPtr()->logMessage(e.what());
	throw PrefabLoadFileError();
      }
      getName(it->second._properties);
      getTag(it->second._properties);
      getMesh(it->second._properties);
      getScript(it->second._properties);
      getSound(it->second._properties);
      getGeoData(it->second._properties);
      getCollider(it->second._properties);
      getPosition(it->second._properties);
      getRotation(it->second._properties);
      getScale(it->second._properties);
    }
    if (!it->second._properties.script.empty())
      {
	for (int i = 0; i < it->second._properties.script.size(); ++i)
	  {
	    std::map<std::string, Memory::LibraryLoader>::iterator itLib;
	    if ((itLib = _lib.find(it->second._properties.script[i])) == _lib.end())
	      {
		_lib[it->second._properties.script[i]] = Memory::LibraryLoader();
		itLib = _lib.find(it->second._properties.script[i]);
	      }
	    try {
	      loadLibrary(it->second._properties, itLib->second, it->second._usable, i);
	    } catch (PrefabLibraryLoaderError e) {
	      Ogre::LogManager::getSingletonPtr()->logMessage(e.what());
	      throw PrefabLoadFileError();
	    }
	    Ogre::LogManager::getSingletonPtr()->logMessage
	      ("lib found " + it->second._properties.script[i] + ", loading script");
	  }
      }
  }

  void PrefabCreator::getRenderObjectType(Properties & _properties, bool & _usable)
  {
    std::string	type(_parser.getValue("RenderObjectType"));

    if (type == std::string("UNKNOWN"))
      {
	_properties.renderObjectType = 0;
      }
    else if (type == std::string("EMPTY"))
      {
	_properties.renderObjectType = 1;
      }
    else if (type == std::string("MESH"))
      {
	_properties.renderObjectType = 2;
      }
    else if (type == std::string("LIGHT"))
      {
	_properties.renderObjectType = 3;
      }
    else if (type == std::string("CAMERA"))
      {
	_properties.renderObjectType = 4;
      }
    else if (type == std::string("PARTICULE"))
      {
	_properties.renderObjectType = 5;
      }
    else
      {
	_usable = false;
	throw PrefabRenderObjectTypeError();
      }
  }

  void PrefabCreator::getName(Properties & _properties)
  {
    std::string	name(_parser.getValue("Name"));

    if (!name.empty())
      _properties.name = name;
  }

  void PrefabCreator::getTag(Properties & _properties)
  {
    std::string	tag(_parser.getValue("Tag"));

    if (!tag.empty())
      _properties.tag = tag;
  }

  void PrefabCreator::getMesh(Properties & _properties)
  {
    std::string	mesh(_parser.getValue("Mesh"));

    if (!mesh.empty())
      _properties.mesh = mesh;
  }

  void PrefabCreator::getScript(Properties & _properties)
  {
    std::vector<std::string>  script = _parser.stoa(_parser.getValue("Script"), ';');

    if (!script.empty())
      for (int i = 0; i < script.size(); ++i)
	{
#if defined(__GNUC__)
	  _properties.script.push_back(std::string("indie-studio/script/lib/lib" + script[i]));
#elif defined(_MSC_VER)
	  _properties.script.push_back(std::string(script[i]));
#endif
	}
  }

  void PrefabCreator::loadLibrary(Properties & _properties, Memory::LibraryLoader & _library,
				  bool &_usable, int it)
  {
    try {
      _library.loadSharedLibrary(_properties.script[it]);
    } catch (Memory::LibraryLoadError e) {
      Ogre::LogManager::getSingletonPtr()->logMessage(e.what());
      Ogre::LogManager::getSingletonPtr()->logMessage
	(std::string("load error message") + _library.logError());
      _usable = false;
      throw PrefabLibraryLoaderError();
    }
    try {
      _properties.skillFunction.push_back((skillScript)_library.getFunction("getScriptInstance"));
    } catch (Memory::LibraryFunctionLoadError e) {
      Ogre::LogManager::getSingletonPtr()->logMessage(e.what());
      _usable = false;
      throw PrefabLibraryLoaderError();
    }
  }

  void PrefabCreator::getSound(Properties & _properties)
  {
    std::vector<std::string> sound = _parser.stoa(_parser.getValue("Sound"), ';');

    if (!sound.empty())
      {
	for (int i = 0; i < sound.size(); ++i)
	  {
#if defined(__GNUC__)
	    _properties.sound.push_back(std::string("indie-studio/media/" + sound[i]));
#elif defined(_MSC_VER)
	    _properties.sound.push_back(std::string(sound[i]));
#endif
	  }
      }
  }

  void PrefabCreator::getGeoData(Properties & _properties)
  {
    std::string geoData(_parser.getValue("GeoData"));

    if (!geoData.empty())
      _properties.geoData = _parser.stob(geoData);
  }

  void PrefabCreator::getCollider(Properties & _properties)
  {
    std::string collider(_parser.getValue("Collider"));

    if (!collider.empty())
      _properties.collider = _parser.stob(collider);
  }

  void PrefabCreator::getPosition(Properties & _properties)
  {
    std::vector<std::string>  position = _parser.stoa(_parser.getValue("Position"), ';');

    if (position.size() == 3)
      {
	_properties.position.x = _parser.stoi(position[0]);
	_properties.position.y = _parser.stoi(position[1]);
	_properties.position.z = _parser.stoi(position[2]);
      }
    else
      _properties.scale = Ogre::Vector3(0, 0, 0);
  }

  void PrefabCreator::getRotation(Properties & _properties)
  {
    std::vector<std::string>  rotation = _parser.stoa(_parser.getValue("Rotation"), ';');

    if (rotation.size() == 4)
      {
	_properties.rotation.x = _parser.stoi(rotation[0]);
	_properties.rotation.y = _parser.stoi(rotation[1]);
	_properties.rotation.z = _parser.stoi(rotation[2]);
	_properties.rotation.w = _parser.stoi(rotation[3]);
      }
    else
      _properties.rotation = Ogre::Quaternion::IDENTITY;

  }

  void PrefabCreator::getScale(Properties & _properties)
  {
    std::vector<std::string>  scale = _parser.stoa(_parser.getValue("Scale"), ';');

    if (scale.size() == 3)
      {
	_properties.scale.x = _parser.stoi(scale[0]);
	_properties.scale.y = _parser.stoi(scale[1]);
	_properties.scale.z = _parser.stoi(scale[2]);
      }
    else
      _properties.scale = Ogre::Vector3(1, 1, 1);
  }

  //instantiate private methode

  void PrefabCreator::instantiateRenderObject(Properties & _properties,
					      GameObject *&gameObject,
					      Ogre::Vector3 const & position,
					      Ogre::Quaternion const &rotation,
					      Ogre::Vector3 const & scale)
  {
    switch (static_cast<OgreObject::ObjType>(_properties.renderObjectType))
      {
      case (OgreObject::ObjType::UNKNOWN):
	break;
      case (OgreObject::ObjType::EMPTY):
	gameObject->create<OgreObject::Empty>();
	if (_rootNode == NULL)
	  gameObject->GetComponent<OgreObject::Empty *>()->addNode(randomiseName(_properties.name));
	else
	  gameObject->GetComponent<OgreObject::Empty *>()->addNode(randomiseName(_properties.name),
								  _rootNode);
	instantiateEmptyObject(_properties, gameObject, position, rotation, scale);
	break;
      case (OgreObject::ObjType::MESH):
	gameObject->create<OgreObject::Mesh>();
	if (_rootNode == NULL)
	  gameObject->GetComponent<OgreObject::Mesh *>()->addNode();
	else
	  gameObject->GetComponent<OgreObject::Mesh *>()->addNode(_rootNode);
	try {
	  gameObject->GetComponent<OgreObject::Mesh *>()->addMesh(randomiseName(_properties.name),
								  _properties.mesh);
	} catch (...) {
	  Ogre::LogManager::getSingletonPtr()->logMessage("file .mesh not found");
	  delete (gameObject);
	  gameObject = NULL;
	  return ;
	}
	instantiateMeshObject(_properties, gameObject, position, rotation, scale);
	break;
      case (OgreObject::ObjType::LIGHT):
	break;
      case (OgreObject::ObjType::CAMERA):
	break;
      case (OgreObject::ObjType::PARTICULE):
	break;
      default:
	break;
      }
  }

  void PrefabCreator::instantiateUnknowObject(GameObject *&gameObject)
  {
    return ;
  }

  void PrefabCreator::instantiateEmptyObject(Properties & _properties,
					    GameObject *&gameObject,
					    Ogre::Vector3 const & position,
					    Ogre::Quaternion const &rotation,
					    Ogre::Vector3 const & scale)
  {
    gameObject->setPosition(position == Ogre::Vector3(0,0,0) ?_properties.position : position);
    gameObject->setRotation(rotation == Ogre::Quaternion::IDENTITY ?
			    _properties.rotation : rotation);
    gameObject->setScale(scale == Ogre::Vector3(1, 1, 1) ?
			 _properties.scale : scale);
    if (_properties.collider)
      gameObject->setCollider();
    return ;
  }

  void PrefabCreator::instantiateMeshObject(Properties & _properties,
					    GameObject *&gameObject,
					    Ogre::Vector3 const & position,
					    Ogre::Quaternion const &rotation,
					    Ogre::Vector3 const & scale)
  {
    if (_properties.geoData && _properties.collider)
      gameObject->setCollider();
    if (gameObject->setPosition(position == Ogre::Vector3(0,0,0) ?
				_properties.position : position) == false)
      {
	delete gameObject;
	gameObject = NULL;
	return ;
      }
    gameObject->setRotation(rotation == Ogre::Quaternion::IDENTITY ?
			    _properties.rotation : rotation);
    gameObject->setScale(scale == Ogre::Vector3(1, 1, 1) ?
			 _properties.scale : scale);
    if (!_properties.geoData && _properties.collider)
      gameObject->setCollider();
    return ;
  }

  void PrefabCreator::instantiateLightObject(GameObject *&gameObject)
  {
    return ;
  }

  void PrefabCreator::instantiateCameraObject(GameObject *&gameObject)
  {
    return ;
  }

  void PrefabCreator::instantiateParticuleObject(GameObject *&gameObject)
  {
    return ;
  }

  std::string PrefabCreator::randomiseName(std::string &name)
  {
    std::string newName(name);
    newName += " (";
    for (int i = 0; i < 10; ++i)
      newName += (char)(rand() % 95 + 32);
    newName += ")";
    return (newName);
  }
};
