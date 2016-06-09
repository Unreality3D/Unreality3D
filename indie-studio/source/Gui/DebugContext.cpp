//
// DebugContext.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Fri May 27 17:50:09 2016 jeremy metereau
// Last update Sat May 28 11:03:55 2016 jeremy metereau
//

#include "Gui/Toggler.hpp"
#include "Gui/DebugText.hpp"
#include "Gui/DebugContext.hpp"

namespace Gui
{

  DebugContext::DebugContext(void) :
    Context("DebugContext", false)
  {
    components.push_back(new DebugText(*this));
    components.push_back(new Toggler(*this, OIS::KC_F3));
    std::cout << "[GUI] DebugContext Loaded." << std::endl;
  }

  DebugContext::DebugContext(const DebugContext &o) :
    Context(o)
  {
  }

  DebugContext &DebugContext::operator=(const DebugContext &o)
  {
    return *this;
  }

  DebugContext::~DebugContext(void)
  {
  }

};
