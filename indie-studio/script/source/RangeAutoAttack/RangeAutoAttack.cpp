//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/source/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:53:57 2016 Gandoulf
// Last update Sun Jun  5 22:20:20 2016 Leo Lafon
//

#include "RangeAutoAttack/RangeAutoAttack.hpp"
#include "IndieStudio/GameManager.hpp"
#include "OgreObject/Mesh.hpp"
#include "gobelin/Gobelin.hpp"

RangeAutoAttack::RangeAutoAttack(indie::GameObject *&_gameObject)
  : AScript(_gameObject) {}

RangeAutoAttack::~RangeAutoAttack() {}

void RangeAutoAttack::Start()
{
  _damage = 0;
  _startTime = _timer.getMilliseconds();
}

void RangeAutoAttack::Update()
{
  Ogre::Vector3		oldPos;
  Ogre::Vector3		newPos;

  if (_timer.getMilliseconds() - _startTime >= 5000)
    indie::GameManager::destroy(gameObject);
  oldPos = gameObject->getPosition();
  gameObject->GetComponent<OgreObject::Mesh *>()
    ->getNode()
    ->translate(0, 300 * indie::GameManager::getDeltaTime(), 0, Ogre::Node::TS_LOCAL);
  newPos = gameObject->getPosition();
  gameObject->setPositionF(oldPos);
  if (_playerCol)
    {
      gameObject->setPositionF(newPos);
      _playerCol = false;
    }
  else
    gameObject->setPosition(newPos);
}

void RangeAutoAttack::OnCollisionEnter(indie::GameObject *coll)
{
  std::string tag = coll->getTag();

  if (tag != "player" && tag != "projectile")
    {
      indie::GameManager::destroy(this->gameObject);
    }
  if (tag == "projectile")
    {
      _playerCol = true;
      return ;
    }
}

RangeAutoAttack *RangeAutoAttack::setDamage(int damage)
{
  _damage = damage;
  return this;
}

int RangeAutoAttack::getDamage() const
{
  return _damage;
}

void RangeAutoAttack::Use(std::string str, ...)
{
  va_list list;

  va_start(list, str);
  if (str == "setDamage")
    {
      setDamage(va_arg(list, int));
    }
  va_end(list);
}
