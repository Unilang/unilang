#include "tweeny.h"
#include <iostream>

int main(){
    auto helloworld = tweeny::from('h','e','l','l','o').to('w','o','r','l','d').during(50);
    for (int i = 0; i < 50; i++) {
        for (char c : helloworld.step(1)) { printf("%c", c); }
        printf("\n");
    }
}