//
// Helper.cpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Thu May 26 11:39:03 2016 jeremy metereau
// Last update Mon Jun  6 17:34:11 2016 jeremy metereau
//

#include "OIS/OISKeyboard.h"
#include "Gui/Helper.hpp"
#include "IndieStudio/GameManager.hpp"

namespace Gui
{

  Helper::Helper(void)
  {
  }

  Helper::Helper(const Helper &o)
  {
  }

  Helper &Helper::operator=(const Helper &o)
  {
    return *this;
  }

  Helper::~Helper(void)
  {
  }

  /*
  ** Statics
  */

  int	Helper::getScreenX(void)
  {
    return indie::GameManager::getOgreInstance()->viewport.getActualWidth();
  }

  int	Helper::getScreenY(void)
  {
    return indie::GameManager::getOgreInstance()->viewport.getActualHeight();
  }

  float	Helper::getScalePx(int x)
  {
    return ((float)x / (float)getScreenX());
  }

  float	Helper::getScalePy(int x)
  {
    return ((float)x / (float)getScreenY());
  }

  int	Helper::getPixelSx(float x)
  {
    return (x * getScreenX());
  }

  int	Helper::getPixelSy(float x)
  {
    return (x * getScreenY());
  }

  int	Helper::getFontSize(void)
  {
    return ((getScreenY() * 30) / 1200);
  }

  std::string	Helper::keyToChar(int x)
  {
    if (x >= OIS::KeyCode::KC_1 && x <= OIS::KeyCode::KC_9)
      return (x - 2 + "0");
    else if (x == OIS::KeyCode::KC_0)
      return "0";
    else
      {
	switch (x)
	  {
	  case OIS::KeyCode::KC_Q:
	    return "q";
	  case OIS::KeyCode::KC_W:
	    return "w";
	  case OIS::KeyCode::KC_E:
	    return "e";
	  case OIS::KeyCode::KC_R:
	    return "r";
	  case OIS::KeyCode::KC_T:
	    return "t";
	  case OIS::KeyCode::KC_Y:
	    return "y";
	  case OIS::KeyCode::KC_U:
	    return "u";
	  case OIS::KeyCode::KC_I:
	    return "i";
	  case OIS::KeyCode::KC_O:
	    return "o";
	  case OIS::KeyCode::KC_P:
	    return "p";
	  case OIS::KeyCode::KC_A:
	    return "a";
	  case OIS::KeyCode::KC_S:
	    return "s";
	  case OIS::KeyCode::KC_D:
	    return "d";
	  case OIS::KeyCode::KC_F:
	    return "f";
	  case OIS::KeyCode::KC_G:
	    return "g";
	  case OIS::KeyCode::KC_H:
	    return "h";
	  case OIS::KeyCode::KC_J:
	    return "j";
	  case OIS::KeyCode::KC_K:
	    return "k";
	  case OIS::KeyCode::KC_L:
	    return "l";
	  case OIS::KeyCode::KC_Z:
	    return "z";
	  case OIS::KeyCode::KC_X:
	    return "x";
	  case OIS::KeyCode::KC_C:
	    return "c";
	  case OIS::KeyCode::KC_V:
	    return "v";
	  case OIS::KeyCode::KC_B:
	    return "b";
	  case OIS::KeyCode::KC_N:
	    return "n";
	  case OIS::KeyCode::KC_M:
	    return "m";
	  case OIS::KeyCode::KC_PERIOD:
	    return ".";
	  case OIS::KeyCode::KC_NUMPAD7:
	    return "7";
	  case OIS::KeyCode::KC_NUMPAD8:
	    return "8";
	  case OIS::KeyCode::KC_NUMPAD9:
	    return "9";
	  case OIS::KeyCode::KC_NUMPAD4:
	    return "4";
	  case OIS::KeyCode::KC_NUMPAD5:
	    return "5";
	  case OIS::KeyCode::KC_NUMPAD6:
	    return "6";
	  case OIS::KeyCode::KC_NUMPAD1:
	    return "1";
	  case OIS::KeyCode::KC_NUMPAD2:
	    return "2";
	  case OIS::KeyCode::KC_NUMPAD3:
	    return "3";
	  case OIS::KeyCode::KC_NUMPAD0:
	    return "0";
	  case OIS::KeyCode::KC_DECIMAL:
	    return ".";
	  case OIS::KeyCode::KC_BACK:
	    return "\r";
	  case OIS::KeyCode::KC_COLON:
	    return ":";
	  case OIS::KeyCode::KC_RETURN:
	    return "\n";
	  default:
	    return "";
	  }
      }
  }
};
