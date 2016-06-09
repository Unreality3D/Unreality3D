//
// Mage.cpp for inde in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio/script/source/mage
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 31 02:07:48 2016 Leo Lafon
// Last update Sun Jun  5 12:28:55 2016 Leo Lafon
//

#include "mage/Mage.hpp"

Mage::Mage(indie::GameObject *&_gameObject)
  : Player(_gameObject) {}

Mage::~Mage() {}

//
// PUBLIC
//

void			Mage::Start()
{
  statsFile = "save/mage.stats";
  autoAttackFile = "MageAutoAttack.prefab";
  Player::Start();
}

void			Mage::Update()
{
  Player::Update();
}

void			Mage::OnCollisionEnter(indie::GameObject *other)
{
  Player::OnCollisionEnter(other);
}
