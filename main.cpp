#include "Client/client.cpp"
#include "Server/server.cpp"
#include <thread>
#include <unistd.h>

int main() {

  std::string message = "";

  client cl;

  std::cout << "Initializing Server..." << std::endl;
  std::thread sr_thread(&server::start, server());
  sleep(1);
  sr_thread.detach();

  std::cout
      << "Checking Server... " << cl.ping() << std::endl
      << "1. exit to stop application\n2. ping to check server connectivity\n";

  std::cout << "You: ";
  std::cin >> message;

  while (message != "exit") {
    if (message == "ping") {
      std::cout << "Checking Server... " << cl.ping() << std::endl;
    } else {
      cl.post(message);
    }
    std::cout << "You: ";
    std::cin >> message;
  }

  return 0;
}
