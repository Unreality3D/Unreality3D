//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Wed Jun  1 13:13:41 2016 Leo Lafon
//

#ifndef DEFAULT_HPP_
# define DEFAULT_HPP_

# include "Script/AScript.hpp"

class Default : public indie::AScript
{
public:
  Default(indie::GameObject *&_gameObject);
  virtual ~Default();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);
};

# ifdef SCRIPT_DEFAULT
static Default *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new Default(_gameObject));
  }

  extern "C"
  {
    Default     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* DEFAULT_HPP_ */
