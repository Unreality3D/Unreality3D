//
// Stairs.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/Stairs
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat Jun  4 16:51:53 2016 Gandoulf
// Last update Sat Jun  4 16:52:57 2016 Gandoulf
//

#ifndef STAIRS_HPP_
# define STAIRS_HPP_

# include "Script/AScript.hpp"

class Stairs : public indie::AScript
{
public:
  Stairs(indie::GameObject *&_gameObject);
  virtual ~Stairs();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);
};

# ifdef SCRIPT_STAIRS
static Stairs *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new Stairs(_gameObject));
  }

  extern "C"
  {
    Stairs     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* DEFAULT_HPP_ */
