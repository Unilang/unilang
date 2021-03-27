#include <iostream>
#include "asap/asap.h"
int main(){
   using namespace asap;
   for (auto x: asap::now().until(asap::tomorrow()).every(asap::hours(1))) {
        std::cout << x << std::endl;
   }
}