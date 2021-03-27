#include <iostream>
#include <string>
#include "code/utilities/peripheral/mouse/mouse_controller.hpp"

std::string get_line_from_user()
{
    std::string input;
    std::getline(std::cin,input);
    return input;
}

int main(int argc, char** argv){

    std::cout << "type anything to explain the mouse movement" << std::endl;
    std::cout << "type 'click' to simulate a click" << std::endl;
    std::cout << "type 'hold_l'/'hold_r' to simulate holding mouse button" << std::endl;
    std::cout << "type 'rel_l'/'rel_r' to simulate releasing mouse button" << std::endl;
    std::cout << "type 'done' to finish the manual presentation" << std::endl;
    std::cout << "type command: " << std::endl;
    
    auto input = get_line_from_user();
}