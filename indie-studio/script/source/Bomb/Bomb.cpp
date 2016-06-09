//
// Bomb.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/Bomb
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Jun  7 12:06:45 2016 Gandoulf
// Last update Wed Jun  8 11:31:05 2016 Gandoulf
//

#include "Bomb/Bomb.hpp"
#include "IndieStudio/GameManager.hpp"
#include "Deflagration/Deflagration.hpp"

Bomb::Bomb(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Bomb::~Bomb()
{

}

void Bomb::Start()
{
  explotion = 0;
}

void Bomb::Update()
{
  explotion += indie::GameManager::getDeltaTime();
  if (explotion >= 2)
    {
      indie::GameObject *go;
      indie::GameManager::destroy(gameObject);
      go = indie::GameManager::instantiate("deflagration.prefab", gameObject->getPosition());
      go->GetScript<Deflagration>()->setDirection(Ogre::Vector3(1,0,0), 100);
      go = indie::GameManager::instantiate("deflagration.prefab", gameObject->getPosition());
      go->GetScript<Deflagration>()->setDirection(Ogre::Vector3(-1,0,0), 100);
      go = indie::GameManager::instantiate("deflagration.prefab", gameObject->getPosition());
      go->GetScript<Deflagration>()->setDirection(Ogre::Vector3(0,0,1), 100);
      go = indie::GameManager::instantiate("deflagration.prefab", gameObject->getPosition());
      go->GetScript<Deflagration>()->setDirection(Ogre::Vector3(0,0,-1), 100);
    }
}

void Bomb::OnCollisionEnter(indie::GameObject *)
{

}
