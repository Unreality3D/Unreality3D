//
// Manager.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/include/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 14:16:55 2016 jeremy metereau
// Last update Sun Jun  5 17:09:50 2016 Leo Lafon
//

#ifndef MANAGER_HPP_
# define MANAGER_HPP_

# include <vector>
# include <string>
# include "Gui/Context.hpp"
# include "Gui/System.hpp"
# include "InputManager/InputManager.hpp"

/*# ifndef NULL
#  define NULL	0
# endif*/

namespace Gui
{
  class Manager
  {
  private:
    static System		*sys;
    std::vector<Context *>	contexts;
    float			elapsed;
    OgreInput::InputManager	*_im;

  public:
    /*
    ** Coplien
    */
    Manager(void);
    Manager(const Manager &);
    Manager &operator=(const Manager &);
    ~Manager(void);

    Manager	&addContext(Context *);
    Context	*getContext(const std::string &);
    void	removeContext(const std::string &);

    void	processInputs(float);
    /*
    ** Statics
    */
    static void destroySystem(void);
  };
};

#endif /* !MANAGER_HPP_ */
