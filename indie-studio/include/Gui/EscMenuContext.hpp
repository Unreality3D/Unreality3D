//
// EscMenuContext.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 28 15:50:40 2016 jeremy metereau
// Last update Sat May 28 15:52:11 2016 jeremy metereau
//

#ifndef ESCMENUCONTEXT_HPP_
# define ESCMENUCONTEXT_HPP_

# include "Gui/Context.hpp"

namespace Gui
{
  class EscMenuContext : public Context
  {
  public:
    EscMenuContext(void);
    EscMenuContext(const EscMenuContext &);
    EscMenuContext &operator=(const EscMenuContext&);
    virtual ~EscMenuContext(void);
  };

};

#endif /* !ESCMENUCONTEXT_HPP_ */
