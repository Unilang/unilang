#pragma once
#include <iostream>
#include <string>
#include <vector>

template <typename IntegerType=Default_Test_Element>
struct Algorithm{
	
	Algorithm(std::string const& name_, std::vector<IntegerType>&(*fun_)(std::vector<IntegerType>&))
	: name(name_)
	, fun(fun_)
	{}
	
	std::string name;
	std::vector<IntegerType>&(*fun)(std::vector<IntegerType>&);
	boost::posix_time::time_duration total_time;
	unsigned int trials;
};
