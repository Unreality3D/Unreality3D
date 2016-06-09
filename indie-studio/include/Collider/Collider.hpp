#ifndef COLLIDER_HPP_
# define COLLIDER_HPP_

# include <iostream>
# include <OgreVector3.h>
# include <OgreEntity.h>
# include "Collider/CollisionTools.h"

namespace Collision
{
  class Collider
  {
  public:
    Collider(Ogre::SceneManager *sceneMgr);
    ~Collider();

    bool	collidesWithEntity(Ogre::Vector3 const& fromPoint,
				   Ogre::Vector3 const& toPoint);
    bool	raycastFromPoint(const Ogre::Vector3 &point,
				 const Ogre::Vector3 &normal,
				 Ogre::Vector3 &result,
				 Ogre::Entity *&target,
				 float &distance);

  private:
    MOC::CollisionTools	*collider;
  };
};

#endif /* !COLLIDER_HPP_ */
