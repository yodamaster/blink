#include "session.hpp"

#include <string>

#include "debug.hpp"

Session::~Session()
{

}

Session::Session()
{

}

void Session::handle_input()
{
  DEBUG("session handle input");

  std::vector<char> buff;
  stream_.read(buff);
 
  std::string s(buff.begin(), buff.end());

  DEBUG("GOT %s", s.c_str());

  stream_.write(s);
}

