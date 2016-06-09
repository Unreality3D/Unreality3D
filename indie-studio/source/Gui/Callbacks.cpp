//
// Callbacks.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 28 16:24:38 2016 jeremy metereau
// Last update Sun Jun  5 17:49:57 2016 Leo Lafon
//

#include <iostream>
#include "Gui/CallBacks.hpp"
#include "Gui/MainMenuContext.hpp"
#include "Gui/ClassSelectContext.hpp"
#include "Gui/NetContext.hpp"

namespace Gui
{

  void HideMenu::operator()(Context &c)
  {
    c.toggleActive(false);
    return ;
  }

  void Quit::operator()(Context &c)
  {
    exit(0);
    return ;
  }

  void NetworkInit::operator()(Context &c, const std::string &field)
  {
    std::cout << field << std::endl;
    c.toggleActive(false);
    return;
  }

  void SelectClass::operator()(Context &c)
  {
    c.toggleActive(false);
    // ClassSelectContext::instance->toggleActive(true);
    return ;
  }

  void SelectMage::operator()(Context &c)
  {
    c.toggleActive(false);
    // NetContext::instance->toggleActive(true);
    return ;
  }

  void SelectWarrior::operator()(Context &c)
  {
    c.toggleActive(false);
    // NetContext::instance->toggleActive(true);
    return ;
  }

  void SelectArcher::operator()(Context &c)
  {
    c.toggleActive(false);
    // NetContext::instance->toggleActive(true);
    return ;
  }

  void SelectPriest::operator()(Context &c)
  {
    c.toggleActive(false);
    // NetContext::instance->toggleActive(true);
    return ;
  }

};
