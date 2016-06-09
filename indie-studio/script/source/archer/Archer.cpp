//
// Archer.cpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Thu Jun  2 15:31:28 2016 Maxime Agor
// Last update Sun Jun  5 12:23:56 2016 Leo Lafon
//

#include "archer/Archer.hpp"

Archer::Archer(indie::GameObject *&_gameObject)
  : Player(_gameObject) {}

Archer::~Archer() {}

//
// PUBLIC
//

void			Archer::Start()
{
  statsFile = "save/archer.stats";
  autoAttackFile = "ArcherAutoAttack.prefab";
  Player::Start();
}

void			Archer::Update()
{
  Player::Update();
}

void			Archer::OnCollisionEnter(indie::GameObject *other)
{
  Player::OnCollisionEnter(other);
}
