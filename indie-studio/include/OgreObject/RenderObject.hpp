//
// RenderObject.hpp for indie in /home/lafon_l/Documents/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 24 10:31:50 2016 Leo Lafon
// Last update Mon Jun  6 15:12:31 2016 Gandoulf
//

#ifndef RENDEROBJECT_HPP_
# define RENDEROBJECT_HPP_

# include <Ogre.h>

namespace OgreObject
{
  enum ObjType
    {
      UNKNOWN,
      EMPTY,
      MESH,
      LIGHT,
      CAMERA,
      PARTICULE
    };

  class RenderObject
  {
  public:
    RenderObject();
    virtual ~RenderObject();

    template<class object>
    object GetComponent()
    {return (dynamic_cast<object>(this));}

    virtual Ogre::SceneNode *getNode() = 0;

    virtual RenderObject* setPosition(Ogre::Vector3 const &pos) = 0;
    virtual RenderObject* setRotation(Ogre::Vector3 const &pos) = 0;
    virtual RenderObject* setRotation(Ogre::Vector3 const &axis, Ogre::Radian const &angle) = 0;
    virtual RenderObject* setRotation(Ogre::Radian const& x, Ogre::Radian const& y, Ogre::Radian const& z) = 0;
    virtual RenderObject* setRotation(Ogre::Quaternion const &axis) = 0;
    virtual RenderObject* setScale(Ogre::Vector3 const &scale) = 0;

    virtual Ogre::Vector3 const		&getPosition() const = 0;
    virtual Ogre::Quaternion const	&getRotation() const = 0;
    virtual Ogre::Vector3 const		&getScale() const = 0;
    virtual std::string const		&getName() const = 0;

    static void addSceneManager(Ogre::SceneManager *&sceneManager);

  protected:
    ObjType			type;
    static Ogre::SceneManager	*_sceneManager;
  };
};

#endif /* OBJECT_HPP_ */
