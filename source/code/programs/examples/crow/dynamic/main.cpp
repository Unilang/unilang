#include "include/crow.h"

int main()
{
    crow::SimpleApp app;

    std::string route = "/";
    CROW_ROUTE(app, route)([](){
        return "Hello world";
    });

    app.port(18080).multithreaded().run();
}