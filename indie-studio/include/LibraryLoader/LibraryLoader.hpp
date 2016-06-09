//
// LibraryLoader.hpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/include
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 11:31:30 2016 Gandoulf
// Last update Mon May 30 11:03:37 2016 Gandoulf
//

#ifndef LIBRARYLOADER_HPP_
# define LIBRARYLOADER_HPP_

# include <string>
# if defined(_MSC_VER) // Microsoft compiler
#  include <windows.h>
# elif defined(__GNUC__) // GNU compiler
#  include <dlfcn.h>
# else
#  error define your copiler
# endif

namespace Memory
{
  class LibraryLoadError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error in library loading";
    }
  };

  class LibraryFunctionLoadError : public std::exception
  {
  public:
    virtual const char *what() const throw()
    {
      return "Error can't get the function: symbole unknow";
    }
  };

  class LibraryLoader
  {
  public:
    LibraryLoader();
    ~LibraryLoader();

    void loadSharedLibrary(std::string pcDllname, int iMode = 2);
    void *getFunction(std::string const &fctName);
    bool freeSharedLibrary();
    char *logError();

  private:
    void	*_library;
    void	*_handler;
  };
};

#endif /* LIBRARYLOADER_HPP_ */
