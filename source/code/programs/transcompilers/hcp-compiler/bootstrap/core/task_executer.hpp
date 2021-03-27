#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "code/programs/transcompilers/hcp-compiler/bootstrap/program_options/program_options.hpp"

class Task_Executer{













public: static void Execute_Needed_Tasks(Program_Options const& program_options);

private: static void Immediate_Checks_On_Filename_Sent_To_Compiler(std::string const& file_name);};