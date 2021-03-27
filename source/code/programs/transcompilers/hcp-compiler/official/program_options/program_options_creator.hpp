#pragma once
#include "program_options.hpp"
#include "program_options_checker.hpp"

class Program_Options_Creator{

	public: static Program_Options Create(int const argc, char** const argv);
};

