#include "export_stats.hpp"

//constructor
Export_Stats::Export_Stats()
: base_functions(0)
, function_synonyms(0)
{}

//function recorders
void Export_Stats::Increment_Base_Function(){
	++base_functions;
	return;
}
void Export_Stats::Increment_Function_Synonyms(unsigned int const& add_amount){
	function_synonyms += add_amount;
	return;
}