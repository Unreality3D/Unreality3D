//
// Default.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/default
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 17:54:52 2016 Gandoulf
// Last update Sun Jun  5 22:01:25 2016 Korial
//

#ifndef SMAPGENERATOR_HPP_
# define SMAPGENERATOR_HPP_

# include "Script/AScript.hpp"
# include "IndieStudio/MapDisplayer.hpp"
# include "MapGenerator/MapGenerator.hpp"

# define NB_ROOM                400
# define MAP_SIZE               4000
# define ROOM_MAX_SIZE          15
# define ROOM_MIN_SIZE          6

# define MAP_SEED "mangue"

class SMapGenerator : public indie::AScript
{
public:
  SMapGenerator(indie::GameObject *&_gameObject);
  virtual ~SMapGenerator();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject *);

  void					GenerateNewMap();
  std::vector<std::string> const&       get_map() const;
  int					getTileSize() const;
  Ogre::Vector3				getMapStart() const;

private:
  MapDisplayer                        *_md;
  Map                                 *_map;
};

# ifdef SCRIPT
static SMapGenerator *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new SMapGenerator(_gameObject));
  }

  extern "C"
  {
    SMapGenerator     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

#endif /* SMAPGENERATOR_HPP_ */
