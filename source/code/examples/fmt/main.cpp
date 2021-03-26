#include <iostream>
#include <fmt/format.h>

int main(){
    fmt::print("Hello, {}!", "world");  // Python-like format string syntax
    
    auto x = fmt::format("Hello, {}!","world");
    std::cout << std::endl << x << std::endl;
}