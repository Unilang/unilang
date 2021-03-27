#pragma once
#include <string>

class Program_Options_Default{
	
	// Constructor
	protected: explicit Program_Options_Default();
	
	// the author or organization responsible for the software
	// (applied by the flag value --author)
	const std::string AUTHOR =
	"Trevor Hickey"
	;
	
	// a description of the software
	// (applied by the flag value --description)
	const std::string DESCRIPTION =
	"enum generator for c++ with reflective properties"
	;
	
	//website to get code and further information about the software
	// (applied by the flag value --website)
	const std::string WEBSITE =
	"git@github.com:UniLang/unilang.git"
	;
	
	//email address to contact about the software
	// (applied by the flag value --email_address)
	const std::string EMAIL_ADDRESS =
	"TrevorJamesHickey@gmail.com"
	;
	
	//the name of the software tool
	// (applied by the flag value --tool_name)
	const std::string TOOL_NAME =
	"enum_cpp"
	;
	
	//the version number of the software
	// (applied by the flag value --version_number)
	const std::string VERSION_NUMBER =
	"1.0.0"
	;
	
	//the license that the software is under
	// (applied by the flag value --license)
	const std::string LICENSE =
	"MIT"
	;
	
};
