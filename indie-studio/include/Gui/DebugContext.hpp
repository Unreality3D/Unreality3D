//
// DebugContext.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 17:48:18 2016 jeremy metereau
// Last update Fri May 27 18:24:03 2016 jeremy metereau
//

#ifndef DEBUGCONTEXT_HPP_
# define DEBUGCONTEXT_HPP_

# include "Gui/Context.hpp"

namespace Gui
{

  class DebugContext : public Context
  {
  public:
    DebugContext();
    DebugContext(const DebugContext &);
    DebugContext &operator=(const DebugContext &);
    virtual ~DebugContext(void);
  };

};

#endif /* !DEBUGCONTEXT_HPP_ */
