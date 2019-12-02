#include <fmt/core.h>
#include <httplib.h>

int main() {

    using namespace httplib;

    Server srv;

    srv.Get("/", [](const Request& req, Response& res) {
        res.set_content("Hello world!", "text/plain");
    });

    srv.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
        auto numbers = req.matches[1];
        res.set_content(numbers, "text/plain");
    });

    srv.Get("/stop", [&](const Request& req, Response& res) {
        srv.stop();
    });

    const auto port = 4321;

    fmt::print("Listening on PORT {}", port);

    srv.listen("localhost", port);
}
