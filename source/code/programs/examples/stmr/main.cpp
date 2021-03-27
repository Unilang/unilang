#include <iostream>
#include <stdio.h>
#include <string.h>
#include "code/utilities/types/strings/observers/natural_language/word_stemer.hpp"

int main(int argc, char **argv){
    std::cout << Word_Stemer::Word_As_Stem("jumping") << std::endl;
}