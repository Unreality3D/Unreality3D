//
// MapDisplayer.cpp for MapDisplay in /home/korial/rendu/Tek2/cpp_indie_studio
//
// Made by Korial
// Login   <korial@epitech.net>
//
// Started on  Mon Jun  6 00:04:13 2016 Korial
// Last update Mon Jun  6 11:41:23 2016 Gandoulf
//

#include "IndieStudio/MapDisplayer.hpp"
#include "IndieStudio/GameManager.hpp"

MapDisplayer::MapDisplayer()
{
  sg = indie::GameManager::getSceneManager()->createStaticGeometry("sg");
  sg->setRegionDimensions(Ogre::Vector3(50000, 5000, 50000));
  sg->setOrigin(Ogre::Vector3(0, 0, 0));
  _funcPtr.push_back(&MapDisplayer::crates_1);
  _funcPtr.push_back(&MapDisplayer::crates_2);
  _funcPtr.push_back(&MapDisplayer::crates_3);
  _funcPtr.push_back(&MapDisplayer::crates_4);
  _funcPtr.push_back(&MapDisplayer::barrel_1);
  _funcPtr.push_back(&MapDisplayer::barrel_2);
  _funcPtr.push_back(&MapDisplayer::barrel_3);
  _funcPtr.push_back(&MapDisplayer::barrel_and_crate_1);
  _funcPtr.push_back(&MapDisplayer::barrel_and_crate_2);
}

MapDisplayer::~MapDisplayer()
{
  std::vector<indie::GameObject*> objs = indie::GameManager::getGameObjects().getObjectsWithTag("notBaked");
  while (objs.size())
    {
      indie::GameManager::destroy(objs.back());
      objs.pop_back();
    }
  indie::GameManager::getSceneManager()->destroyStaticGeometry(sg);
}

std::vector<OgreObject::Mesh *>	const &MapDisplayer::get_map()
{
  return (this->_objs);
}

void		MapDisplayer::new_obj(Ogre::Vector3 _pos, std::string mesh, Ogre::Vector3 scale, Ogre::Vector3 rot, int tileSize, Ogre::Vector3 offset)
{
  static int		id = 0;
  OgreObject::Mesh	*_mesh;
  indie::GameObject	*_go = new indie::GameObject();

  _go->create<OgreObject::Mesh>();
  _mesh = _go->GetComponent<OgreObject::Mesh *>();
  _mesh->addNode(std::string(mesh + std::to_string(id)), NULL, Ogre::Vector3(_pos.x * tileSize + offset.x, _pos.z + offset.z, _pos.y * tileSize + offset.y));
  _mesh->addMesh(std::string("Go_" + mesh + std::to_string(id)), mesh);
  _mesh->setScale(scale);
  _mesh->setRotation(rot);
  if (mesh != "wall.mesh"
      && mesh != "wallSide.mesh"
      && mesh != "pillar.mesh"
      && mesh != "hotel.mesh"
      && mesh != "TrainingDummy4.mesh"
      && mesh != "Grave.mesh")
    {
      _go->setTag("bake");
      sg->addSceneNode(_mesh->getNode());
    }
  else
    _go->setTag("notBaked");
  _objs.push_back(_mesh);
  indie::GameManager::getGameObjects().addObject(_go, indie::GameObjectManager::STATIC);
  ++id;
}

void		MapDisplayer::displayGround(int x, int y)
{
  if (rand() % 100 >= 98)
    new_obj(Ogre::Vector3(x, y, 0), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  else
    new_obj(Ogre::Vector3(x, y, 0), "floor.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
}

void		MapDisplayer::displayAngles(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 35), "wall.mesh", Ogre::Vector3(20, 20, 30), Ogre::Vector3(90, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
}

void		MapDisplayer::displayHorizontalWall(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 30), "wallSide.mesh", Ogre::Vector3(20, 30, 30), Ogre::Vector3(90, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
}

void		MapDisplayer::displayVerticalWall(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 30), "wallSide.mesh", Ogre::Vector3(20, 30, 30), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(0, 0, 0));
}

