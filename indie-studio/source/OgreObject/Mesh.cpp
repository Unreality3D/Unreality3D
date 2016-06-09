//
// Mesh.cpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 24 10:28:57 2016 Leo Lafon
// Last update Tue May 31 19:02:58 2016 Leo Lafon
//

#include "OgreObject/Mesh.hpp"

namespace OgreObject
{
  Mesh::Mesh()
    : _object(NULL), _node(NULL)
  {
    type = MESH;
  }

  Mesh::~Mesh()
  {
    if (_object != NULL && _node != NULL)
      destroyAllOgreObject(_node);
  }

  Mesh* Mesh::addNode(std::string const &name, Ogre::SceneNode *node,
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

  Mesh* Mesh::addNode(Ogre::SceneNode *node, Ogre::Vector3 const & translate,
		     Ogre::Quaternion const & rotate)
  {
    //need exeption for _sceneManager
    if (node == NULL)
      _node = _sceneManager->getRootSceneNode()->createChildSceneNode(translate, rotate);
    else
      _node = node->createChildSceneNode(translate, rotate);
    return this;
  }

  Mesh* Mesh::addMesh(std::string const &name, std::string const &meshName)
  {
    //need exeption for _sceneManager
    if (_node == NULL)
      addNode();
    _object = _sceneManager->createEntity(name.c_str(), meshName.c_str());
    _node->attachObject(_object);
    return this;
  }

  Ogre::SceneNode *Mesh::getNode()
  {
    return (_node);
  }

  Ogre::Entity		*Mesh::getEntity()
  {
    return _object;
  }

  RenderObject* Mesh::setPosition(Ogre::Vector3 const &pos)
  {
    _node->setPosition(pos);
    return this;
  }

  RenderObject* Mesh::setRotation(Ogre::Vector3 const& rot)
  {
    if (rot.x != 0)
      _node->pitch(Ogre::Degree(rot.x));
    if (rot.y != 0)
      _node->yaw(Ogre::Degree(rot.y));
    if (rot.z != 0)
      _node->roll(Ogre::Degree(rot.z));
    return this;
  }

  RenderObject* Mesh::setRotation(Ogre::Vector3 const &axis, Ogre::Radian const &angle)
  {
    _node->rotate(axis, angle);
    return this;
  }

  RenderObject* Mesh::setRotation(Ogre::Radian const& x, Ogre::Radian const& y, Ogre::Radian const& z)
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

  RenderObject* Mesh::setRotation(Ogre::Quaternion const &axis)
  {
    _node->setOrientation(axis);
    return this;
  }

  RenderObject* Mesh::setScale(Ogre::Vector3 const &scale)
  {
    _node->setScale(scale);
    return this;
  }

  Ogre::Vector3 const &Mesh::getPosition() const
  {
    return (_node->getPosition());
  }

  Ogre::Quaternion const &Mesh::getRotation() const
  {
    return (_node->getOrientation());
  }

  Ogre::Vector3 const &Mesh::getScale() const
  {
    return (_node->getScale());
  }

  std::string const &Mesh::getName() const
  {
    return (_object->getName());
  }

  //private

  void Mesh::destroyAllOgreObject(Ogre::SceneNode *node)
  {
    Ogre::SceneNode::ObjectIterator itObject = _node->getAttachedObjectIterator();
    Ogre::SceneNode	*tmp;
    int			child = 0;

    while (itObject.hasMoreElements())
      {
	Ogre::MovableObject *pObject = static_cast<Ogre::MovableObject *>(itObject.getNext());
	_node->getCreator()->destroyMovableObject(pObject);
      }
    while ((tmp = static_cast<Ogre::SceneNode *>(node->getChild(child++))) != NULL)
      destroyAllOgreObject(tmp);
  }
}









//
//work in progress
//

/*
void Mesh::destroyAllOgreObject(Ogre::SceneNode *node)
{
  //unsigned short	count = 0;
  Ogre::SceneNode::ObjectIterator itObject = _node->getAttachedObjectIterator();
  Ogre::SceneNode	*tmp;
  int			child = 0;

  //std::cout << "o_0 : attachedObj = " << _node->numAttachedObjects() << std::endl;
  while (itObject.hasMoreElements())
    {
      //std::cout << count << std::endl;
      //count += 1;
	Ogre::MovableObject *pObject = static_cast<Ogre::MovableObject *>(itObject.getNext());
	_node->getCreator()->destroyMovableObject(pObject);
      }
  while ((tmp = static_cast<Ogre::SceneNode *>(node->getChild(child++))) != NULL)
    destroyAllOgreObject(tmp);

  // Recurse to child SceneNodes
  //Ogre::SceneNode::ChildNodeIterator itChild = _node->getChildIterator();

    //while (itChild.hasMoreElements())
    //{
    //Ogre::SceneNode *pChildNode = static_cast<Ogre::SceneNode *>(itChild.getNext());
    //destroyAllOgreObject(pChildNode);
    //}
}
*/
