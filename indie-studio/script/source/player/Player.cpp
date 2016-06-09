#include "player/Player.hpp"
#include "IndieStudio/GameManager.hpp"
#include "OgreObject/Mesh.hpp"
#include "RangeAutoAttack/RangeAutoAttack.hpp"
#include "Gui/LifeBar.hpp"
#include "Gui/SampleText.hpp"

Player::Player(indie::GameObject *&_gameObject)
  : AScript(_gameObject) {}

Player::~Player() {}

//
// PUBLIC
//

void		Player::Start()
{
  OgreObject::Mesh *mesh;

  _im = indie::GameManager::getInputManager();
  mesh = gameObject->GetComponent<OgreObject::Mesh *>();
  _anims.push_back(mesh->getEntity()->getAnimationState("Idle"));
  _anims.push_back(mesh->getEntity()->getAnimationState("Walk"));
  _anims.push_back(mesh->getEntity()->getAnimationState("Attack"));
  _anims.push_back(mesh->getEntity()->getAnimationState("Hit"));
  _anims.push_back(mesh->getEntity()->getAnimationState("Die"));
  _anims[DIE]->setLoop(false);

  _currentAnim = IDLE;
  _previousAnim = IDLE;
  _lastFire = 0;
  _dead = false;

  if (_parser.loadFile(statsFile))
    {
      std::cout << "ok" << std::endl;
      std::cout << "ok" << std::endl;
      std::cout << "ok" << std::endl;
      std::cout << "ok" << std::endl;
      _stats.life = _parser.stoi(_parser.getValue("Life"));
      _stats.currentLife = _stats.life;
      _stats.mana = _parser.stoi(_parser.getValue("Mana"));
      _stats.damage = _parser.stoi(_parser.getValue("Damage"));
      _stats.range = _parser.stoi(_parser.getValue("Range"));
      _stats.speed = _parser.stoi(_parser.getValue("Speed"));
      _stats.defense = _parser.stoi(_parser.getValue("Defense"));
      _stats.attackRate = (unsigned)_parser.stol(_parser.getValue("AttackRate"));
      _level = (unsigned)_parser.stoi(_parser.getValue("Level"));
      _exp = (unsigned)_parser.stol(_parser.getValue("Exp"));
      _skills = _parser.stoa(_parser.getValue("Skills"), ';');
    }
  else
    {
      std::cout << "nop" << std::endl;
      std::cout << "nop" << std::endl;
      std::cout << "nop" << std::endl;
      std::cout << "nop" << std::endl;
      _stats.life = 100;
      _stats.currentLife = _stats.life;
      _stats.mana = 10;
      _stats.currentMana = _stats.mana;
      _stats.damage = 10;
      _stats.range = 200;
      _stats.speed = 120;
      _stats.defense = 5;
      _stats.attackRate = 500;
      _level = 1;
      _exp = 0;
      _skills.push_back(autoAttackFile);
    }
}

void			Player::Update()
{
  _deltaTime = indie::GameManager::getDeltaTime();
  _movement = false;
  _attack = false;

  if (_dead)
    {
      death();
      return;
    }

  // For debug purpose
  if (_im->getKeyDown(OIS::KC_P))
    takeDamage(10);

  _handleController();
  _handleCamera();
  _handleOrientation();
  _handleAnimations();
}

void			Player::OnCollisionEnter(indie::GameObject *other)
{
}

Player			*Player::setDeltaTime(float deltaTime)
{
  _deltaTime = deltaTime;
  return this;
}

void			Player::takeDamage(int damage)
{
  _stats.currentLife -= damage;
  if (_stats.currentLife <= 0)
    _dead = true;
  if (gameObject->getSounds().size() >= 2)
    gameObject->getSounds()[1]->start();

  Gui::LifeBar::setLife(_stats.currentLife);
}

void			Player::death()
{
  if (!_anims[DIE]->hasEnded())
    {
      _anims[_previousAnim]->setEnabled(false);
      _anims[_currentAnim]->setEnabled(false);
      _anims[DIE]->setEnabled(true);
      _anims[DIE]->addTime(_deltaTime);
    }
  if (gameObject->getSounds().size() >= 3)
      gameObject->getSounds()[2]->start();
}

