//
// Deflagration.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/Deflagration
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Jun  7 16:16:29 2016 Gandoulf
// Last update Tue Jun  7 16:46:21 2016 Gandoulf
//

#include "Deflagration/Deflagration.hpp"
#include "IndieStudio/GameManager.hpp"

Deflagration::Deflagration(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Deflagration::~Deflagration()
{

}

void Deflagration::Start()
{
  range = 0;
  maxRange = 120;
  nbDestruction = 2;
}

void Deflagration::Update()
{
  float	deltaTime = indie::GameManager::getDeltaTime();
  if (range >= maxRange)
    indie::GameManager::destroy(gameObject);
  range += speed * deltaTime;
  gameObject->setPosition(Ogre::Vector3
			  (gameObject->getPosition().x + (direction.x * speed * deltaTime),
			   gameObject->getPosition().y + (direction.y * speed * deltaTime),
			   gameObject->getPosition().z + (direction.z * speed * deltaTime)));
}

void Deflagration::OnCollisionEnter(indie::GameObject *coll)
{
  if (coll->getTag() == "box" || coll->getTag() == "players" || coll->getTag() == "deflagration")
    {
      nbDestruction -= 1;
      if (nbDestruction <= 0)
	indie::GameManager::destroy(gameObject);
      indie::GameManager::destroy(coll);
    }
  else
    indie::GameManager::destroy(gameObject);
}

void Deflagration::setDirection(Ogre::Vector3 const &dir, float const &_speed)
{
  direction = dir;
  speed = _speed;
}
