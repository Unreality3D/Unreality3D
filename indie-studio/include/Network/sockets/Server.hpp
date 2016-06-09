//
// Server.hpp for  in /home/agor_m/github/tests_with_cpp_sockets/include
//
// Made by Maxime Agor
// Login   <agor_m@epitech.net>
//
// Started on  Mon May  2 15:20:47 2016 Maxime Agor
// Last update Sun Jun  5 18:54:18 2016 Maxime Agor
//

#ifndef SERVER_HPP_
# define SERVER_HPP_

#include <functional>
# include <thread>
# include <atomic>
#include <sys/time.h>

# include "Network/sockets/Sockets.hpp"

namespace Socket
{
  class Server
  {
  public:
    Server();
    virtual ~Server();

    /* SERVER CONFIGURATION API */

    void start(int port, size_t maxClients = 1);
    void stop();

    // set the timeout in ms
    void     setTimeout(float t);
    float    getTimeout() const;

    size_t   getMaxClients() const;

    /* CALLBACKS API */
    // param0 : *this

    // called on client connexion
    // param1 : Int : fd of the client socket
    void  OnConnect(std::function < void (Server &, int) > const &callback);
    // called on client disconnexion
    // param1 : Int : closed fd of the client socket
    void  OnDisconnect(std::function < void (Server &, int) > const &callback);
    // called on client read accessibility
    // param1 : Int : fd of the client socket
    // param2 : size_t : size possible to read (can change meanwhile)
    void  OnReadPossible(std::function < void (Server &, int, size_t) > const &callback);
    // called on client write accessibility
    // param1 : Int : fd of the client socket
    void  OnWritePossible(std::function < void (Server &, int) > const &callback);
    // called on server startup
    // param1 : Int : Port of the connexion
    void  OnStart(std::function < void (Server &, int) > const &callback);


    /* I/O API */
    void    disconnect(int fd);
    int     read(int fd, void *buffer, size_t size);
    int     write(int fd, void const *buffer, size_t size);
    size_t  bytesAvailables(int fd) const;

  protected:
    int                                             _port;
    size_t                                          _maxClients;
    SOCKET                                          _fd;
    std::vector<SOCKET>                             _clients;
    std::thread                                     _stateThread;
    timeval                                         _timeout;

    std::function < void (Server &, int) >          _OnConnect;
    std::function < void (Server &, int) >          _OnDisconnect;
    std::function < void (Server &, int, size_t) >  _OnReadPossible;
    std::function < void (Server &, int) >          _OnWritePossible;
    std::function < void (Server &, int) >               _OnStart;

  private:
    void  stateChecker();
    fd_set                                          _fd_set;
    int                                             _max_fd;
    std::atomic<bool>                               _isRunning;
  };
};

#endif
