#include <vector>
#include <iostream>
#include "nameof.hpp"
int main(){
    std::cout << NAMEOF(std::vector<float>()) << std::endl;
}