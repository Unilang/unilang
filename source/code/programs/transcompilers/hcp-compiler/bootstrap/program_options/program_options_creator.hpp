#pragma once
#include "code/programs/transcompilers/hcp-compiler/bootstrap/program_options/program_options.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/program_options/program_options_checker.hpp"

class Program_Options_Creator{

	public: static Program_Options Create(int const argc, char** const argv);
};

