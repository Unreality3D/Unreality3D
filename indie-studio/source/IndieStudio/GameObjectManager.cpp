//
// GameObjectManager.cpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Tue May 31 14:15:09 2016 Maxime Agor
// Last update Tue May 31 14:15:13 2016 Maxime Agor
//

#include <algorithm>

#include "IndieStudio/GameObjectManager.hpp"

namespace indie
{
  GameObjectManager::GameObjectManager() {}

  GameObjectManager::GameObjectManager(GameObjectManager &newMap)
  {
    _staticObjects = newMap.getStaticObjects();
    _dynamicObjects = newMap.getDynamicObjects();
  }

  GameObjectManager::~GameObjectManager() {}

  GameObjectManager			*GameObjectManager::addObject(GameObject *newObject,
								      ObjType type)
  {
    if (type == STATIC)
      _staticObjects[newObject->getName()] = newObject;
    else if (type == DYNAMIC)
      {
	_dynamicObjects[newObject->getName()] = newObject;
	newObject->Start();
      }
    return this;
  }

  bool					GameObjectManager::deleteObject(std::string const& nameObject)
  {
    if (!_dynamicObjects.erase(nameObject))
      if (!_staticObjects.erase(nameObject))
	return false;
    return true;
  }

  GameObject				*GameObjectManager::getObject(std::string const& nameObject)
  {
    std::map<std::string, indie::GameObject *>::iterator	wanted;

    wanted = _dynamicObjects.find(nameObject);
    if (wanted == _dynamicObjects.end())
      wanted = _staticObjects.find(nameObject);
    return wanted == _staticObjects.end() ? NULL : wanted->second;
  }

  std::map<std::string, GameObject *>	&GameObjectManager::getStaticObjects()
  {
    return _staticObjects;
  }

  std::map<std::string, GameObject *>	&GameObjectManager::getDynamicObjects()
  {
    return _dynamicObjects;
  }

  std::vector <GameObject *>	GameObjectManager::getObjectsWithTag(std::string const &tag)
  {
    std::vector<GameObject *> objects;

    for (auto it = _staticObjects.begin(); it != _staticObjects.end(); ++it)
      {
	if ((*it).second->getTag() == tag)
	  objects.push_back((*it).second);

      }
    for (auto it = _dynamicObjects.begin(); it != _dynamicObjects.end(); ++it)
      {
	if ((*it).second->getTag() == tag)
	  objects.push_back((*it).second);

      }

    return objects;
  }

};
