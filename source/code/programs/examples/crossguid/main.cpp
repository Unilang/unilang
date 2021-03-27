#include <iostream>
#include "crossguid/guid.hpp"

int main(){
    auto myGuid = xg::newGuid();
    std::cout << "Here is a random guid: " << myGuid << std::endl;
}