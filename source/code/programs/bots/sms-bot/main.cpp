#include "program_options_creator.hpp"
#include "task_executer.hpp"

//Get Program Options and call Task_Executer on them
int main(int const argc, char** const argv) {

	//get program options from the command line
	auto program_options = Program_Options_Creator::Create(argc, argv);

	//choose what task to do (this handles all of the flag options we just read in)
	Task_Executer::Do_Needed_Tasks(program_options);

	//It is possible for this program to end successfully, but unlikely.
	//This bot is designed to run 24/7, it takes a special command
	//sent to it through group chat in order to shut it down and exit the function above.
	//Probably want to check via a list of sudoer's email addresses, 
	//and still ask for a password to prevent email spoofing
	return EXIT_SUCCESS;
}
