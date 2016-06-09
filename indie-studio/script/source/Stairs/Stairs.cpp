//
// Stairs.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/Stairs
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat Jun  4 16:53:31 2016 Gandoulf
// Last update Mon Jun  6 11:53:19 2016 Gandoulf
//

#include "Stairs/Stairs.hpp"
#include "IndieStudio/GameManager.hpp"
#include "Gauntlet/Gauntlet.hpp"

Stairs::Stairs(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Stairs::~Stairs()
{

}

void Stairs::Start()
{

}

void Stairs::Update()
{
}

void Stairs::OnCollisionEnter(indie::GameObject *coll)
{
  if (coll->getTag() == "player")
    {
      std::vector<indie::GameObject *> go;
      go = indie::GameManager::getGameObjects().getObjectsWithTag("game");
      std::cout << coll->getPosition() << std::endl;
      if (go.size() == 1)
	  if (go[0]->GetScript<Gauntlet>() != NULL)
	    go[0]->GetScript<Gauntlet>()->newMap();
    }
}
