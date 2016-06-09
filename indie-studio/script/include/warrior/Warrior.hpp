//
// Warrior.hpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio/script/include/warrior
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 31 02:16:08 2016 Leo Lafon
// Last update Sat Jun  4 20:22:14 2016 Leo Lafon
//

#ifndef WARRIOR_HPP_
# define WARRIOR_HPP_

# include "player/Player.hpp"

class Warrior : public Player
{
public:
  Warrior(indie::GameObject *&_gameObject);
  virtual ~Warrior();

  virtual void				Start();
  virtual void				Update();
  virtual void				OnCollisionEnter(indie::GameObject *);
};

# ifdef SCRIPT_WARRIOR
static Warrior *instantiateScript(indie::GameObject *_gameObject)
{
  return new Warrior(_gameObject);
}

extern "C"
{
  Warrior *getScriptInstance(indie::GameObject *_gameObject)
  {
    return instantiateScript(_gameObject);
  }
}
# endif

#endif /* WARRIOR_HPP_ */
