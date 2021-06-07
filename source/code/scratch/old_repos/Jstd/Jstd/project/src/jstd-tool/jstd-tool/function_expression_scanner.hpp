#pragma once
#include <vector>
#include <string>

class Function_Expression_Scanner{
	
	public: Function_Expression_Scanner() = delete;
	public: static std::vector<std::string> Scan(std::string const& expression);
	
};
