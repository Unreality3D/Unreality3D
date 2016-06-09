//
// Deflagration.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Tue Jun  7 16:34:59 2016 Gandoulf
//

#ifndef DEFLAGRATION_HPP_
# define DEFLAGRATION_HPP_

# include "Script/AScript.hpp"

class Deflagration : public indie::AScript
{
public:
  Deflagration(indie::GameObject *&_gameObject);
  virtual ~Deflagration();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);

  void setDirection(Ogre::Vector3 const &dir, float const &speed);

private:
  float		range;
  float		maxRange;
  int		nbDestruction;
  Ogre::Vector3	direction;
  float		speed;
};

# ifdef SCRIPT_DEFLAGRATION
static Deflagration *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new Deflagration(_gameObject));
  }

  extern "C"
  {
    Deflagration     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* DEFLAGRATION_HPP_ */
