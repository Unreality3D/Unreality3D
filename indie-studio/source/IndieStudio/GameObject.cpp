#include "IndieStudio/GameObject.hpp"
#include "IndieStudio/GameManager.hpp"

namespace indie
{
  GameObject::GameObject()
    : _obj(NULL), _collider(NULL), _tag("")
  {
    _direction = Ogre::Vector3::ZERO;
  }

  GameObject::~GameObject()
  {
    if (_obj != NULL)
      {
	delete _obj;
      }
    if (_collider != NULL)
      delete _collider;
    if (!_script.empty())
      for (int i = 0; i < _script.size(); ++i)
	{
	  delete _script.back();
	  _script.pop_back();
	}
    for (int i = _sounds.size() - 1; i >= 0; --i)
      delete _sounds[i];
  }

  void			GameObject::Start()
  {
    if (!_script.empty())
      for (int i = 0; i < _script.size(); ++i)
	_script[i]->Start();
  }

  void			GameObject::Update()
  {
    if (!_script.empty())
      for (int i = 0; i < _script.size(); ++i)
	_script[i]->Update();
  }

  void			GameObject::OnCollisionEnter(GameObject *gameObject)
  {
    if (!_script.empty())
      for (unsigned int i = 0; i < _script.size(); ++i)
	{
	  _script[i]->OnCollisionEnter(gameObject);
	}
  }

  // bool                  GameObject::checkCollision(Ogre::Vector3 const& position)
  // {
  //   Ogre::Vector3       result(0, 0, 0);
  //   Ogre::Vector3       selfPosition = getPosition();
  //   Ogre::Vector3       normal(position - selfPosition);
  //   Ogre::Entity        *target;
  //   GameObject          *go = NULL;
  //   float               distanceToColl = 0.0f;
  //   float               distanceToDestination = normal.normalise();

  //   if (!_collider)
  //     return true;
  //   if (_collider->raycastFromPoint(selfPosition, normal, result, target, distanceToColl))
  //     {
  // 	distanceToColl -= 2.5f;
  // 	if (distanceToColl <= distanceToDestination)
  // 	  {
  // 	    go = GameManager::getGameObjects().getObject(target->getName());
  // 	    if (go)
  // 	      {
  // 		OnCollisionEnter(go);
  // 		go->OnCollisionEnter(this);
  // 	      }
  // 	    return false;
  // 	  }
  //     }
  //   return true;
  // }

  /*
  ** Private methode
  */
  bool			GameObject::checkCollision(Ogre::Vector3 const& position)
  {
    Ogre::Vector3	result;
    Ogre::Vector3	selfPosition = getPosition();
    Ogre::Entity	*target = NULL;
    GameObject		*go = NULL;
    float		distanceFromOther;

    if (!_collider || !_collider->collidesWithEntity(selfPosition, position))
      return true;
    _collider->raycastFromPoint(selfPosition,
  				position - selfPosition,
  				result,
  				target,
  				distanceFromOther);
    go = GameManager::getGameObjects().getObject(target->getName());
    if (go)
      {
  	OnCollisionEnter(go);
  	go->OnCollisionEnter(this);
      }
    return false;
  }

  /*
  ** end of Private methode
  */

  bool			GameObject::setPosition(Ogre::Vector3 const& position)
  {
    if (this->checkCollision(position) == true)
      {
	_obj->setPosition(position);
	return (true);
      }
    return (false);
  }

  bool			GameObject::setPositionF(Ogre::Vector3 const& position)
  {
    _obj->setPosition(position);
  }

  void			GameObject::setRotation(Ogre::Radian const& x,
						Ogre::Radian const& y,
						Ogre::Radian const& z)
  {
    _obj->setRotation(x, y, z);
  }

  void			GameObject::setRotation(Ogre::Vector3 const& rot)
  {
    _obj->setRotation(rot);
  }

  void			GameObject::setRotation(Ogre::Vector3 const& rotation,
						Ogre::Radian const& rad)
  {
    _obj->setRotation(rotation, rad);
  }

  void			GameObject::setRotation(Ogre::Quaternion const& rotation)
  {
    _obj->setRotation(rotation);
  }

  void			GameObject::setScale(Ogre::Vector3 const& scale)
  {
    _obj->setScale(scale);
  }

  void GameObject::setTag(std::string const &tag)
  {
    _tag = tag;
  }

  Ogre::Vector3 const&	GameObject::getPosition() const
  {
    return (_obj->getPosition());
  }

  Ogre::Quaternion const&	GameObject::getRotation() const
  {
    return (_obj->getRotation());
  }

  Ogre::Vector3 const&	GameObject::getScale() const
  {
    return (_obj->getScale());
  }

  std::string const & GameObject::getName() const
  {
    return (_obj->getName());
  }

  std::string const & GameObject::getTag() const
  {
    return (_tag);
  }

  Ogre::SceneNode *GameObject::getNode()
  {
    return (_obj->getNode());
  }

  std::vector<Sound::Music *> &GameObject::getSounds()
  {
    return (_sounds);
  }

  void        GameObject::setCollider()
  {
    if (this->_collider != NULL)
      delete this->_collider;
    this->_collider = new Collision::Collider(indie::GameManager::getSceneManager());
  }

  void        GameObject::setScript(AScript *script)
  {
    _script.push_back(script);
  }
};
