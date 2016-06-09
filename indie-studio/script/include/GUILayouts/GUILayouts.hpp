#ifndef GUILAYOUTS_HPP_
# define GUILAYOUTS_HPP_

# include "Script/AScript.hpp"
# include "Gui/Context.hpp"

class GUILayouts : public indie::AScript
{
protected:
  Gui::Context		*_mainMenu;
  Gui::Context		*_escMenu;
  Gui::Context		*_classSelectionMenu;
  Gui::Context		*_inGameMenu;

public:
  GUILayouts(indie::GameObject *&_go);
  virtual ~GUILayouts();

  virtual void		Start();

  Gui::Context		*getMainMenu();
  Gui::Context		*getEscMenu();
  Gui::Context		*getClassSelectionMenu();
  Gui::Context		*getInGameMenu();
};

# ifdef SCRIPT_GUILAYOUTS
static GUILayouts *instantiateScript(indie::GameObject *_gameObject)
{
  return new GUILayouts(_gameObject);
}

extern "C"
{
  GUILayouts *getScriptInstance(indie::GameObject *_gameObject)
  {
    return instantiateScript(_gameObject);
  }
}
# endif

#endif // GUILAYOUTS_HPP_
