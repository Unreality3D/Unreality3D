//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Mon Jun  6 14:53:18 2016 Gandoulf
//

#ifndef BOMBERMAN_HPP_
# define BOMBERMAN_HPP_

# include "Script/AScript.hpp"
//# include "IndieStudio/IndieParser.hpp"
# include "InputManager/InputManager.hpp"

class BomberMan : public indie::AScript
{
public:
  BomberMan(indie::GameObject *&_gameObject);
  virtual ~BomberMan();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);

private:
  OgreInput::InputManager	*input;
  Ogre::Camera			*cam;
};

# ifdef SCRIPT_BOMBERMAN
static BomberMan *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new BomberMan(_gameObject));
  }

  extern "C"
  {
    BomberMan     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* BOMBERMAN_HPP_ */
