//
// Thread.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/source/Thread
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat May 21 11:14:39 2016 Gandoulf
// Last update Sun May 22 14:22:17 2016 Gandoulf
//

#include "Tools/Thread.hpp"

namespace Memory
{
  Thread::Thread()
    : _thread(NULL)
  {

  }

  Thread::~Thread()
  {
    join();
  }

  bool Thread::join()
  {
    if (_thread != NULL)
      {
	if (_thread->joinable())
	  _thread->join();
	delete _thread;
      }
  }
};
