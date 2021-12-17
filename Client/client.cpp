#include "client.hpp"

client::client() {
  std::cout << "Enter RHOST (http://ip-or-domain:port): ";
  std::cin >> RHOST;
}

auto client::post(std::string data) {
  httplib::Client cli(RHOST);
  auto response =
      cli.Post("/message", "msg=" + data, "application/x-www-form-urlencoded");
  return response;
}

auto client::ping() {
  std::string error = "Something is wrong";
  httplib::Client cli(RHOST);
  if (auto res = cli.Get("/ping")) {
    if (res->status == 200) {
      return res->body;
    }
  }
  return error;
}
