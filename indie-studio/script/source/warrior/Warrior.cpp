//
// Warrior.cpp for Warrior in /home/korial/rendu/Tek2/cpp_indie_studio
// 
// Made by Korial
// Login   <korial@epitech.net>
// 
// Started on  Mon Jun  6 01:25:37 2016 Korial
// Last update Mon Jun  6 01:25:38 2016 Korial
//

#include "warrior/Warrior.hpp"

Warrior::Warrior(indie::GameObject *&_gameObject)
  : Player(_gameObject) {}

Warrior::~Warrior() {}

//
// PUBLIC
//

void			Warrior::Start()
{
  statsFile = "save/warrior.stats";
  autoAttackFile = "WarriorAutoAttack.prefab";
  Player::Start();
}

void			Warrior::Update()
{
  Player::Update();
}

void			Warrior::OnCollisionEnter(indie::GameObject *other)
{
  Player::OnCollisionEnter(other);
}
