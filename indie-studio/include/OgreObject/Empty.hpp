//
// Empty.hpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 24 10:32:13 2016 Leo Lafon
// Last update Sun May 29 13:37:44 2016 Gandoulf
//

#ifndef EMPTY_HPP_
# define EMPTY_HPP_

# include <string>
# include "OgreObject/RenderObject.hpp"

namespace OgreObject
{
  class Empty : public RenderObject
  {
  public:
    Empty();
    virtual ~Empty();

    Empty* addNode(Ogre::SceneNode *node = NULL,
			  Ogre::Vector3 const & translate = Ogre::Vector3::ZERO,
			  Ogre::Quaternion const & rotate = Ogre::Quaternion::IDENTITY);
    Empty* addNode(std::string const &name, Ogre::SceneNode *node = NULL,
			  Ogre::Vector3 const & translate = Ogre::Vector3::ZERO,
			  Ogre::Quaternion const & rotate = Ogre::Quaternion::IDENTITY);

    virtual Ogre::SceneNode			*getNode();
    virtual Ogre::Entity			*getEntity();

    virtual RenderObject*			setPosition(Ogre::Vector3 const &pos);
    virtual RenderObject*			setRotation(Ogre::Vector3 const& rot);
    virtual RenderObject*			setRotation(Ogre::Vector3 const &axis,
							    Ogre::Radian const &angle);
    virtual RenderObject*			setRotation(Ogre::Radian const& x,
							    Ogre::Radian const& y,
							    Ogre::Radian const& z);
    virtual RenderObject*			setRotation(Ogre::Quaternion const &axis);
    virtual RenderObject*			setScale(Ogre::Vector3 const &scale);

    virtual Ogre::Vector3 const			&getPosition() const;
    virtual Ogre::Quaternion const		&getRotation() const;
    virtual Ogre::Vector3 const			&getScale() const;
    virtual std::string const			&getName() const;

  private:
    void        destroyAllOgreObject(Ogre::SceneNode *node);

  private:
    Ogre::SceneNode	*_node;
  };
};

#endif /* EMPTY_HPP_ */
