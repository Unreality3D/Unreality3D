//
// time.hpp for  in /home/resse_e/rendu/cpp_plazza/encapsulation/include
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Fri Apr 15 14:17:13 2016 Enzo Resse
// Last update Mon May 30 13:40:38 2016 Gandoulf
//

#ifndef CHRONO_HPP_
# define CHRONO_HPP_

# include <time.h>
# include <math.h>

namespace Time
{
  class Chrono
  {
  public:
    Chrono();
    ~Chrono();

    void start();
    void stop();
    long getPassedTime();
    long getActualTime();

    bool isStarted();

  private:
    struct timespec     _spec;
    long		_startingTime;
    bool		_started;
  };
};

#endif /* CHRONO_HPP_ */
