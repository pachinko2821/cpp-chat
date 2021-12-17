#include "server.hpp"

void server::start() {

  httplib::Server svr;

  svr.Get("/ping", [](const httplib::Request &req, httplib::Response &res) {
    res.set_content("Server is Live", "text/plain");
  });

  svr.Post("/message", [](const httplib::Request &req, httplib::Response &res) {
    auto val = req.get_param_value("msg");
    res.set_content("", "text/plain");
    std::cout << "Them: " << val << std::endl;
  });

  svr.listen("localhost", 9001);
}
