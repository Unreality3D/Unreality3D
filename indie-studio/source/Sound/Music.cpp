//
// Music.cpp for Music.cpp in /home/labrez_f/test/indie_studio
//
// Made by Florian LABREZE
// Login   <labrez_f@epitech.net>
//
// Started on  Tue May  3 16:14:24 2016 Florian LABREZE
// Last update Fri May 27 17:56:40 2016 Florian LABREZE
//

/*
*******************************
**                            *
** This use PortAUdio plugin. *
**                            *
*******************************
*/

#include "Sound/Music.hpp"
#include "SFML/Audio.hpp"

namespace Sound
{
  Music::Music(std::string const &newTrack, SoundType newType, SoundState newState, bool newLoop)
    : track(newTrack), type(newType), state(newState), loop(newLoop)
  {
    setVolume(100);
    if (this->track.empty())
      {
	std::cerr << "Error : There is no music" << std::endl;
	return;
      }
    changeTrack(this->track);
    std::cout << "new music" << std::endl;
    if (this->state == PLAY)
      this->start();
  }

  Music::~Music()
  {
    this->stop();
  }

  void		Music::start()
  {
    this->state = PLAY;

    if (this->type == SOUND)
      this->sound.play();
    else if (this->type == MUSIC)
      this->music.play();
  }

  void		Music::pause()
  {
    this->state = PAUSE;

    if (this->type == SOUND)
      this->sound.pause();
    else if (this->type == MUSIC)
      this->music.pause();
  }

  void		Music::stop()
  {
    this->state = STOP;

    if (this->type == SOUND)
      this->sound.stop();
    else if (this->type == MUSIC)
      this->music.stop();
  }

  void		Music::setVolume(int newVolume)
  {
    if (this->type == SOUND)
      this->sound.setVolume(newVolume);
    else if (this->type == MUSIC)
      this->music.setVolume(newVolume);
  }

  void		Music::startLoop()
  {
    this->loop = true;

    if (this->type == SOUND)
      this->sound.setLoop(true);
    else if (this->type == MUSIC)
      this->music.setLoop(true);
  }

  void		Music::stopLoop()
  {
    this->loop = false;

    if (this->type == SOUND)
      this->sound.setLoop(false);
    else if (this->type == MUSIC)
      this->music.setLoop(false);
  }

  void		Music::changeTrack(std::string const &newTrack)
  {
    this->track = newTrack;

    if (this->type == SOUND)
      {
	if (! this->buffer.loadFromFile(this->track))
	  {
	    std::cerr << "Error : loading sound" << std::endl;
	    return;
	  }
	this->sound.setBuffer(this->buffer);
      }
    else if (this->type == MUSIC)
      {
	if (! this->music.openFromFile(this->track))
	  {
	    std::cerr << "Error : loading music" << std::endl;
	    return;
	  }
      }
  }

  SoundState	Music::getState() const
  {
    return (this->state);
  }

  bool		Music::getLoop() const
  {
    return (this->loop);
  }
};
