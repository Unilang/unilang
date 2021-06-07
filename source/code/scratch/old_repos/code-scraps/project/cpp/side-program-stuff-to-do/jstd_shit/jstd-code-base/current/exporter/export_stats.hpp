#pragma once
#include "stat_timer.hpp"

class Export_Stats: public Stat_Timer{
	
	
public:
	
	//constructor
	Export_Stats();
	
	//function recorders
	void Increment_Base_Function();
	void Increment_Function_Synonyms(unsigned int const& add_amount);

private:
	
	unsigned int base_functions;
	unsigned int function_synonyms;

};
