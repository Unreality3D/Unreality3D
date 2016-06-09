//
// Gobelin.cpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio/script/source/gobelin
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Sun Jun  5 23:32:03 2016 Maxime Agor
// Last update Sun Jun  5 23:34:33 2016 Maxime Agor
//

#include "gobelin/Gobelin.hpp"
#include "MapGenerator/SMapGenerator.hpp"
#include "player/Player.hpp"
#include "RangeAutoAttack/RangeAutoAttack.hpp"

#define GOBELIN_PATHF_MASK (1<<15)
#define GOBELIN_PATHF_INFINITY (std::numeric_limits<int>::max() & ~GOBELIN_PATHF_MASK)

Gobelin::Gobelin(indie::GameObject *&_gameObject)
  : AScript(_gameObject)
{
  _subdivisions = 2;
  _aggro = 20;
  _life = 100;
  _speed = 150;
  _fireRate = 500;
}

Gobelin::~Gobelin()
{

}

// todo : find the closest one
indie::GameObject *Gobelin::getClosestTarget()
{
  return _players[0];
}

void Gobelin::Start()
{
  _players = indie::GameManager::getGameObjects().getObjectsWithTag("player");
  auto gm = indie::GameManager::getGameObjects().getObjectsWithTag("gameManager");
  _nextStep = Vector2(0, 0);
  if (gm.size())
    {
      _mapGenerator = gm[0];
      if (_mapGenerator->GetScript<SMapGenerator>() != NULL)
	{
	  feedMap((_mapGenerator->GetScript<SMapGenerator>()->get_map()));
	  _tileSize = _mapGenerator->GetScript<SMapGenerator>()->getTileSize();
	}
      //printPathMap();
    }
  _nextPos = worldToMapPos(gameObject->getPosition());
  _lastFire = _timer.getMilliseconds();
}

void Gobelin::Update()
{
  if (!_players.size())
    _players = indie::GameManager::getGameObjects().getObjectsWithTag("player");
  if (!_players.size())
    return ;

  _target = getClosestTarget();

  Vector2 nextStep = _nextStep;
  if (_nextPos == worldToMapPos(gameObject->getPosition()))
    {
      try {
	nextStep = pathFind(worldToMapPos(gameObject->getPosition()),
			    worldToMapPos(_target->getPosition()));
      } catch (...)
	{
	  nextStep = Vector2(0, 0);
	}
      _nextPos = worldToMapPos(gameObject->getPosition()) + nextStep;
      _nextStep = nextStep;
    }
  else
    nextStep = _nextStep;

  if (!(gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x + nextStep.x *
					      _speed * indie::GameManager::getDeltaTime(),
					      gameObject->getPosition().y,
					      gameObject->getPosition().z + nextStep.y *
					      _speed * indie::GameManager::getDeltaTime()))))
    {
      gameObject->setPosition(Ogre::Vector3(gameObject->getPosition().x - nextStep.x *
					    _speed * indie::GameManager::getDeltaTime(),
					    gameObject->getPosition().y,
					    gameObject->getPosition().z - nextStep.y *
					    _speed * indie::GameManager::getDeltaTime()));
      _nextPos = worldToMapPos(gameObject->getPosition());
    }
}

void Gobelin::feedMap(std::vector<std::string> const &map)
{
  std::vector<int> line;
  int j, k, l;

  _map = map;

  // go through y
  for (auto it = _map.begin(); it != _map.end(); ++it)
    {
      line = std::vector<int>();
      // go through x
      for (j = 0; j < (*it).length(); ++j)
	{
	  // increase the x resolution
	  for (l = 0; l < _subdivisions; ++l)
	    {
	      switch ((*it)[j])
		{
		case '.':
		case '-':
		case 'X':
		case '|':
		  line.push_back(-1);
		  break;
		default :
		  line.push_back(GOBELIN_PATHF_INFINITY);
		  break;
		}
	    }
	}
      // increase the y resolution
      for (k = 0; k < _subdivisions; ++k)
	{
	  _pathMap.push_back(line);
	}
    }
}


