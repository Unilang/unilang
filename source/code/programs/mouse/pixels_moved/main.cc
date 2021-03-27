#include <iostream>
#include <string>
#include "code/utilities/peripheral/mouse/mouse_controller.hpp"

int main(int argc, char** argv){

    Mouse_Controller controller;
    Point previous_pos;
    Point pos;
     
    int total=0;
	previous_pos = controller.current_mouse_position();
    while (true){
        pos = controller.current_mouse_position();
        if ( pos.x != previous_pos.x || pos.y != previous_pos.y){
		
		//calculate distance
		auto part1 = std::pow(pos.x - previous_pos.x,2);
		auto part2 = std::pow(pos.y - previous_pos.y,2);
		auto distance = std::sqrt(part1 + part2);
		total += distance;
		std::cout << total << std::endl;
        }
        previous_pos = pos;
    }
}