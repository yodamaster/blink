#pragma once

#include <memory>

class Handler
{
  public:
    virtual ~Handler();
    Handler();

    virtual int get_handle() const = 0; 

    virtual void handle_input() {}
};

typedef std::shared_ptr<Handler> HandlerPtr;

