//
// GameObject.hpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Thu Jun  2 15:32:14 2016 Maxime Agor
// Last update Mon Jun  6 15:08:58 2016 Gandoulf
//

#ifndef GAMEOBJECT_HPP_
# define GAMEOBJECT_HPP_

# include "OgreObject/RenderObject.hpp"
# include "Collider/Collider.hpp"
# include "Script/AScript.hpp"
# include "Sound/Music.hpp"
# include <typeinfo>

namespace indie
{
  class AScript;

  class GameObject
  {
  protected:
    OgreObject::RenderObject		*_obj;
    Ogre::Vector3			_direction;
    Collision::Collider			*_collider;
    std::vector<indie::AScript *>	_script;
    std::string				_tag;
    std::vector<Sound::Music *>		_sounds;

  public:
    GameObject();
    virtual ~GameObject();

    virtual void			Start();
    virtual void			Update();
    virtual void			OnCollisionEnter(GameObject *gameObject);

    template<class T>
    void				create()
    {
      _obj = new T();
    }

    bool				setPosition(Ogre::Vector3 const&);
    bool				setPositionF(Ogre::Vector3 const&);
    void				setRotation(Ogre::Vector3 const& rot);
    void				setRotation(Ogre::Radian const&,
						    Ogre::Radian const&,
						    Ogre::Radian const& x);
    void				setRotation(Ogre::Vector3 const&, Ogre::Radian const&);
    void				setRotation(Ogre::Quaternion const&);
    void				setScale(Ogre::Vector3 const&);

    void				setTag(std::string const &tag);

    Ogre::Vector3 const&		getPosition() const;
    Ogre::Quaternion const&		getRotation() const;
    Ogre::Vector3 const&		getScale() const;
    std::string const &			getName() const;
    std::string const &			getTag() const;
    std::vector<Sound::Music *>		&getSounds();

    Ogre::SceneNode			*getNode();

    template<class T>
    T					GetComponent()
    {
      return _obj->GetComponent<T>();
    }

    template<class Script>
    Script				*GetScript()
    {
      for (auto it = _script.begin(); it != _script.end(); ++it)
    	{
    	  try {
	    return dynamic_cast<Script *>(*it);
    	  } catch (std::bad_cast) {}
    	}
      return (NULL);
    }

    void	setCollider();
    void	setScript(AScript *script);

  private:
    bool	checkCollision(Ogre::Vector3 const& position);
  };
};

#endif /* !GAMEOBJECT_HPP_ */
