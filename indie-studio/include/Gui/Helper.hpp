//
// Helper.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Thu May 26 11:30:23 2016 jeremy metereau
// Last update Fri Jun  3 16:39:57 2016 jeremy metereau
//

#ifndef HELPER_HPP_
# define HELPER_HPP_

# include <string>

namespace Gui
{

  /*
  ** Static class
  */
  class Helper
  {
  public:
    Helper();
    Helper(const Helper &);
    Helper &operator=(const Helper &);
    ~Helper();

    static int getScreenX(void);
    static int getScreenY(void);
    /*
    ** Get the scale rate for X pixels
    */
    static float getScalePx(int);
    static float getScalePy(int);
    /*
    ** get the pixel for X scale rate
    */
    static int getPixelSx(float);
    static int getPixelSy(float);
    /*
    ** Text related
    */
    static int getFontSize(void);
    static std::string keyToChar(int);
  };

};

#endif /* !HELPER_HPP_ */
