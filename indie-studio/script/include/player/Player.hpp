#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Script/AScript.hpp"
# include "InputManager/InputManager.hpp"
# include "IndieStudio/Stats.hpp"
# include "IndieStudio/IndieParser.hpp"

# define NEXT_LEVEL_REQUIREMENT (100 * (_level * 2))

class Player : public indie::AScript
{
protected:
  typedef	enum e_Animation
    {
      IDLE	= 0,
      WALK	= 1,
      ATTACK	= 2,
      HIT	= 3,
      DIE	= 4
    }		Animation;

protected:
  OgreInput::InputManager		*_im;
  Ogre::Timer				_timer;
  float					_deltaTime;
  std::vector<Ogre::AnimationState *>	_anims;
  std::vector<std::string>		_skills;
  Animation				_previousAnim;
  Animation				_currentAnim;
  bool					_movement;
  bool					_attack;
  bool					_dead;
  unsigned long				_lastFire;
  indie::Stats				_stats;
  indie::IndieParser			_parser;
  unsigned int				_level;
  unsigned long				_exp;
  std::string				statsFile;
  std::string				autoAttackFile;

protected:
  virtual void				_handleController();
  virtual void				_handleAnimations();
  virtual void				_handleOrientation();
  virtual void				_handleCamera();

public:
  Player(indie::GameObject *&);
  virtual ~Player();

public:
  virtual void				Start();
  virtual void				Update();
  virtual void				OnCollisionEnter(indie::GameObject *);

public:
  Player				*setDeltaTime(float);

  void					takeDamage(int);
  void					death();
  void					addExp(unsigned long);
  void					levelUp();
  indie::Stats const&			getStats() const;
  unsigned int				getLevel() const;
  unsigned long				getExp() const;
};

# ifdef SCRIPT_PLAYER
static Player *instantiateScript(indie::GameObject *_gameObject)
{
  return new Player(_gameObject);
}

extern "C"
{
  Player *getScriptInstance(indie::GameObject *_gameObject)
  {
    return instantiateScript(_gameObject);
  }
}
# endif

#endif /* !PLAYER_HPP_ */
