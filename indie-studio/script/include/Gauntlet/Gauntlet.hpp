//
// Gauntlet.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/script/include/Gauntlet
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Fri Jun  3 15:08:11 2016 Gandoulf
// Last update Sun Jun  5 18:44:17 2016 Leo Lafon
//

#ifndef GAUNTLET_HPP_
# define GAUNTLET_HPP_

# include "Script/AScript.hpp"
# include "Gui/Manager.hpp"

class Gauntlet : public indie::AScript
 {
 public:
   Gauntlet(indie::GameObject *&_gameObject);
   virtual ~Gauntlet();

   virtual void Start();
   virtual void Update() {}
   virtual void OnCollisionEnter(indie::GameObject *) {}

   void newMap();
   void startGame();
   void startMainMenu();
   std::string const& getPlayerClass() const;
   void setPlayerClass(std::string const&);

 private:
   indie::GameObject	*player;
   indie::GameObject	*map;
   indie::GameObject	*gui;
   Gui::Manager		*guiManager;
   std::string		playerClass;
};

# ifdef SCRIPT_GAUNTLET
static Gauntlet *instantiateScript(indie::GameObject *_gameObject)
{
  return (new Gauntlet(_gameObject));
}

extern "C"
{
  Gauntlet     *getScriptInstance(indie::GameObject *_gameObject)
  {
    return (instantiateScript(_gameObject));
  }
}
# endif

#endif /* GAUNTLET_HPP_ */