void			Player::addExp(unsigned long exp)
{
  _exp += exp;
  if (_exp >= NEXT_LEVEL_REQUIREMENT)
    levelUp();
}

void			Player::levelUp()
{
  _level += 1;
  _stats.damage += 5;
  Gui::SampleText::setText("level", std::to_string(_level));
}

indie::Stats const&	Player::getStats() const
{
  return _stats;
}

unsigned int		Player::getLevel() const
{
  return _level;
}

unsigned long		Player::getExp() const
{
  return _exp;
}

//
// PROTECTED
//

void			Player::_handleController()
{
  Ogre::Vector3 const&	currentPos = gameObject->getPosition();
  indie::GameObject	*autoAttack;

  if (_im->getKeyDown(OIS::KC_Q))
    {
      gameObject->setPosition(Ogre::Vector3(currentPos.x - (_stats.speed * _deltaTime),
					    currentPos.y,
					    currentPos.z));
      _movement = true;
    }
  if (_im->getKeyDown(OIS::KC_D))
    {
      gameObject->setPosition(Ogre::Vector3(currentPos.x + (_stats.speed * _deltaTime),
					    currentPos.y,
					    currentPos.z));
      _movement = true;
    }
  if (_im->getKeyDown(OIS::KC_Z))
    {
      gameObject->setPosition(Ogre::Vector3(currentPos.x,
					    currentPos.y,
					    currentPos.z - (_stats.speed * _deltaTime)));
      _movement = true;
    }
  if (_im->getKeyDown(OIS::KC_S))
    {
      gameObject->setPosition(Ogre::Vector3(currentPos.x,
					    currentPos.y,
					    currentPos.z + (_stats.speed * _deltaTime)));
      _movement = true;
    }
  if (_im->getMouseButtonDown(OIS::MB_Left) &&
      (_timer.getMilliseconds() >= (_lastFire + _stats.attackRate)))
    {
      _attack = true;
      autoAttack = indie::GameManager::instantiate(_skills[0],
						   gameObject->getPosition(),
						   gameObject->getRotation());
      if (autoAttack)
      	{
	  if (gameObject->getSounds().size() >= 1)
	    gameObject->getSounds()[0]->start();
	  autoAttack->GetScript<RangeAutoAttack>()->setDamage(_stats.damage);
	  autoAttack->setRotation(Ogre::Radian(1.57), Ogre::Radian(0), Ogre::Radian(0));
	}
      _lastFire = _timer.getMilliseconds();
    }
}

void			Player::_handleAnimations()
{
  _currentAnim = (_movement || _attack ? (_attack ? ATTACK : WALK) : IDLE);
  if (_previousAnim == ATTACK &&
      (_anims[_previousAnim]->getTimePosition() < _anims[_previousAnim]->getLength() - (_deltaTime * 4)))
    _anims[_previousAnim]->addTime(_deltaTime * 5);
  else
    {
      if (_previousAnim != _currentAnim)
      	_anims[_previousAnim]->setEnabled(false);
      _anims[_currentAnim]->setEnabled(true);
      _anims[_currentAnim]->addTime(_currentAnim == ATTACK ? _deltaTime * 5 : _deltaTime);
      _previousAnim = _currentAnim;
    }
}

void			Player::_handleOrientation()
{
  Ogre::Vector2 cursor2DPos(_im->getMousePosX(), _im->getMousePosY());
  Ogre::Vector2 screenCenter(_im->getMouseState().width / 2,
			     _im->getMouseState().height / 2);
  Ogre::Vector2 playerToMouseVec = cursor2DPos - screenCenter;
  Ogre::Radian playerToMouseRad = Ogre::Math::ATan2(playerToMouseVec.x,playerToMouseVec.y);
  Ogre::Radian nullRad;

  gameObject->GetComponent<OgreObject::Mesh *>()->getNode()->resetOrientation();
  gameObject->setRotation(nullRad, playerToMouseRad, nullRad);
}

void			Player::_handleCamera()
{
  Ogre::Camera *cam = indie::GameManager::getCamera();

  cam->setPosition(gameObject->getPosition().x,
		   cam->getPosition().y,
		   gameObject->getPosition().z + 300);
}
