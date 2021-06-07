#pragma once
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/structure/lib.hpp"
#include <vector>
#include <iostream>

class Class_Compiler{





public:

static void Compile_HCP_File(Class_Structure const& structure, std::string const& directory,  bool const& utility_functions=true);

static void Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes);

static void Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file, bool const& utility_functions);
private:
};
