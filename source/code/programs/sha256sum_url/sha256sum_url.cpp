#include <iostream>
#include <cstdlib>
#include "code/utilities/formats/compression/lib.hpp"

int main(int const argc, char** const argv){
    
    //this can be done with a simple curl and sha256 command
    auto sha = Sha256sum_Of_Url_Artifact(argv[1]);
    std::cout << sha << std::endl;
}