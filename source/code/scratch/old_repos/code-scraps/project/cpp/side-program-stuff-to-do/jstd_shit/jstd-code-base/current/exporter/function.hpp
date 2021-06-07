#pragma once
#include <string>
#include <vector>

class Function{
	
public:
	std::string get_paramater_list() const;
	std::string get_passed_in_values() const;
	
public:
	
	//data
	std::vector<std::string> attributes;
	std::vector<std::string> template_statement;
	std::string return_type;
	std::vector<std::pair<std::string,std::string>> parameters;
	std::vector<std::string> function_name_expressions;
	std::vector<std::string> definition;
	std::vector<std::string> raw_adds;
	std::vector<std::string> raw_deletes;
	std::string function_base;
	
};