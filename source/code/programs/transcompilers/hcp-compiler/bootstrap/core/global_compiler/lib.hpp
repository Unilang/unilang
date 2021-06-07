#pragma once
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/structure/lib.hpp"
#include <iostream>
#include <fstream>

class Global_Compiler{





public:

static void Compile_HCP_File(Class_Structure const& structure);

static void Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes);

static void Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file);


friend std::ostream &operator<<( std::ostream & out, Global_Compiler const& self){
	return out;
}

private:
};