void Gobelin::printPathMap()
{
  // debug
  for (auto it = _pathMap.begin(); it != _pathMap.end(); ++it)
    {
      for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
  {
    std::cout << (*it2 < 0 ? 'X' : (*it2 >= GOBELIN_PATHF_INFINITY ? '.' : ' '));
  }
      std::cout << std::endl;
    }
}

void Gobelin::resetPathMap()
{
  for (auto it = _pathMap.begin(); it != _pathMap.end(); ++it)
    {
      for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
  {
    if (*it2 >= 0)
      *it2 = GOBELIN_PATHF_INFINITY;
    else
      *it2 = -1;
  }
    }
}

void Gobelin::updateNeighbours(std::vector<Gobelin::Vector2> &visibleNodes,
			       Gobelin::Vector2 pos, Gobelin::Vector2 mapSize)
{
  int myPosValue = _pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK;
  if (pos.y > 0)
    if (!(_pathMap[pos.y - 1][pos.x] & GOBELIN_PATHF_MASK) &&
	_pathMap[pos.y - 1][pos.x] > myPosValue)
      {
	if (_pathMap[pos.y - 1][pos.x] >= GOBELIN_PATHF_INFINITY)
	  visibleNodes.push_back(Vector2(pos.x, pos.y - 1));
	_pathMap[pos.y - 1][pos.x] = (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) + 1;
      }
  if (pos.y < mapSize.y - 1)
    if (!(_pathMap[pos.y + 1][pos.x] & GOBELIN_PATHF_MASK) &&
	_pathMap[pos.y + 1][pos.x] > myPosValue)
      {
	if (_pathMap[pos.y + 1][pos.x] >= GOBELIN_PATHF_INFINITY)
	  visibleNodes.push_back(Vector2(pos.x, pos.y + 1));
	_pathMap[pos.y + 1][pos.x] = (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) + 1;
      }
  if (pos.x > 0)
    if (!(_pathMap[pos.y][pos.x - 1] & GOBELIN_PATHF_MASK) &&
	_pathMap[pos.y][pos.x - 1] > myPosValue)
      {
	if (_pathMap[pos.y][pos.x - 1] >= GOBELIN_PATHF_INFINITY)
	  visibleNodes.push_back(Vector2(pos.x - 1, pos.y));
	_pathMap[pos.y][pos.x - 1] = (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) + 1;
      }
  if (pos.x < mapSize.x - 1)
    if (!(_pathMap[pos.y][pos.x + 1] & GOBELIN_PATHF_MASK) &&
	_pathMap[pos.y][pos.x + 1] > myPosValue)
      {
	if (_pathMap[pos.y][pos.x + 1] >= GOBELIN_PATHF_INFINITY)
	  visibleNodes.push_back(Vector2(pos.x + 1, pos.y));
	_pathMap[pos.y][pos.x + 1] = (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) + 1;
      }
}

Gobelin::Vector2 Gobelin::findClosestNeighbour(Gobelin::Vector2 pos, Gobelin::Vector2 mapSize)
{
  if (pos.y > 0)
    if ((_pathMap[pos.y - 1][pos.x] & ~GOBELIN_PATHF_MASK) == (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) - 1)
      return Vector2(0, -1);
  if (pos.y < mapSize.y - 1)
    if ((_pathMap[pos.y + 1][pos.x] & ~GOBELIN_PATHF_MASK) == (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) - 1)
      return Vector2(0, 1);
  if (pos.x > 0)
    if ((_pathMap[pos.y][pos.x - 1] & ~GOBELIN_PATHF_MASK) == (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) - 1)
      return Vector2(-1, 0);
  if (pos.x < mapSize.x - 1)
    if ((_pathMap[pos.y][pos.x + 1] & ~GOBELIN_PATHF_MASK) == (_pathMap[pos.y][pos.x] & ~GOBELIN_PATHF_MASK) - 1)
      return Vector2(1, 0);
  return (Vector2(0, 0));
}

