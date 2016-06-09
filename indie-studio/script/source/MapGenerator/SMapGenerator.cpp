//
// SMapGenerator.cpp for SMapGenerator in /home/korial/rendu/Tek2/cpp_indie_studio
//
// Made by Korial
// Login   <korial@epitech.net>
//
// Started on  Mon Jun  6 00:53:20 2016 Korial
// Last update Mon Jun  6 12:05:46 2016 Gandoulf
//

#include "MapGenerator/SMapGenerator.hpp"
#include "IndieStudio/GameManager.hpp"
#include "IndieStudio/IndieParser.hpp"

SMapGenerator::SMapGenerator(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{
  indie::IndieParser	parser;

  _map = new Map();
  if (parser.loadFile("indie-studio/save/map.param"))
    {
      std::cout << "ok" << std::endl;
      *_map = Map(parser.stoi(parser.getValue("Room")),
		  Size(parser.stoi(parser.getValue("MsizeX")), parser.stoi(parser.getValue("MsizeY"))),
		  Size(parser.stoi(parser.getValue("RMaxSizeX")), parser.stoi(parser.getValue("RMaxSizeY"))),
		  Size(parser.stoi(parser.getValue("RMinSizeX")), parser.stoi(parser.getValue("RMinSizeY"))));
      _map->set_seed(parser.getValue("Seed"));
    }
  else
    {
      *_map = Map(40, Size(80, 80),
		  Size(15, 15),
		  Size(6, 6));
      _map->set_seed(MAP_SEED);
    }
  _md = new MapDisplayer();
}

SMapGenerator::~SMapGenerator()
{

}

void SMapGenerator::Start()
{
  _map->generate_map();
  _md->displayMap(_map->get_map());
}

void SMapGenerator::Update()
{

}

void SMapGenerator::OnCollisionEnter(indie::GameObject *coll)
{

}

void SMapGenerator::GenerateNewMap()
{
  delete (_md);
  delete (_map);
  std::vector<indie::GameObject *> enemy;
  indie::GameManager::destroy(indie::GameManager::getGameObjects().getObjectsWithTag("stairs")[0]);
  enemy = indie::GameManager::getGameObjects().getObjectsWithTag("enemy");
  for (int i = 0; i < enemy.size(); ++i)
    indie::GameManager::destroy(enemy[i]);
  _map = new Map();
  *_map = Map(40, Size(80, 80),
	     Size(15, 15),
	     Size(6, 6));
  //_map->set_seed();
  _md = new MapDisplayer();
  _map->generate_map();
  _md->displayMap(_map->get_map());
}

std::vector<std::string> const&       SMapGenerator::get_map() const
{
  return (_map->get_map());
}

int	SMapGenerator::getTileSize() const
{
  return MapDisplayer::getTileSize();
}

Ogre::Vector3	SMapGenerator::getMapStart() const
{
  return Ogre::Vector3(_map->get_startY() * MapDisplayer::getTileSize()
		       , 25
		       , _map->get_startX() * MapDisplayer::getTileSize());
}
