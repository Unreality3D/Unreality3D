//
// SkillProperties.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/IndieStudio
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Mon May 23 18:29:15 2016 Gandoulf
// Last update Sun Jun  5 17:39:49 2016 Gandoulf
//

#ifndef SKILLPROPERTIES_HPP_
# define SKILLPROPERTIES_HPP_

# include <string>
# include "Script/AScript.hpp"
# include "IndieStudio/GameObject.hpp"

namespace indie
{
  struct Properties
  {
    Properties()
    {
      renderObjectType = 1;
      name = "Unknow";
      tag = "Unknow";
      mesh = "";
      geoData = false;
      collider = true;
      position = Ogre::Vector3(0, 0, 0);
      rotation = Ogre::Quaternion::IDENTITY;
      scale = Ogre::Vector3(1, 1, 1);
    }

    ~Properties()
    {}

    Properties &operator=(Properties const &SP)
    {
      renderObjectType = SP.renderObjectType;
      name = SP.name;
      tag = SP.tag;
      mesh = SP.mesh;
      script = SP.script;
      sound = SP.sound;
      geoData = SP.geoData;
      collider = SP.collider;
      position = SP.position;
      rotation = SP.rotation;
      scale = SP.scale;
      skillFunction = SP.skillFunction;
      return (*this);
    }

    int				renderObjectType;
    std::string			name;
    std::string			tag;
    std::string			mesh;
    std::vector<std::string>	script;
    std::vector<std::string>	sound;
    bool			geoData;
    bool			collider;
    Ogre::Vector3		position;
    Ogre::Quaternion		rotation;
    Ogre::Vector3		scale;

    std::vector<AScript *(*)(GameObject *)> skillFunction;
  };
};

#endif /* SKILLPROPERTIES_HPP_ */
