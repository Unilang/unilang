#pragma once
#include <string>
#include <fstream>
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/structure/lib.hpp"

class Hcp_Class_Parser {







public: static Class_Structure Parse(std::wifstream & infile, std::string const& hcp_file, std::wstring const& file_type);};