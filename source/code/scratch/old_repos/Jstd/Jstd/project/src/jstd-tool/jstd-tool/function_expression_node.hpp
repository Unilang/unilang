#pragma once
#include <string>
#include <vector>

class Function_Expression_Node{
	
public:
	Function_Expression_Node(std::string const& value_in = "", bool const& more_in = false);
	
	std::string value;
	bool more;
	std::vector<std::vector<Function_Expression_Node>> children;
	
};
