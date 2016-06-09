//
// Players.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/Players
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue Jun  7 10:43:46 2016 Gandoulf
// Last update Wed Jun  8 11:35:05 2016 Gandoulf
//

#ifndef PLAYERS_HPP_
# define PLAYERS_HPP_

# include "Script/AScript.hpp"
# include "InputManager/InputManager.hpp"

class Players : public indie::AScript
{
public:
  Players(indie::GameObject *&_gameObject);
  virtual ~Players();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);

  void	setControl(OIS::KeyCode const up, OIS::KeyCode const down,
		   OIS::KeyCode const right, OIS::KeyCode const left,
		   OIS::KeyCode const attack);

private:
  OgreInput::InputManager       *input;
  OIS::KeyCode			control[5];
  float				deltaTime;
  float				nextBomb;
  Ogre::AnimationState		*anim;
};

# ifdef SCRIPT_PLAYERS
static Players *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new Players(_gameObject));
  }

  extern "C"
  {
    Players     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* PLAYERS_HPP_ */
