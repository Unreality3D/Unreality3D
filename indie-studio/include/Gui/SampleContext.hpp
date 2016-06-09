//
// SampleContext.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Mon May 23 11:29:29 2016 jeremy metereau
// Last update Mon May 23 15:29:43 2016 jeremy metereau
//

#ifndef SAMPLECONTEXT_HPP_
# define SAMPLECONTEXT_HPP_

# include "Gui/Context.hpp"

namespace Gui
{

  class SampleContext : public Context
  {
  public:
    SampleContext(const std::string &, bool active = false);
    SampleContext(const SampleContext &);
    SampleContext &operator=(const SampleContext &);
    virtual ~SampleContext(void);
  };

};

#endif /* !SAMPLECONTEXT_HPP_ */
