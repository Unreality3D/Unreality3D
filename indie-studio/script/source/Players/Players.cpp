//
// Players.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/Players
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Jun  7 10:44:46 2016 Gandoulf
// Last update Wed Jun  8 11:38:31 2016 Gandoulf
//

#include "Players/Players.hpp"
#include "IndieStudio/GameManager.hpp"
#include "OgreObject/Mesh.hpp"

Players::Players(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Players::~Players()
{

}

void Players::Start()
{
  input = indie::GameManager::getInputManager();
  anim = gameObject->GetComponent<OgreObject::Mesh *>()->getEntity()->getAnimationState("Walk");
  anim->setEnabled(true);
  anim->setLoop(true);
  nextBomb = 0;
}

void Players::Update()
{
  anim->addTime(indie::GameManager::getDeltaTime());
  deltaTime = indie::GameManager::getDeltaTime();
  nextBomb += deltaTime;
  if (input->getKeyDown(control[0]))
    gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x, gameObject->getPosition().y,
					  gameObject->getPosition().z - (100 * deltaTime)));
  if (input->getKeyDown(control[1]))
    gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x, gameObject->getPosition().y,
					  gameObject->getPosition().z + (100 * deltaTime)));
  if (input->getKeyDown(control[2]))
    gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x + (100 * deltaTime),
					  gameObject->getPosition().y,
					  gameObject->getPosition().z));
  if (input->getKeyDown(control[3]))
    gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x - (100 * deltaTime),
					  gameObject->getPosition().y,
					  gameObject->getPosition().z));
  if (input->getKeyDown(control[4]) && nextBomb > 1)
    {
      indie::GameManager::instantiate("bomb.prefab", gameObject->getPosition(),
				      gameObject->getRotation(),
				      Ogre::Vector3(5,10,5));
      nextBomb = 0;
    }
  //exit(0);
}

void Players::OnCollisionEnter(indie::GameObject *)
{

}

void Players::setControl(OIS::KeyCode const up, OIS::KeyCode const down,
			 OIS::KeyCode const right, OIS::KeyCode const left,
			 OIS::KeyCode const attack)
{
  control[0] = up;
  control[1] = down;
  control[2] = right;
  control[3] = left;
  control[4] = attack;
}
