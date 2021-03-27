#include "include/semver.hpp"
#include <iostream>

int main(){
    constexpr semver::version v1{1, 4, 3};
    constexpr semver::version v2{1, 2, 4, semver::prerelease::alpha, 10};
    static_assert(v1 != v2);
    static_assert(v1 > v2);
    static_assert(v1 >= v2);
    static_assert(v2 < v1);
    static_assert(v2 <= v1);
    
    
    semver::version ptest("1.2.3");
    std::cout << int(ptest.major) << std::endl;
    std::cout << std::to_string(ptest.minor) << std::endl;
    std::cout << std::to_string(ptest.patch) << std::endl;
}

