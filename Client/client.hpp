#include "../cpp-httplib/httplib.h"
#include <iostream>
#include <string>

class client {
private:
  std::string RHOST = "";

public:
  client();
  auto ping();            // to check if server is live
  auto post(std::string); // to send data to server
};