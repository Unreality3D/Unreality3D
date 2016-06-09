//
// Empty.cpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 24 10:28:57 2016 Leo Lafon
// Last update Tue May 31 19:04:01 2016 Leo Lafon
//

#include "OgreObject/Empty.hpp"

namespace OgreObject
{
  Empty::Empty()
  {
    type = MESH;
  }

  Empty::~Empty()
  {
    if (_node != NULL)
      destroyAllOgreObject(_node);
  }

  Empty* Empty::addNode(std::string const &name, Ogre::SceneNode *node,
		     Ogre::Vector3 const & translate,
		     Ogre::Quaternion const & rotate)
  {
    //need exeption for _sceneManager
    if (node == NULL)
      _node = _sceneManager->getRootSceneNode()->createChildSceneNode(name, translate, rotate);
    else
      _node = node->createChildSceneNode(name, translate, rotate);
    return this;
  }

  Empty* Empty::addNode(Ogre::SceneNode *node, Ogre::Vector3 const & translate,
		     Ogre::Quaternion const & rotate)
  {
    //need exeption for _sceneManager
    if (node == NULL)
      _node = _sceneManager->getRootSceneNode()->createChildSceneNode(translate, rotate);
    else
      _node = node->createChildSceneNode(translate, rotate);
    return this;
  }

  Ogre::SceneNode *Empty::getNode()
  {
    return (_node);
  }

  Ogre::Entity		*Empty::getEntity()
  {
    return (NULL);
  }

  RenderObject* Empty::setPosition(Ogre::Vector3 const &pos)
  {
    _node->setPosition(pos);
    return this;
  }

  RenderObject* Empty::setRotation(Ogre::Vector3 const& rot)
  {
    if (rot.x != 0)
      _node->pitch(Ogre::Degree(rot.x));
    if (rot.y != 0)
      _node->yaw(Ogre::Degree(rot.y));
    if (rot.z != 0)
      _node->roll(Ogre::Degree(rot.z));
    return this;
  }

  RenderObject* Empty::setRotation(Ogre::Vector3 const &axis, Ogre::Radian const &angle)
  {
    _node->rotate(axis, angle);
    return this;
  }

  RenderObject* Empty::setRotation(Ogre::Radian const& x, Ogre::Radian const& y, Ogre::Radian const& z)
  {
    Ogre::Radian ref;

    if (x != ref)
      _node->pitch(x);
    if (y != ref)
      _node->yaw(y);
    if (z != ref)
      _node->roll(z);
    return this;
  }

  RenderObject* Empty::setRotation(Ogre::Quaternion const &axis)
  {
    _node->setOrientation(axis);
    return this;
  }

  RenderObject* Empty::setScale(Ogre::Vector3 const &scale)
  {
    _node->setScale(scale);
    return this;
  }

  Ogre::Vector3 const &Empty::getPosition() const
  {
    return (_node->getPosition());
  }

  Ogre::Quaternion const &Empty::getRotation() const
  {
    return (_node->getOrientation());
  }

  Ogre::Vector3 const &Empty::getScale() const
  {
    return (_node->getScale());
  }

  std::string const &Empty::getName() const
  {
    return (_node->getName());
  }

  void Empty::destroyAllOgreObject(Ogre::SceneNode *node)
  {
    Ogre::SceneNode::ObjectIterator itObject = _node->getAttachedObjectIterator();
    Ogre::SceneNode     *tmp;
    int                 child = 0;

    while (itObject.hasMoreElements())
      {
	Ogre::MovableObject *pObject = static_cast<Ogre::MovableObject *>(itObject.getNext());
	_node->getCreator()->destroyMovableObject(pObject);
      }
    while ((tmp = static_cast<Ogre::SceneNode *>(node->getChild(child++))) != NULL)
      destroyAllOgreObject(tmp);
  }
}
