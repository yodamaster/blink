#pragma once

#include <memory>

#include "handler.hpp"
#include "reactor.hpp"

class Acceptor;
typedef std::shared_ptr<Acceptor> AcceptorPtr;

class SockStream;
class Acceptor : public Handler, public std::enable_shared_from_this<Acceptor>
{
  private:
    Acceptor(ReactorPtr acceptor_reactor, ReactorPtr session_reactor);

  public:
    ~Acceptor();
    
    Acceptor& operator=( const Acceptor & ) = delete;
    Acceptor( const Acceptor & ) = delete;

    static AcceptorPtr create(ReactorPtr acceptor_reactor, ReactorPtr session_reactor) {return AcceptorPtr(new Acceptor(acceptor_reactor, session_reactor)); }

    AcceptorPtr get_ptr() 
    {
      return shared_from_this();
    }

    void open();

    void accept(SockStream& stream);
    void close();

    void handle_input();

    int get_handle() const { return socket_; }

  private:
    int socket_;

    ReactorPtr acceptor_reactor_;
    ReactorPtr session_reactor_;
};


