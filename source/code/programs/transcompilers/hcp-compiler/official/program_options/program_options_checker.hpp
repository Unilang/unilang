
#include "program_options.hpp"

class Program_Options_Checker {

	//If there are any additional issues with the flags you would like to check for, that can be done here.
	//these checks should deal with logical issues of the flag values, and not how flag values were passed.
	//If there are no logic errors, then the function will return; else it will exit the program inside the function.
	//This function is called automatically by the Program_Options object.
	public: static void Check(Program_Options const& program_options);
		private: static void Validate_Through_Regular_Expressions(Program_Options const& program_options);
		private: static void Validate_Through_User_Injected_Code(Program_Options const& program_options);
};
