#include "Collider.hpp"

namespace Collision
{
  Collider::Collider(Ogre::SceneManager *sceneMgr)
  {
    this->collider = new MOC::CollisionTools(sceneMgr);
  }

  Collider::~Collider()
  {
    delete this->collider;
  }

  bool	Collider::collidesWithEntity(Ogre::Vector3 const& fromPoint,
				     Ogre::Vector3 const& toPoint)
  {
    return (this->collider->collidesWithEntity(fromPoint, toPoint, 1.0f));
  }

  bool	Collider::raycastFromPoint(const Ogre::Vector3 &point,
				   const Ogre::Vector3 &normal,
				   Ogre::Vector3 &result,
				   Ogre::Entity *&target,
				   float &distance)
  {
    return (this->collider->raycastFromPoint(point, normal, result, target, distance));
  }
};
