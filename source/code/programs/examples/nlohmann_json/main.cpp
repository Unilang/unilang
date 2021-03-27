#include "nlohmann/json.hpp"
#include <iostream>

int main(){
  using json = nlohmann::json;
  json j2 = {
    {"pi", 3.141},
    {"happy", true},
    {"name", "Niels"},
    {"nothing", nullptr},
    {"answer", {
      {"everything", 42}
    }},
    {"list", {1, 0, 2}},
    {"object", {
      {"currency", "USD"},
      {"value", 42.99}
    }}
  };
  std::cout << j2.dump(4) << std::endl;
  return 0;
}