//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Mon May 30 14:02:27 2016 Gandoulf
//

#include "default/Default.hpp"
#include "IndieStudio/GameManager.hpp"

Default::Default(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

Default::~Default()
{

}

void Default::Start()
{
  std::cout << "default start" << std::endl;
}

void Default::Update()
{
  gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x + 1,
					gameObject->getPosition().y,
					gameObject->getPosition().z));
}

void Default::OnCollisionEnter(indie::GameObject *coll)
{
  indie::GameManager::destroy(coll, 3000);
}
