//
// Music.hpp for Music.hh in /home/labrez_f/test/indie_studio
//
// Made by Florian LABREZE
// Login   <labrez_f@epitech.net>
//
// Started on  Tue May  3 14:59:59 2016 Florian LABREZE
// Last update Fri May 27 17:41:05 2016 Florian LABREZE
//

#ifndef SOUND_HPP_
# define SOUND_HPP_

# include <iostream>
# include "SFML/Audio.hpp"

namespace Sound
{
  enum SoundState
  {
    PLAY,
    PAUSE,
    STOP
  };

  enum SoundType
    {
      MUSIC,
      SOUND
    };

  class Music
  {
  public:
    Music(std::string const &newTrack = "", SoundType newType = SOUND, SoundState newState = STOP, bool newLoop = false);
    ~Music();

    void	start();
    void	pause();
    void	stop();

    void	setVolume(int newVolume);

    void	startLoop();
    void	stopLoop();

    void	changeTrack(std::string const &newTrack);

    SoundState	getState() const;
    bool	getLoop() const;

  private:
    std::string	track;
    SoundState	state;
    bool	loop;
    int		volume;

    SoundType		type;
    sf::SoundBuffer	buffer;
    sf::Sound		sound;
    sf::Music		music;
  };
};

#endif /* SOUND_HPP_ */
