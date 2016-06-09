//
// System.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/include/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 13:57:31 2016 jeremy metereau
// Last update Tue May 24 17:25:35 2016 jeremy metereau
//

#ifndef SYSTEM_HPP_
# define SYSTEM_HPP_

namespace Gui
{

  class System
  {
    static int	instances;
    bool	isInit;
  public:
    System(void);
    System(const System &);
    System &operator=(const System &);
    ~System(void);

  };

};

#endif /* !SYSTEM_HPP_ */
