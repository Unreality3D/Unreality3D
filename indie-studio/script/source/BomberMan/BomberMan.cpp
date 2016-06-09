//
// BomberMan.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/BomberMan
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon Jun  6 14:23:17 2016 Gandoulf
// Last update Wed Jun  8 11:45:24 2016 Gandoulf
//

#include "BomberMan/BomberMan.hpp"
#include "IndieStudio/GameManager.hpp"
#include "Players/Players.hpp"
#include "Sound/Music.hpp"

BomberMan::BomberMan(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{

}

BomberMan::~BomberMan()
{

}

void BomberMan::Start()
{
  std::vector<std::string> map =
    {"1111111111",
     "1300000001",
     "1020220201",
     "1000000001",
     "1020220201",
     "1020220201",
     "1000000001",
     "1020220201",
     "1000000041",
     "1111111111"};

  cam = indie::GameManager::getCamera();
  input = indie::GameManager::getInputManager();
  gameObject->getSounds()[0]->setVolume(100);
  gameObject->getSounds()[0]->start();
  cam->setPosition(178, 500, 555);
  for (int i = 0; i < map.size(); ++i)
    {
      for (int j = 0; j < map[i].size(); ++j)
	{
	  indie::GameManager::instantiate("floor.prefab", Ogre::Vector3(i * 40 , 0, j * 40));
	  if (map[i][j] == '1')
	    {
	      indie::GameObject *go;
	      go = indie::GameManager::instantiate("wall.prefab",
						   Ogre::Vector3(i * 40 , 20, j * 40));
	      go->setRotation(Ogre::Vector3(90,0,0));
	    }
	  else if (map[i][j] == '2')
	    {
	      indie::GameObject *go;
	      go = indie::GameManager::instantiate("box.prefab",
						   Ogre::Vector3(i * 40 , 20, j * 40));
	      if (go != NULL)
		go->setRotation(Ogre::Vector3(90,0,0));
	    }
	  else if (map[i][j] == '3')
	    {
	      indie::GameObject *go;
	      go = indie::GameManager::instantiate("players.prefab",
						   Ogre::Vector3(i * 40 , 20, j * 40));
	      if (go != NULL)
		go->GetScript<Players>()->setControl(OIS::KC_Z, OIS::KC_S, OIS::KC_D,
		OIS::KC_Q, OIS::KC_SPACE);
	    }
	  else if (map[i][j] == '4')
	    {
	      indie::GameObject *go;
	      go = indie::GameManager::instantiate("players.prefab",
						   Ogre::Vector3(i * 40 , 20, j * 40));
	      if (go != NULL)
		go->GetScript<Players>()->setControl(OIS::KC_UP, OIS::KC_DOWN, OIS::KC_RIGHT,
						     OIS::KC_LEFT, OIS::KC_SPACE);
	    }
	}
    }
}

void BomberMan::Update()
{
  /*if (input->getKeyDown(OIS::KC_LEFT))
    cam->setPosition(cam->getPosition().x - 1, cam->getPosition().y, cam->getPosition().z);
  if (input->getKeyDown(OIS::KC_RIGHT))
    cam->setPosition(cam->getPosition().x + 1, cam->getPosition().y, cam->getPosition().z);
  if (input->getKeyDown(OIS::KC_UP))
    cam->setPosition(cam->getPosition().x, cam->getPosition().y, cam->getPosition().z - 1);
  if (input->getKeyDown(OIS::KC_DOWN))
  cam->setPosition(cam->getPosition().x, cam->getPosition().y, cam->getPosition().z + 1);*/
}

void BomberMan::OnCollisionEnter(indie::GameObject *)
{

}
