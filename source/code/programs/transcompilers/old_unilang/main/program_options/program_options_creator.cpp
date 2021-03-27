#include "program_options_creator.hpp"

Program_Options Program_Options_Creator::Create(int const argc, char** const argv){
	Program_Options program_options(argc, argv);
	Program_Options_Checker::Check(program_options);
	return program_options;
}
