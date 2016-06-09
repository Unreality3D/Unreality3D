//
// Mage.hpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio/script/include/mage
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 31 02:14:47 2016 Leo Lafon
// Last update Sat Jun  4 19:45:35 2016 Leo Lafon
//

#ifndef MAGE_HPP_
# define MAGE_HPP_

# include "player/Player.hpp"

class Mage : public Player
{
public:
  Mage(indie::GameObject *&_gameObject);
  virtual ~Mage();

  virtual void				Start();
  virtual void				Update();
  virtual void				OnCollisionEnter(indie::GameObject *);
};

# ifdef SCRIPT_MAGE
static Mage *instantiateScript(indie::GameObject *_gameObject)
{
  return new Mage(_gameObject);
}

extern "C"
{
  Mage *getScriptInstance(indie::GameObject *_gameObject)
  {
    return instantiateScript(_gameObject);
  }
}
# endif

#endif /* MAGE_HPP_ */