void		MapDisplayer::displayExit(int x, int y)
{
  indie::GameObject *go = NULL;
  displayGround(x, y);
  std::cout << "fzefzfef" << std::endl;
  std::cout << "fzefzfef" << std::endl;
  std::cout << "fzefzfef" << std::endl;
  std::cout << "fzefzfef" << std::endl;
  std::cout << "fzefzfef" << std::endl;
  go = indie::GameManager::instantiate("stairs.prefab", Ogre::Vector3(x * getTileSize(), 30, y * getTileSize()),
	      Ogre::Quaternion::IDENTITY,
	      Ogre::Vector3(25, 50, 20));
  std::cout << "gameobject = " << go << std::endl;
}

void		MapDisplayer::displayEntry(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x+1, y, 0), "pillar.mesh", Ogre::Vector3(20, 40, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 30), "blueBanner.mesh", Ogre::Vector3(30, 1, 30), Ogre::Vector3(90, 0, 0), getTileSize(), Ogre::Vector3(-12, 9, 0));
  new_obj(Ogre::Vector3(x-1, y, 0), "pillar.mesh", Ogre::Vector3(20, 40, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y, 30), "blueBanner.mesh", Ogre::Vector3(30, 1, 30), Ogre::Vector3(90, 0, 0), getTileSize(), Ogre::Vector3(-12, 9, 0));
}

void		MapDisplayer::displayRandomMisc(int x, int y)
{
  if ((rand() % 100) >= 80)
      (this->*_funcPtr[rand() % _funcPtr.size()])(x, y);
  else
    displayGround(x, y);
}

void		MapDisplayer::crates_1(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 15), "crate.mesh", Ogre::Vector3(8, 5, 5), Ogre::Vector3(0, -28, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
}

void		MapDisplayer::crates_2(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 15), "crate.mesh", Ogre::Vector3(10, 10, 10), Ogre::Vector3(0, -28, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y, 30), "crate.mesh", Ogre::Vector3(5, 5, 5), Ogre::Vector3(0, 30, 0), getTileSize(), Ogre::Vector3(5, 0, 0));
}

void		MapDisplayer::crates_3(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 8), "crate.mesh", Ogre::Vector3(7, 8, 7), Ogre::Vector3(0, -28, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y, 24), "crate.mesh", Ogre::Vector3(8, 8, 8), Ogre::Vector3(0, 20, 0), getTileSize(), Ogre::Vector3(8, 0, 3));
  new_obj(Ogre::Vector3(x+1, y, 8), "crate.mesh", Ogre::Vector3(5, 8, 5), Ogre::Vector3(0, 45, 0), getTileSize(), Ogre::Vector3(-20, 0, 0));
}

void		MapDisplayer::crates_4(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 10), "crate.mesh", Ogre::Vector3(5, 5, 8), Ogre::Vector3(0, -28, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 10), "crate.mesh", Ogre::Vector3(7, 5, 5), Ogre::Vector3(0, 45, 0), getTileSize(), Ogre::Vector3(-15, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 10), "crate.mesh", Ogre::Vector3(6, 7, 5), Ogre::Vector3(0, 60, 0), getTileSize(), Ogre::Vector3(-30, 15, 0));
}

void		MapDisplayer::barrel_1(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 0), "barrel.mesh", Ogre::Vector3(0.8, 0.7, 0.8), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
}

void		MapDisplayer::barrel_2(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 0), "barrel.mesh", Ogre::Vector3(0.8, 0.7, 0.8), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-5, 0, 0));
  new_obj(Ogre::Vector3(x, y, 10), "barrel.mesh", Ogre::Vector3(0.7, 0.6, 0.7), Ogre::Vector3(90, 0, 20), getTileSize(), Ogre::Vector3(15, 0, 0));
}

