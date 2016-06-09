//
// ClassSelectContext.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 14:08:45 2016 jeremy metereau
// Last update Sat Jun  4 14:10:16 2016 jeremy metereau
//

#ifndef CLASSSELECTCONTEXT_HPP_
# define CLASSSELECTCONTEXT_HPP_

# include "Gui/Context.hpp"

namespace Gui
{

  class ClassSelectContext : public Context
  {
  public:
    ClassSelectContext(void);
    ClassSelectContext(const ClassSelectContext &);
    ClassSelectContext &operator=(const ClassSelectContext &);
    virtual ~ClassSelectContext(void);

    static ClassSelectContext *instance;
  };

};

#endif /* !CLASSSELECTCONTEXT_HPP_ */
