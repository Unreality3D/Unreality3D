//
// Bomb.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/Bomb
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Jun  7 12:06:11 2016 Gandoulf
// Last update Tue Jun  7 12:10:15 2016 Gandoulf
//

#ifndef BOMB_HPP_
# define BOMB_HPP_

# include "Script/AScript.hpp"

class Bomb : public indie::AScript
{
public:
  Bomb(indie::GameObject *&_gameObject);
  virtual ~Bomb();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);

private:
  float	explotion;
};

# ifdef SCRIPT_BOMB
static Bomb *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new Bomb(_gameObject));
  }

  extern "C"
  {
    Bomb     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* BOMB_HPP_ */
