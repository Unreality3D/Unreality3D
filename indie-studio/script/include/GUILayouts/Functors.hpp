#ifndef FUNCTORS_HPP_
# define FUNCTORS_HPP_

# include "Gui/Context.hpp"

class HideMenu
{
public:
  void operator()(Gui::Context &);
};

class Quit
{
public:
  void operator()(Gui::Context &);
};

class NetworkInit
{
public:
  void operator()(Gui::Context &, const std::string &);
};

class SelectClass
{
public:
  void operator()(Gui::Context &);
};

class SelectMage
{
public:
  void operator()(Gui::Context &);
};

class SelectWarrior
{
public:
  void operator()(Gui::Context &);
};

class SelectArcher
{
public:
  void operator()(Gui::Context &);
};

class SelectPriest
{
public:
  void operator()(Gui::Context &);
};

#endif // FUNCTORS_HPP_
