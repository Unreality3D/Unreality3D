//
// LibraryLoader.cpp for  in /home/gandoulf/epitech/cpp_indie_studio/indie-studio/source/LibraryLoader
//
// Made by Gandoulf
// Login   <gandoulf@epitech.net>
//
// Started on  Tue May 24 11:49:59 2016 Gandoulf
// Last update Mon May 30 11:04:46 2016 Gandoulf
//

#include "LibraryLoader/LibraryLoader.hpp"

namespace Memory
{
  LibraryLoader::LibraryLoader()
    :_library(NULL), _handler(NULL)
  {

  }

  LibraryLoader::~LibraryLoader()
  {
    freeSharedLibrary();
  }

  void LibraryLoader::loadSharedLibrary(std::string pcDllname, int iMode)
  {
    if (_library != NULL)
      return;
#if defined(_MSC_VER) // Microsoft compiler
    pcDllname += ".dll";
    if ((_library = (void*)LoadLibrary(pcDllname)) == 0)
      throw LibraryLoadError();
#elif defined(__GNUC__) // GNU compiler
    pcDllname += ".so";
    if ((_library = dlopen(pcDllname.c_str(),iMode)) == 0)
      throw LibraryLoadError();
#endif
  }

  void *LibraryLoader::getFunction(std::string const &fctName)
  {
#if defined(_MSC_VER) // Microsoft compiler
    if ((_handler = (void*)GetProcAddress((HINSTANCE)_library, fctName.c_str())) == 0)
      throw LibraryFunctionLoadError();
#elif defined(__GNUC__) // GNU compiler
    if ((_handler = dlsym(_library, fctName.c_str())) == 0)
      throw LibraryFunctionLoadError();
#endif
    return (_handler);
  }

  bool LibraryLoader::freeSharedLibrary()
  {
    bool	stat;
#if defined(_MSC_VER) // Microsoft compiler
    if (_library != NULL)
      stat = FreeLibrary((HINSTANCE)_library);
#elif defined(__GNUC__) // GNU compiler
    if (_library != NULL)
      stat = dlclose(_library);
#endif
    if (stat = true)
      {
	_library = NULL;
	_handler = NULL;
      }
    return stat;
  }

  char *LibraryLoader::logError()
  {
#if defined(_MSC_VER)
    return ("not implemented");
#elif defined(__GNUC__)
    return (dlerror());
#endif
  }
}
