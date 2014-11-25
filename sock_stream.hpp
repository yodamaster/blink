#pragma once

#include <vector>
#include <string>

const int BUFF_SIZE = 1024;

class SockStream
{
  public:
    ~SockStream();
    SockStream();

    int get_handle() const { return socket_; }
    void set_handle(int socket) { socket_ = socket; }

    void read(std::vector<char>& result);
    void write(const std::string& buff);


  private:
    int socket_;
    char buff_[BUFF_SIZE];
};
