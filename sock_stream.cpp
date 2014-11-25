#include "sock_stream.hpp"

#include "exception.hpp"

#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

SockStream::~SockStream()
{
  ::close(socket_);
}

SockStream::SockStream() : socket_(0)
{
//  if((socket_ = socket(AF_INET, SOCK_STREAM, 0)) == -1)
//  {
//    throw exception("Can't create socket");
//  }
//  
//  int yes;
//  
//  if(setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
//  {
//    throw exception("Can't set socket options");
//  }
}

void SockStream::read(std::vector<char>& result)
{
  int nbytes;

  if((nbytes = recv(socket_, buff_, sizeof(buff_), 0)) <= 0)
  {
    if(nbytes == 0) 
    {
      //shutdown
      return;
    }
    else 
    {
      throw exception("Can't read from the socket");
    }

    return;
  }
  
  result.insert(result.end(), buff_, buff_ + nbytes);
}

void SockStream::write(const std::string& buff)
{
  if(send(socket_, buff.c_str(), buff.size(), 0) == -1)
    throw exception("Can't write to the socket");
}

