//
// SampleContext.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Mon May 23 13:35:05 2016 jeremy metereau
// Last update Mon May 23 15:46:16 2016 jeremy metereau
//

#include "Gui/SampleButton.hpp"
#include "Gui/SampleContext.hpp"

namespace Gui
{

  SampleContext::SampleContext(const std::string &n, bool actv) :
    Context(n, actv)
  {
    components.push_back(new SampleButton(*this, "sampleButton"));
    if (active)
      overlay->show();
    std::cout << "[GUI] Done creating sampleContext." << std::endl;
  }

  SampleContext::SampleContext(const SampleContext &o) :
    Context(o)
  {
  }

  SampleContext &SampleContext::operator=(const SampleContext &o)
  {
    return *this;
  }

  SampleContext::~SampleContext(void)
  {
  }

};
