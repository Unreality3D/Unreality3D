//
// MapDisplayer.hpp for  in /home/agor_m/epitech/cpp_indie_studio/indie-studio
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Tue May 31 14:15:38 2016 Maxime Agor
// Last update Sun Jun  5 19:07:05 2016 Korial
//

#ifndef MAPDISPLAYER_HPP_
# define MAPDISPLAYER_HPP_

#include <iostream>
#include <vector>
#include "GameObject.hpp"
#include "OgreObject/Mesh.hpp"
#include <OgreStaticGeometry.h>

class MapDisplayer
{
  typedef void (MapDisplayer::*MemFuncPtr)(int, int);

public:
  MapDisplayer();
  ~MapDisplayer();

private:
  std::vector<OgreObject::Mesh *>		_objs;
  std::vector<MemFuncPtr>			_funcPtr;
  Ogre::StaticGeometry				*sg;

public:
  static int				getTileSize();
  std::vector<OgreObject::Mesh *> const	&get_map();
  void					displayMap(std::vector<std::string> const &);

private:
  void			new_obj(Ogre::Vector3, std::string, Ogre::Vector3, Ogre::Vector3, int, Ogre::Vector3);
  void            displayAngles(int, int);
  void            displayHorizontalWall(int, int);
  void            displayVerticalWall(int, int);
  void            displayGround(int, int);
  void            displayExit(int, int);
  void            displayEntry(int, int);
  void		  displayRandomMisc(int, int);

  void		  crates_1(int, int);
  void		  crates_2(int, int);
  void		  crates_3(int, int);
  void		  crates_4(int, int);
  void		  chest(int, int);
  void		  barrel_1(int, int);
  void		  barrel_2(int, int);
  void		  barrel_3(int, int);
  void		  barrel_and_crate_1(int, int);
  void		  barrel_and_crate_2(int, int);

  void		  sacrifice_roomL(int, int);
  void		  sacrifice_roomS(int, int);
  void		  butchery_roomL(int, int);
  void		  butchery_roomS(int, int);
  void		  chest_room(int, int);
  void		  grave_roomS(int, int);
  void		  grave_roomL(int, int);
  void		  training_roomL(int, int);
  void		  training_roomS(int, int);

};

#endif /*!MAPDISPLAYER_HPP_*/
