#pragma once
#include <string>
#include <vector>
#include "function_expression_node.hpp"

class Function_Expression_Parser{

	Function_Expression_Parser() = delete;
	
//get parse tree
public: static std::vector<std::vector<Function_Expression_Node>> Parse(std::vector<std::string> const& tokens, unsigned int & amount);
	private: static std::vector<std::vector<Function_Expression_Node>> Build_Parse_Tree(std::vector<std::string>::const_iterator & it, std::vector<std::string>::const_iterator const& end, unsigned int & amount);
		private: static Function_Expression_Node Recursive_Build(std::vector<std::string>::const_iterator & it, int & total); //<- recursive
	
	//utility
	private: static bool Is_Word(std::string const& it);
};
