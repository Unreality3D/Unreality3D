//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Sat Jun  4 19:45:11 2016 Leo Lafon
//

#ifndef ARCHER_HPP_
# define ARCHER_HPP_

# include "player/Player.hpp"

class Archer : public Player
{
public:
  Archer(indie::GameObject *&_gameObject);
  virtual ~Archer();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);
};

# ifdef SCRIPT_ARCHER
static Archer *instantiateScript(indie::GameObject *_gameObject)
{
  return new Archer(_gameObject);
}

extern "C"
{
  Archer *getScriptInstance(indie::GameObject *_gameObject)
  {
    return instantiateScript(_gameObject);
  }
}
# endif

#endif /* ARCHER_HPP_ */
