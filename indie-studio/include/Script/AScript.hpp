//
// Script.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/Script
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 15:49:39 2016 Gandoulf
// Last update Tue May 31 17:46:18 2016 Leo Lafon
//

#ifndef ASCRIPT_HPP_
# define ASCRIPT_HPP_

# include <cstdarg>
# include "IndieStudio/GameObject.hpp"

namespace indie
{
  class GameObject;

  class AScript
  {
  public:
    AScript(GameObject *&_gameObject)
    : gameObject(_gameObject)
    {}
    virtual ~AScript()
    {}

    virtual void Start() {}
    virtual void Update() {}
    virtual void OnCollisionEnter(GameObject *) {}
    virtual void Use(std::string str, ...) {}

  protected:
    GameObject	*gameObject;
  };

  /*# ifdef SCRIPT
  static AScript *instantiateScript(GameObject *&_gameObject)
  {
    return (new AScript(_gameObject));
  }

  extern "C"
  {
    AScript	*getScriptInstance(GameObject *&_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
  # endif*/

};

#endif /* SCRIPT_HPP_ */
