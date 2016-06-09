//
// NetContext.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 13:55:52 2016 jeremy metereau
// Last update Sat Jun  4 15:42:57 2016 jeremy metereau
//

#ifndef NETCONTEXT_HPP_
# define NETCONTEXT_HPP_

# include "Gui/Context.hpp"

namespace Gui
{
  class NetContext : public Context
  {
  public:
    NetContext(void);
    NetContext(const NetContext &);
    NetContext &operator=(const NetContext &);
    virtual ~NetContext(void);

    static NetContext *instance;
  };

};

#endif /* !NETCONTEXT_HPP_ */
