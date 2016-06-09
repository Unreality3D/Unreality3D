//
// Stats.cpp for indie in /home/lafon_l/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 10 12:11:25 2016 Leo Lafon
// Last update Fri May 20 16:29:41 2016 Gandoulf
//

#include "IndieStudio/Stats.hpp"

namespace indie
{
  Stats::Stats()
    : life(0), currentLife(0), mana(0), currentMana(0), damage(0),
      range(0), speed(0), defense(0), attackRate(0) {}

  Stats::Stats(Stats const& other)
  {
    *this = other;
  }

  Stats::~Stats() {}

  void		Stats::operator=(Stats const& other)
  {
    if (this != &other)
      {
	life = other.life;
	currentLife = other.currentLife;
	mana = other.mana;
	currentMana = other.currentMana;
	damage = other.damage;
	range = other.range;
	speed = other.speed;
	defense = other.defense;
	attackRate = other.attackRate;
      }
  }
};
