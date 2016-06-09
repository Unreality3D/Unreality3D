#ifndef MAINMENU_HPP_
# define MAINMENU_HPP_

# include "Gui/Context.hpp"

class MainMenu : public Gui::Context
{
public:
  MainMenu(void);
  MainMenu(const MainMenu &);
  MainMenu &operator=(const MainMenu &);
  virtual ~MainMenu(void);
};

#endif /* !MAINMENU_HPP_ */
