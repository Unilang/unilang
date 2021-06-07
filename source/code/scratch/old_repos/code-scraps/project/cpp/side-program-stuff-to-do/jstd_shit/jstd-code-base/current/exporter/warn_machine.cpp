#include "warn_machine.hpp"
#include "utilities.hpp"
#include <cstdlib>
#include <string>

//constructor
Warn_Machine::Warn_Machine(int const& warn_amount):
warn_amount_(warn_amount)
{
	if (warn_amount_ == 0){
		infinity = true;
	}else{
		infinity = false;
	}
}


//transformer
bool Warn_Machine::Warn(std::string const& message){
	
	Red_Message(message);
	
	if (!infinity){
		--warn_amount_;
		
		if (warn_amount_ == 0){
			return false;
		}
	}
	
	return true;
}