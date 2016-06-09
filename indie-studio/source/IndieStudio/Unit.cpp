//
// Unit.cpp for indie in /home/lafon_l/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 10 11:50:33 2016 Leo Lafon
// Last update Fri May 27 13:31:11 2016 Gandoulf
//

#include "IndieStudio/Unit.hpp"

namespace indie
{
  Unit::Unit(OgreInput::InputManager * const& im)
    : _level(0), _stats(), _basicStats(), _iManager(im) //, _controller(NULL)
{
  create<OgreObject::Mesh>();
}

  Unit::Unit(OgreInput::InputManager * const& im, std::string const& str)
    : _iManager(im)
  {
    // Parsing
  }

  Unit::~Unit()
  {
    for (unsigned int i = 0; i < _skills.size(); ++i)
      delete _skills[i];
  }

  void			Unit::setLevel(int level)
  {
    _level = level;
  }

  void			Unit::setStats(Stats const& stats)
  {
    _stats = stats;
  }

  void			Unit::setBasicStats(Stats const& basicStats)
  {
    _basicStats = basicStats;
  }

  void			Unit::addSkill(std::string const &confFile)
  {
    return ;
  }

  int const&		Unit::getLevel() const
  {
    return _level;
  }

  Stats const&		Unit::getStats() const
  {
    return _stats;
  }

  Stats const&		Unit::getBasicStats() const
  {
    return _basicStats;
  }

  void			Unit::instantiateSkill(std::string const & prefabFile,
					       Ogre::Vector3 const & position,
					       Ogre::Quaternion const &rotation,
					       Ogre::Vector3 const & scale)
  {

  }

  void			Unit::Start()
  {

  }

  void			Unit::Update() {}
};
