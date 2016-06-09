//
// GameObjectManager.hpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Tue May 31 14:16:31 2016 Maxime Agor
// Last update Tue May 31 14:16:32 2016 Maxime Agor
//

#ifndef GAMEOBJECTMANAGER_HPP_
# define GAMEOBJECTMANAGER_HPP_

# include <map>
# include <vector>
# include <iostream>
# include "IndieStudio/GameObject.hpp"

namespace indie
{
  class GameObjectManager
  {
  public:
    typedef	enum e_ObjType
      {
	STATIC,
	DYNAMIC
      }		ObjType;

  public:
    GameObjectManager();
    GameObjectManager(GameObjectManager &newMap);
    ~GameObjectManager();

    GameObjectManager			*addObject(GameObject *newObject, ObjType objType);
    bool				deleteObject(std::string const& nameObject);
    GameObject				*getObject(std::string const& nameObject);
    std::map<std::string, GameObject *> &getStaticObjects();
    std::map<std::string, GameObject *> &getDynamicObjects();
    std::vector<GameObject *>		getObjectsWithTag(std::string const &tag);

  private:
    std::map<std::string, GameObject *> _staticObjects;
    std::map<std::string, GameObject *> _dynamicObjects;
  };
};

#endif /* !GAMEOBJECTMANAGER_HPP_ */
