//
// TextRegistrar.hpp for  in /home/metere_j/tek2/cpp/indie/newgui/cpp_indie_studio/indie-studio/include/Gui
//
// Made by jeremy metereau
// Login   <metere_j@epitech.net>
//
// Started on  Sat May 21 14:25:31 2016 jeremy metereau
// Last update Mon May 23 18:10:49 2016 jeremy metereau
//

#ifndef TEXTREGISTRAR_HPP_
# define TEXTREGISTRAR_HPP_

namespace Gui
{
  class TextRegistrar
  {
  private:
    std::string pool;

  public:
    /*
    ** Coplien
    */
    TextRegistrar(const std::string &pool = "./resource/fonts/");
    TextRegistrar(const TextRegistrar &);
    TextRegistrar &operator=(const TextRegistrar &);
    ~TextRegistrar(void);

    /*
    ** Misc
    */
    void addFont(const std::string &name, const std::string &fileName) const;
  };
};

#endif /* !TEXTREGISTRAR_HPP_ */
