#include "function.hpp"
std::string Function::get_paramater_list() const{
	std::string str;
	for (auto it = parameters.begin(); it != parameters.end(); ++it){
		str+= it->first + " " + it->second;
		if (it != parameters.end()-1){
			str+= ", ";
		}
	}
	return str;
}
	
std::string Function::get_passed_in_values() const{
	std::string str;
	for (auto it = parameters.begin(); it != parameters.end(); ++it){
		str+= it->second;
		if (it != parameters.end()-1){
			str+= ", ";
		}
	}
	return str;
}