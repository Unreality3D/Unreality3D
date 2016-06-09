#ifndef ESCMENU_HPP_
# define ESCMENU_HPP_

# include "Gui/Context.hpp"

class EscMenu : public Gui::Context
{
public:
  EscMenu(void);
  EscMenu(const EscMenu &);
  EscMenu &operator=(const EscMenu&);
  virtual ~EscMenu(void);
};

#endif // ESCMENU_HPP_
