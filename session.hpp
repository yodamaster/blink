#pragma once

#include <memory>

#include "handler.hpp"

#include "sock_stream.hpp"

class Session : public Handler
{
  public:
    ~Session();
    Session();

    SockStream& stream() { return stream_; }

    int get_handle() const { return stream_.get_handle(); }

    void handle_input();

  private:
    SockStream stream_;
};

typedef std::shared_ptr<Session> SessionPtr;

