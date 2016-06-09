//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Sun Jun  5 20:03:56 2016 Leo Lafon
//

#ifndef RANGEAUTOATTACK_HPP_
# define RANGEAUTOATTACK_HPP_

# include "Script/AScript.hpp"

class RangeAutoAttack : public indie::AScript
{
protected:
  int			_damage;
  Ogre::Timer		_timer;
  unsigned long		_startTime;
  bool			_playerCol;

public:
  RangeAutoAttack(indie::GameObject *&_gameObject);
  virtual ~RangeAutoAttack();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);
  virtual void Use(std::string str, ...);

  RangeAutoAttack	*setDamage(int damage);
  int			getDamage() const;
};

# ifdef SCRIPT_RANGEAUTOATTACK
static RangeAutoAttack *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new RangeAutoAttack(_gameObject));
  }

  extern "C"
  {
    RangeAutoAttack     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* RANGEAUTOATTACK_HPP_ */
