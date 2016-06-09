#ifndef INGAMEMENU_HPP_
# define INGAMEMENU_HPP_

# include "Gui/Context.hpp"

class InGameMenu : public Gui::Context
{
public:
  InGameMenu(void);
  InGameMenu(const InGameMenu &);
  InGameMenu &operator=(const InGameMenu &);
  virtual ~InGameMenu(void);
};

#endif // INGAMEMENU_HPP_
