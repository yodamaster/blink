#include <string>
#include <stdexcept>

class exception : public std::runtime_error
{
  public:
    exception(const std::string& msg) : std::runtime_error(msg)
  {
  }

    exception(const std::string& msg1, const std::string& msg2)
      : std::runtime_error(msg1 + " "+ msg2)
    {}

    exception(const std::string& msg1, const std::string& msg2, const std::string& msg3)
      : std::runtime_error(msg1 + " "+ msg2 + " " + msg3)
    {}
};

