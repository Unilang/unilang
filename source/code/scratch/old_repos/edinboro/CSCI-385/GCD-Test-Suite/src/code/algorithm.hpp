#pragma once
#include <iostream>
#include <string>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

//TODO: this should be a class, and it should be able to
// calculate averages and stuff.. 
template <typename IntegerType=TestType>
struct Algorithm{
	
	Algorithm(std::string const& name_, IntegerType(*fun_)(IntegerType, IntegerType))
	: name(name_)
	, fun(fun_)
	{}
	
	std::string name;
	IntegerType(*fun)(IntegerType, IntegerType);
	boost::posix_time::time_duration total_time;
	unsigned int trials;
};
