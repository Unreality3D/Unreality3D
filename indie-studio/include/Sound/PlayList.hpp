//
// PlayList.hpp for PlayList in /home/labrez_f/test/indie_studio
//
// Made by Florian LABREZE
// Login   <labrez_f@epitech.net>
//
// Started on  Tue May  3 15:32:44 2016 Florian LABREZE
// Last update Tue May  3 17:56:00 2016 Florian LABREZE
//

#ifndef PLAYLIST_HPP_
# define PLAYLIST_HPP_

# include <vector>
# include "Music.hpp"

namespace Sound
{
  class PlayList
  {
  public:
    PlayList(std::string const &track, SoundState state, bool loop);
    ~PlayList();

    void	start();
    void	pause();
    void	stop();

    void	stopLoop();
    void	startLoop();

    void	addTrack(std::string const &track);

    bool	getLoop() const;
    SoundState	getState() const;

  private:
    std::vector<Music*>	tracks;
    SoundState		state;
    bool		loop;
  };
};

#endif /* PLAYLIST_HPP_ */
