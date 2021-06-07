#pragma once
#include <string>

class Warn_Machine{
	
public:
	//constructor
	Warn_Machine(int const& warn_amount);
	
	//transformer
	bool Warn(std::string const& message);
	
private:
	
	int warn_amount_;
	bool infinity;
	
};