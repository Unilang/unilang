#include "mustache.hpp"
#include <iostream>
#include <string>

int main(){
    kainjow::mustache::mustache tmpl{"Hello {{what}}!"};
    std::cout << tmpl.render({"what", "World"}) << std::endl;
    // Hello World!
}