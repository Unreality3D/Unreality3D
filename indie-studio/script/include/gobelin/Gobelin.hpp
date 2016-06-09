//
// Gobelin.hpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio/script/include/gobelin
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sun Jun  5 23:32:14 2016 Maxime Agor
// Last update Sun Jun  5 23:32:14 2016 Maxime Agor
//

#ifndef GOBELIN_HPP_
# define GOBELIN_HPP_

#include <vector>
#include <string>
# include "Script/AScript.hpp"
# include "IndieStudio/GameManager.hpp"

class Gobelin : public indie::AScript
{
public:
  struct Vector2
  {
    int x;
    int y;

    Vector2(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Vector2(Vector2 const &oth) : x(oth.x), y(oth.y) {}
    bool operator==(Vector2 const &oth) const {return (this->x == oth.x && this->y == oth.y);}
    Vector2 &operator= (Vector2 const &oth) {x = oth.x; y = oth.y; return *this;}
    Vector2 operator+ (Vector2 const &v) const {return Vector2(x + v.x, y + v.y);}
    Vector2 operator- (Vector2 const &v) const {return Vector2(x - v.x, y - v.y);}
  };

public:
  Gobelin(indie::GameObject *&_gameObject);
  virtual ~Gobelin();

  virtual void Start();
  virtual void Update();
  virtual void OnCollisionEnter(indie::GameObject*);
  void takeDamage(int);

private:
  void printPathMap();
  void resetPathMap();
  void updateNeighbours(std::vector<Vector2> &, Vector2, Vector2);
  Vector2 findClosestNeighbour(Vector2, Vector2);

  void feedMap(std::vector<std::string> const &);
  Vector2 pathFind(Vector2 from, Vector2 to);

  Vector2 worldToMapPos(Ogre::Vector3);
  Ogre::Vector3 mapToWorldPos(Vector2, int);

  indie::GameObject *getClosestTarget();

private:
  int					_subdivisions;
  indie::GameObject			*_mapGenerator;
  std::vector<indie::GameObject *>	_players;
  std::vector<std::string>		_map;
  std::vector< std::vector<int> >	_pathMap;
  indie::GameObject			*_target;
  int					_tileSize;
  Vector2				_nextPos;
  Vector2				_nextStep;
  int					_aggro;
  unsigned long				_lastFire;
  Ogre::Timer				_timer;

  // stats
private:
  int					_life;
  int					_speed;
  unsigned long				_fireRate;

};

# ifdef SCRIPT_GOBELIN
static Gobelin *instantiateScript(indie::GameObject *_gameObject)
  {
    return (new Gobelin(_gameObject));
  }

  extern "C"
  {
    Gobelin     *getScriptInstance(indie::GameObject *_gameObject)
    {
      return (instantiateScript(_gameObject));
    }
  }
# endif

std::ostream &operator<< (std::ostream &s, Gobelin::Vector2 const &v)
{
  return s << "Vector2(" << v.x << ", " << v.y << ")";
}


#endif /* GOBELIN_HPP_ */
