//
// Priest.hpp for inie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio/script/include/priest
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 31 02:15:25 2016 Leo Lafon
// Last update Sat Jun  4 19:45:53 2016 Leo Lafon
//

#ifndef PRIEST_HPP_
# define PRIEST_HPP_

# include "player/Player.hpp"

class Priest : public Player
{
protected:
  virtual void				_handleAnimations();

public:
  Priest(indie::GameObject *&_gameObject);
  virtual ~Priest();

  virtual void				Start();
  virtual void				Update();
  virtual void				OnCollisionEnter(indie::GameObject *);
};

# ifdef SCRIPT_PRIEST
static Priest *instantiateScript(indie::GameObject *_gameObject)
{
  return new Priest(_gameObject);
}

extern "C"
{
  Priest *getScriptInstance(indie::GameObject *_gameObject)
  {
    return instantiateScript(_gameObject);
  }
}
# endif

#endif /* PRIEST_HPP_ */
