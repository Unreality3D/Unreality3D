//
// MainMenuContext.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 10:31:27 2016 jeremy metereau
// Last update Sat Jun  4 13:53:28 2016 jeremy metereau
//

#ifndef MAINMENUCONTEXT_HPP_
# define MAINMENUCONTEXT_HPP_

# include "Gui/Context.hpp"

namespace Gui
{
  class MainMenuContext : public Context
  {
  public:
    MainMenuContext(void);
    MainMenuContext(const MainMenuContext &);
    MainMenuContext &operator=(const MainMenuContext &);
    virtual ~MainMenuContext(void);
  };

};

#endif /* !MAINMENUCONTEXT_HPP_ */
