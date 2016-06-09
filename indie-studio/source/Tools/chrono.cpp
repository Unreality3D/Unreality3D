//
// time.cpp for  in /home/resse_e/rendu/cpp_plazza/encapsulation/time
//
// Made by Enzo Resse
// Login   <resse_e@epitech.net>
//
// Started on  Fri Apr 15 14:18:05 2016 Enzo Resse
// Last update Mon May 30 13:40:42 2016 Gandoulf
//

#include "Tools/chrono.hpp"

namespace Time
{
  Chrono::Chrono()
    : _startingTime(0), _started(false)
  {

  }

  Chrono::~Chrono()
  {

  }

  void Chrono::start()
  {
    clock_gettime(CLOCK_REALTIME, &_spec);
    _startingTime = round(_spec.tv_nsec / 1.0e6) + _spec.tv_sec * 1000;
    _started = true;
  }

  void Chrono::stop()
  {
    _started = false;
  }

  long Chrono::getPassedTime()
  {
    long	actualTime;

    clock_gettime(CLOCK_REALTIME, &_spec);
    actualTime = round(_spec.tv_nsec / 1.0e6) + _spec.tv_sec * 1000;
    return (actualTime - _startingTime);
  }

  long Chrono::getActualTime()
  {
    clock_gettime(CLOCK_REALTIME, &_spec);
    return (round(_spec.tv_nsec / 1.0e6) + _spec.tv_sec * 1000);
  }

  bool Chrono::isStarted()
  {
    return (_started);
  }
};
