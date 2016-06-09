//
// Thread.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include/Thread
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Sat May 21 11:05:43 2016 Gandoulf
// Last update Sun May 22 14:20:47 2016 Gandoulf
//

#ifndef THREAD_HPP_
# define THREAD_HPP_

# include <thread>

namespace Memory
{
  class Thread
  {
  public:
    Thread();
    ~Thread();

    bool join();

    template<typename... Param>
    void launchThread(Param... param)
    {
      if (_thread != NULL)
	_thread = new std::thread(param...);
    }

  private:
    std::thread	*_thread;
  };
};

#endif /* THREAD_HPP_ */
