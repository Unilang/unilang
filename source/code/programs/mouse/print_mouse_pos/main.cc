#include <iostream>
#include <string>
#include "code/utilities/peripheral/mouse/mouse_controller.hpp"

int main(int argc, char** argv){

    Mouse_Controller controller;
    Point previous_pos;
    Point pos;
    while (true){
        pos = controller.current_mouse_position();
        if ( pos.x != previous_pos.x || pos.y != previous_pos.y){
            std::cout << pos.x << " " << pos.y << std::endl;
        }
        previous_pos = pos;
    }
}