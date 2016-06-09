//
// FunctorField.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat Jun  4 11:45:32 2016 jeremy metereau
// Last update Sat Jun  4 12:20:08 2016 jeremy metereau
//

#ifndef FUNCTORFIELD_HPP_
# define FUNCTORFIELD_HPP_

# include "Gui/Helper.hpp"
# include "IndieStudio/GameManager.hpp"
# include "Gui/InputField.hpp"

namespace Gui
{

  template <class F>
  class FunctorField : public InputField
  {
    F	callback;

  public:
    FunctorField(Context &c, const std::string &n, const std::string &d,
		 int m, const Ogre::Vector2 &p) :
      InputField(c, n, d, m, p) {}
    FunctorField(const FunctorField &o) :
      InputField(o) {}
    FunctorField &operator=(const FunctorField &o)
    { return *this; }
    virtual ~FunctorField(void) {}

    virtual void	TriggerKey(void)
    {
      InputField::TriggerKey();
      OgreInput::InputManager &inputs = (*indie::GameManager::getInputManager());
      for (int i = OIS::KeyCode::KC_UNASSIGNED; i < OIS::KeyCode::KC_MAIL; ++i)
	{
	  if (inputs.getKeyDown((OIS::KeyCode)i))
	    if (Helper::keyToChar(i) == "\n")
	      callback(context, clean);
	}
    }

  };

};

#endif /* !FUNCTORFIELD_HPP_ */