void		MapDisplayer::barrel_3(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 0), "barrel.mesh", Ogre::Vector3(0.8, 0.7, 0.8), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x, y, 0), "barrel.mesh", Ogre::Vector3(0.8, 0.7, 0.8), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(10, 0, 0));
  new_obj(Ogre::Vector3(x, y, 20), "barrel.mesh", Ogre::Vector3(0.8, 0.7, 0.8), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 3));
}

void		MapDisplayer::barrel_and_crate_1(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 0), "barrel.mesh", Ogre::Vector3(0.8, 0.7, 0.8), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y, 15), "crate.mesh", Ogre::Vector3(8, 5, 5), Ogre::Vector3(0, 45, 0), getTileSize(), Ogre::Vector3(10, 20, 0));
}

void		MapDisplayer::barrel_and_crate_2(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 15), "crate.mesh", Ogre::Vector3(10, 10, 10), Ogre::Vector3(0, -28, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y, 5), "barrel.mesh", Ogre::Vector3(0.5, 0.4, 0.5), Ogre::Vector3(90, 0, 20), getTileSize(), Ogre::Vector3(25, 10, 0));
}

void		MapDisplayer::sacrifice_roomL(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y - 1, 1), "carpet.mesh", Ogre::Vector3(80, 1, 90), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 0), "pillar.mesh", Ogre::Vector3(20, 20, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y, 0), "pillar.mesh", Ogre::Vector3(20, 20, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y - 2, 0), "pillar.mesh", Ogre::Vector3(20, 20, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y - 2, 0), "pillar.mesh", Ogre::Vector3(20, 20, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y + 2, 0), "pillar.mesh", Ogre::Vector3(20, 20, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y + 2, 0), "pillar.mesh", Ogre::Vector3(20, 20, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y - 4, 10), "hotel.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x+1, y+1, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(30, 0, 0));
  new_obj(Ogre::Vector3(x-1, y+1, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-50, 0, 0));
  new_obj(Ogre::Vector3(x+1, y-1, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(30, 0, 0));
  new_obj(Ogre::Vector3(x-1, y-1, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-50, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::sacrifice_roomS(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y-2, 0), "hotel.mesh", Ogre::Vector3(25, 25, 25), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x, y - 1, 1), "carpet.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 90, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x, y, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 90, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x, y+1, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 90, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::butchery_roomS(int x, int y)
{
  new_obj(Ogre::Vector3(x, y, 0), "floorGrid.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 1), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y-1, 1), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y-1, 0), "saw.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 45, 0), getTileSize(), Ogre::Vector3(-10, 10, 0));
  new_obj(Ogre::Vector3(x+1, y-1, 0), "saw.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, -45, 0), getTileSize(), Ogre::Vector3(0, 10, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::butchery_roomL(int x, int y)
{
  new_obj(Ogre::Vector3(x, y, 0), "floorGrid.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 1), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y-1, 0), "saw.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x+1, y-1, 0), "saw.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y-1, 1), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y+1, 0), "saw.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, -10, 0));
  new_obj(Ogre::Vector3(x+1, y+1, 0), "saw.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, -10, 0));
  new_obj(Ogre::Vector3(x-2, y, 1), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+2, y+2, 1), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+2, y, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(30, 0, 0));
  new_obj(Ogre::Vector3(x-2, y, 0), "bench.mesh", Ogre::Vector3(1, 1, 1), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-50, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::chest_room(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x, y, 1), "carpet.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 90, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x, y, 10), "chest.mesh", Ogre::Vector3(0.3, 0.3, 0.3), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3((x+1) * getTileSize(), 20, y * getTileSize()));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3((x-1) * getTileSize(), 20, y * getTileSize()));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, (y+1) * getTileSize()));
}

void		MapDisplayer::grave_roomS(int x, int y)
{
  displayGround(x, y);
    new_obj(Ogre::Vector3(x-1, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
    new_obj(Ogre::Vector3(x+1, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::grave_roomL(int x, int y)
{
  displayGround(x, y);
  new_obj(Ogre::Vector3(x-1, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x-1, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x-3, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x+3, y, 20), "Grave.mesh", Ogre::Vector3(25, 25, 20), Ogre::Vector3(90, 0, 90), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x-4, y-1, 0), "pillar.mesh", Ogre::Vector3(20, 30, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x-4, y+1, 0), "pillar.mesh", Ogre::Vector3(20, 30, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(-10, 0, 0));
  new_obj(Ogre::Vector3(x+4, y-1, 0), "pillar.mesh", Ogre::Vector3(20, 30, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(10, 0, 0));
  new_obj(Ogre::Vector3(x+4, y+1, 0), "pillar.mesh", Ogre::Vector3(20, 30, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(10, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::training_roomS(int x, int y)
{
  new_obj(Ogre::Vector3(x, y, 0), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+2, y, 10), "sword.mesh", Ogre::Vector3(3, 3, 3), Ogre::Vector3(100, -70, -10), getTileSize(), Ogre::Vector3(-15, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::training_roomL(int x, int y)
{
  new_obj(Ogre::Vector3(x, y, 0), "floorBlood.mesh", Ogre::Vector3(20, 1, 20), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y - 2, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y - 2, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+1, y + 2, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-1, y + 2, 0), "TrainingDummy4.mesh", Ogre::Vector3(30, 30, 30), Ogre::Vector3(0, 0, 0), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x-2, y + 2, 10), "sword.mesh", Ogre::Vector3(3, 3, 3), Ogre::Vector3(-100, 70, 10), getTileSize(), Ogre::Vector3(0, 0, 0));
  new_obj(Ogre::Vector3(x+2, y-1, 10), "sword.mesh", Ogre::Vector3(3, 3, 3), Ogre::Vector3(100, -70, -10), getTileSize(), Ogre::Vector3(-15, 0, 0));
  indie::GameManager::instantiate("gobelin.prefab", Ogre::Vector3(x * getTileSize(), 20, y * getTileSize()));
}

void		MapDisplayer::displayMap(std::vector<std::string> const & _map)
{
  for(size_t y = 0; y < _map.size();y++)
    {
      for (size_t x = 0; x < _map[y].size();x++)
	{
	  if (_map[y][x] == 'X' || _map[y][x] == '#')
	    displayAngles(x, y);
	  else if (_map[y][x] == '-')
	    displayHorizontalWall(x, y);
	  else if (_map[y][x] == '|')
	    displayVerticalWall(x, y);
	  else if (_map[y][x] == ' ')
	    displayGround(x, y);
	  else if (_map[y][x] == 'S')
	    displayExit(x, y);
	  else if (_map[y][x] == 'E')
	    displayEntry(x, y);
	  else if (_map[y][x] == 'M')
	    displayRandomMisc(x, y);
	  else if (_map[y][x] == 'H')
	    sacrifice_roomL(x, y);
	  else if (_map[y][x] == 'h')
	    sacrifice_roomS(x, y);
	  else if (_map[y][x] == 'B')
	    butchery_roomL(x, y);
	  else if (_map[y][x] == 'b')
	    butchery_roomS(x, y);
	  else if (_map[y][x] == 'G')
	    grave_roomL(x, y);
	  else if (_map[y][x] == 'g')
	    grave_roomS(x, y);
	  else if (_map[y][x] == 'T')
	    training_roomL(x, y);
	  else if (_map[y][x] == 't')
	    training_roomS(x, y);
	  else if (_map[y][x] == 'C')
	    chest_room(x, y);
	}
    }
  sg->build();
  std::vector<indie::GameObject*> objs = indie::GameManager::getGameObjects().getObjectsWithTag("bake");
  while (objs.size())
    {
      indie::GameManager::destroy(objs.back());
      objs.pop_back();
    }
  return ;
}

int	MapDisplayer::getTileSize()
{
  return 40;
}