static inline int ABS(int a)
{
  return (a > 0 ? a : -a);
}

static bool compTiles(std::vector <std::vector <int> > &map, Gobelin::Vector2 const &to,
		      Gobelin::Vector2 const &a, Gobelin::Vector2 const &b)
{
  if (map[b.y][b.x] < 0)
    return true;
  else if (map[a.y][a.x] < 0)
    return false;
  else
    return ((map[a.y][a.x] & ~GOBELIN_PATHF_MASK) + ABS((a-to).x) + ABS((a-to).y) <
	    (map[b.y][b.x] & ~GOBELIN_PATHF_MASK) + ABS((b-to).x) + ABS((b-to).y) );
}

Gobelin::Vector2 Gobelin::pathFind(Gobelin::Vector2 from, Gobelin::Vector2 to)
{
  Vector2 min;
  int x, y;
  std::vector <Vector2> visibleNodes;

  Vector2 tmp = to - from;
  if (tmp.x * tmp.x + tmp.y * tmp.y >= _aggro * _aggro)
    return Vector2(0, 0);

  resetPathMap();
  visibleNodes.push_back(to);
  _pathMap[to.y][to.x] = 0;
  if (_pathMap[from.y][from.x] < 0)
    return Vector2(-_nextStep.x, -_nextStep.y);
  _pathMap[from.y][from.x] = GOBELIN_PATHF_INFINITY;

  while (_pathMap[from.y][from.x] >= GOBELIN_PATHF_INFINITY)
    {
      // find the closest node
      auto minNode = std::min_element(visibleNodes.begin(), visibleNodes.end(),
				 [&](Vector2 const &a, Vector2 const &b)
				      {return compTiles(_pathMap, from, a, b);});

      // no path possible
      if (minNode == visibleNodes.end())
	throw std::exception();
      min = *minNode;

      // lock the shortest
      _pathMap[min.y][min.x] |= GOBELIN_PATHF_MASK;
      visibleNodes.erase(minNode);
      updateNeighbours(visibleNodes, min, Vector2(_pathMap[min.y].size(), _pathMap.size()));
    }
  return findClosestNeighbour(min, Vector2(_pathMap[min.y].size(), _pathMap.size()));
}

Gobelin::Vector2 Gobelin::worldToMapPos(Ogre::Vector3 wPos)
{
  return Gobelin::Vector2((wPos.x / (float)(_tileSize / _subdivisions)) > 0 ?
			  (wPos.x / (float)(_tileSize / _subdivisions)) : 0,
			  (wPos.z / (float)(_tileSize / _subdivisions)) > 0 ?
			  (wPos.z / (float)(_tileSize / _subdivisions)) : 0);
}

Ogre::Vector3 Gobelin::mapToWorldPos(Gobelin::Vector2 mPos, int y)
{
  return Ogre::Vector3(mPos.x * (float)(_tileSize / _subdivisions),
		       y,
		       mPos.y * (float)(_tileSize / _subdivisions));
}

void Gobelin::takeDamage(int life)
{
  _life -= life;
  if (gameObject->getSounds().size() >= 1)
    gameObject->getSounds()[0]->start();
  if (_life <= 0)
    {
      if (gameObject->getSounds().size() >= 2)
	gameObject->getSounds()[1]->start();
      indie::GameManager::destroy(gameObject);
      for (auto it = _players.begin(); it != _players.end(); ++it)
	{
	  (*it)->GetScript<Player>()->addExp(100);
	}
    }
}

void Gobelin::OnCollisionEnter(indie::GameObject *coll)
{
  if (coll->getTag() == "projectile")
    {
      takeDamage(coll->GetScript<RangeAutoAttack>()->getDamage());
    }

  else if (coll->getTag() == "player")
    {
      if (_timer.getMilliseconds() >= _lastFire + _fireRate)
	{
	  std::cout << "outch" << std::endl;
	  coll->GetScript<Player>()->takeDamage(10);
	  _lastFire = _timer.getMilliseconds();
	}
    }
}
