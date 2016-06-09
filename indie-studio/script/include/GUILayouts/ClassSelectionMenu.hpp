#ifndef CLASSSELECTIONMENU_HPP_
# define CLASSSELECTIONMENU_HPP_

# include "Gui/Context.hpp"

class ClassSelectionMenu : public Gui::Context
{
public:
  ClassSelectionMenu(void);
  ClassSelectionMenu(const ClassSelectionMenu &);
  ClassSelectionMenu &operator=(const ClassSelectionMenu &);
  virtual ~ClassSelectionMenu(void);
};

#endif /* !CLASSSELECTIONMENU_HPP_ */
