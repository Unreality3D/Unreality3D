//
// Stats.hpp for indie in /home/lafon_l/rendu/cpp_indie_studio/indie-studio
//
// Made by Leo Lafon
// Login   <lafon_l@epitech.net>
//
// Started on  Tue May 10 12:06:56 2016 Leo Lafon
// Last update Tue May 31 00:39:57 2016 Leo Lafon
//

#ifndef STATS_HPP_
# define STATS_HPP_

namespace indie
{
  struct Stats
  {
    int			life;
    int			currentLife;
    int			mana;
    int			currentMana;
    int			damage;
    int			range;
    int			speed;
    int			defense;
    unsigned long	attackRate;

    Stats();
    Stats(Stats const&);
    ~Stats();
    void	operator=(Stats const&);
  };
};
#endif /* !STATS_HPP_ */
