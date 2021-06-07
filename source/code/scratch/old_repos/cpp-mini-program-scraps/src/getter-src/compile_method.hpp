#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "utilities.hpp"

class Compile_Method {
	
public:
	
	//constructor
	Compile_Method(std::string const& language_standard_in);
	
	//transformers
	void Attempt_To_Get_Successful_Build(std::string source_file);
	
	//observers
	bool Was_Successful();
	
	
private:
	
	//data members
	std::string language_standard;      //a particular c++ language standard to give the compiler
	std::vector<std::string> libraries; //additional libraries that made it build correctly
	bool success;
};
