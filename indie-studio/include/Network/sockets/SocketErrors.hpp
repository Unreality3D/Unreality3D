//
// SocketErrors.hpp for  in /home/agor_m/github/tests_with_cpp_sockets/include
// 
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
// 
// Started on  Tue May  3 16:30:07 2016 Maxime Agor
// Last update Tue May  3 16:55:59 2016 Maxime Agor
//


#ifndef SOCKETERRORS_HPP_
# define SOCKETERRORS_HPP_

# include <string>

namespace Socket
{
  /* SOCKET EXCEPTIONS */

  class SocketError : public std::exception
  {
  public:
    SocketError(std::string err, std::string msg = std::string(""))
      : _err(err), _msg(msg) {}

    virtual ~SocketError() throw() {}

    virtual const char *what() const throw()
    {
      return (_err + " : " + _msg).c_str();
    }

  protected:
    std::string _err;
    std::string _msg;
  };

  class SocketCreateError : public SocketError
  {
  public:
    SocketCreateError(std::string msg = std::string("???"))
      : SocketError("Error in socket creation", msg) {}

    virtual const char *what() const throw()
    {
      return SocketError::what();
    }
  };

  class SocketConnectError : public SocketError
  {
  public:
    SocketConnectError(std::string msg = std::string("???"))
      : SocketError("Error in socket connection", msg) {}

    virtual const char *what() const throw()
    {
      return SocketError::what();
    }
  };

  class SocketIOError : public SocketError
  {
  public:
    SocketIOError(std::string msg = std::string("???"))
      : SocketError("Error in socket I/O operation", msg) {}

    virtual const char *what() const throw()
    {
      return SocketError::what();
    }
  };
};

#endif
