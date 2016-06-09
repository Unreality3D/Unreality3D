//
// Priest.cpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio/script/source/priest
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 31 02:09:38 2016 Leo Lafon
// Last update Sun Jun  5 14:20:22 2016 Leo Lafon
//

#include "priest/Priest.hpp"

Priest::Priest(indie::GameObject *&_gameObject)
  : Player(_gameObject) {}

Priest::~Priest() {}

//
// PUBLIC
//

void			Priest::Start()
{
  statsFile = "save/priest.stats";
  autoAttackFile = "PriestAutoAttack.prefab";
  Player::Start();
}

void			Priest::Update()
{
  Player::Update();
}

void			Priest::OnCollisionEnter(indie::GameObject *other)
{
  Player::OnCollisionEnter(other);
}

void			Priest::_handleAnimations()
{
  _currentAnim = (_movement || _attack ? (_attack ? ATTACK : WALK) : IDLE);
  if (_previousAnim == ATTACK &&
      (_anims[_previousAnim]->getTimePosition() < _anims[_previousAnim]->getLength() - (_deltaTime)))
    _anims[_previousAnim]->addTime(_deltaTime);
  else
    {
      if (_previousAnim != _currentAnim)
      	_anims[_previousAnim]->setEnabled(false);
      _anims[_currentAnim]->setEnabled(true);
      _anims[_currentAnim]->addTime(_currentAnim == ATTACK ? _deltaTime : _deltaTime);
      _previousAnim = _currentAnim;
    }
}
