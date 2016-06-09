//
// PrefabCreator.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Wed May 25 14:52:42 2016 Gandoulf
// Last update Mon May 30 13:03:13 2016 Gandoulf
//

#ifndef PREFABCREATOR_HPP_
# define PREFABCREATOR_HPP_

# include "IndieStudio/Properties.hpp"
# include "IndieStudio/IndieParser.hpp"
# include "LibraryLoader/LibraryLoader.hpp"
# include <map>

typedef indie::AScript *(*skillScript)(indie::GameObject *);

namespace indie
{
  class PrefabLoadFileError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error while loading prefabFile, can't instanciate any object";
    }
  };

  class PrefabRenderObjectTypeError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error wrong RenderObjectType";
    }
  };

  class PrefabLibraryLoaderError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error while loading library";
    }
  };

  struct Prefab
  {
    Prefab()
      : _usable(true)
    {}
    bool                        _usable;
    Properties                  _properties;
  };

  class PrefabCreator
  {
  public:
    PrefabCreator();
    ~PrefabCreator();

    GameObject	*instantiate(std::string const &prefabFile,
			     Ogre::Vector3 const & position,
			     Ogre::Quaternion const &rotation = Ogre::Quaternion::IDENTITY,
			     Ogre::Vector3 const & scale = Ogre::Vector3(1, 1, 1));

    void	setRootNode(GameObject *node);

  private:
    void loadFile(std::string const &prefabFile);

    void getRenderObjectType(Properties & _properties, bool & _usable);
    void getName(Properties & _properties);
    void getTag(Properties & _properties);
    void getMesh(Properties & _properties);
    void getScript(Properties & _properties);
    void loadLibrary(Properties & _properties, Memory::LibraryLoader & _library,
		     bool & _usable, int it);
    void getSound(Properties & _properties);
    void getGeoData(Properties & _properties);
    void getCollider(Properties & _properties);
    void getPosition(Properties & _properties);
    void getRotation(Properties & _properties);
    void getScale(Properties & _properties);

    //instantiate private methode

    void instantiateRenderObject(Properties & _properties,
				 GameObject *&gameObject,
				 Ogre::Vector3 const & position,
				 Ogre::Quaternion const &rotation,
				 Ogre::Vector3 const & scale);
    void instantiateUnknowObject(GameObject *&gameObject);
    void instantiateEmptyObject(Properties & _properties,
			       GameObject *&gameObject,
			       Ogre::Vector3 const & position,
			       Ogre::Quaternion const &rotation,
			       Ogre::Vector3 const & scale);
    void instantiateMeshObject(Properties & _properties,
			       GameObject *&gameObject,
			       Ogre::Vector3 const & position,
			       Ogre::Quaternion const &rotation,
			       Ogre::Vector3 const & scale);
    void instantiateLightObject(GameObject *&gameObject);
    void instantiateCameraObject(GameObject *&gameObject);
    void instantiateParticuleObject(GameObject *&gameObject);

    std::string randomiseName(std::string &name);

  private:
    std::map<std::string, Prefab>			_prefab;
    std::map<std::string, Memory::LibraryLoader>	_lib;
    IndieParser						_parser;
    Ogre::SceneNode					*_rootNode;
  };
};

#endif /* PREFABCREATOR_HPP_ */
