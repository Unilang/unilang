#include <iostream>
#include "code/examples/variant/root.hpp"
#include "code/utilities/types/variant/lib.hpp"

int main(){
    
    //create A
    A a;
    a.str = "test";
    
    //create B
    B b;
    b.num = 123;
    
    //create Root
    Root r;
    
    r.types = a;
    std::visit(overloaded {
        [&](A const& x) {std::cout << x.str << std::endl;},
        [&](B const& x) {std::cout << x.num << std::endl;},
    }, r.types);
    
    r.types = b;
    std::visit(overloaded {
        [&](A const& x) {std::cout << x.str << std::endl;},
        [&](B const& x) {std::cout << x.num << std::endl;},
    }, r.types);
    

}