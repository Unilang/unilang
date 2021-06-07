#pragma once

//global types
using TestType = unsigned long;

//global constants
namespace constant{
	
	//calculating performance
	constexpr unsigned int min_bit_length = 0;
	constexpr unsigned int max_bit_length = 64;
	constexpr unsigned int num_of_trials = 1000000;
	
	//validating algorithms
	constexpr unsigned int number_of_tests_per_bit_length = 10;
	
}
