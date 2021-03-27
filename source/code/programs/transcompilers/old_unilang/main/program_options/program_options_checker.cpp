
#include "program_options_checker.hpp"

void Program_Options_Checker::Check(Program_Options const& program_options) {

	Validate_Through_Regular_Expressions(program_options);
	Validate_Through_User_Injected_Code(program_options);

	return;
}

void Program_Options_Checker::Validate_Through_Regular_Expressions(Program_Options const& program_options) {

	return;
}

void Program_Options_Checker::Validate_Through_User_Injected_Code(Program_Options const& program_options) {
	#include "program_options_user_check_code.hpp"

	return;
}
