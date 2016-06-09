//
// AComponent.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 17:50:49 2016 jeremy metereau
// Last update Fri Jun  3 10:49:27 2016 jeremy metereau
//

#include <iostream>
#include "Gui/Helper.hpp"
#include "Gui/AComponent.hpp"

namespace Gui
{
  /*
  ** Coplien
  */
  AComponent::AComponent(Context &c, const std::string &n,
			 const Ogre::Vector2 &_pos,
			 const Ogre::Vector2 &_dim, bool Q) :
    context(c), pos(_pos), dim(_dim), active(false), quiet(Q), name(n)
  {
  }

  AComponent::AComponent(const AComponent &o) :
    context(o.context), pos(o.pos), dim(o.dim),
    active(o.active), quiet(o.quiet), name(o.name + "b")
  {
  }

  AComponent	&AComponent::operator=(const AComponent &o)
  {
    dim = o.dim;
    pos = o.pos;
    active = o.active;
    return *this;
  }

  AComponent::~AComponent(void)
  {
  }

  /*
  ** Click element
  */
  bool	AComponent::isQuiet(void) const
  {
    return quiet;
  }

  bool	AComponent::isIn(int x, int y) const
  {
    /* if hover effect, should be here */
    if ((x >= Helper::getPixelSx(pos.x) && x <= (Helper::getPixelSx(pos.x + dim.x))) &&
	(y >= Helper::getPixelSy(pos.y) && y <= (Helper::getPixelSy(pos.y + dim.y))))
      return true;
    return false;
  }

  void	AComponent::Trigger(void)
  {
    /* should active component if clicked */
    return ;
  }

  void	AComponent::unTrigger(void)
  {
    /* component not clicked */
    return ;
  }

  void	AComponent::hover(void)
  {
    return ;
  }

  /*
  ** Passive element
  */
  bool	AComponent::isActive(void) const
  {
    return active;
  }

  void	AComponent::setActive(bool state)
  {
    active = state;
    return ;
  }

  void	AComponent::TriggerKey(void)
  {
    return ;
  }

  void	AComponent::update(void)
  {
    return ;
  }

  const std::string &AComponent::getName(void) const
  {
    return name;
  }

  const std::string &AComponent::getValue(void) const
  {
    return name;
  }

};
