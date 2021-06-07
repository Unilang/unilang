#pragma once
#include "function_expression_node.hpp"

class Function_Expression_Generator{
	
	//constructors
	public: Function_Expression_Generator(std::string const& expression);
	public: Function_Expression_Generator();
	
	//transformer
	void Set_New_Expression(std::string const& expression);
	
	//observers
	public: unsigned int Get_Count();
	//public: unsigned int Get_One_Word_Name_Count();
	public: std::vector<std::string> Get_Generations();
		private: std::vector<std::string> Generate(std::vector<std::vector<Function_Expression_Node>> const& parse_tree);
			private: std::vector<std::string> Sub_Generate(std::vector<Function_Expression_Node> const& nodes);
	
private:
	std::vector<std::vector<Function_Expression_Node>> m_parse_tree;
	unsigned int amount;
	
};
