//
// PlayList.cpp for PlayList.cpp in /home/labrez_f/test/indie_studio
//
// Made by Florian LABREZE
// Login   <labrez_f@epitech.net>
//
// Started on  Tue May  3 16:51:33 2016 Florian LABREZE
// Last update Wed May  4 10:40:52 2016 Florian LABREZE
//

#include "Sound/PlayList.hpp"

namespace Sound
{
  PlayList::PlayList(std::string const &track, SoundState newState, bool newLoop)
    : state(newState), loop(newLoop)
  {
    this->addTrack(track);
    if (this->state == PLAY)
      {
	this->start();
      }
  }

  PlayList::~PlayList()
  {
    this->stop();
  }

  void          PlayList::start()
  {
    this->state = PLAY;
    if (this->loop == true)
      {
	while (this->loop == true)
	  {
	  }
      }
    else
      {
      }
  }

  void          PlayList::pause()
  {
    this->state = PAUSE;
  }

  void          PlayList::stop()
  {
    this->state = STOP;
  }

  void          PlayList::startLoop()
  {
    this->loop = true;
  }

  void          PlayList::stopLoop()
  {
    this->loop = false;
  }

  void          PlayList::addTrack(std::string const &track)
  {
    std::cout << "New track : " << track << std::endl;
  }

  SoundState    PlayList::getState() const
  {
    return (this->state);
  }

  bool          PlayList::getLoop() const
  {
    return (this->loop);
  }
};
