#include <iostream>
#include <string>
#include "code/utilities/peripheral/mouse/mouse_controller.hpp"


//add points to move to and then speed at which to move
//mouse_move 0 0 2500
//will slowly move the mouse to the corner of the screen
int main(int argc, char** argv){

	//get cli args
	int x_location = atoi(argv[1]);
	int y_location = atoi(argv[2]);
	int wait_speed = atoi(argv[3]);

	//move mouse to top left of screen
	Point p;
	p.x = x_location;
	p.y = y_location;
	Mouse_Controller controller;
	controller.move_mouse(p,wait_speed);
}