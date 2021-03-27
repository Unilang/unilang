
#pragma once
#include "program_options_default.hpp"

//Boost Libraries
#include "boost/program_options.hpp"

class Program_Options: public Program_Options_Default{

	public:

	//Constructor
	explicit Program_Options(int const& argc, char** const& argv);

	std::string Enum_Name() const;
	std::vector<std::string> Enum_Values()const;
	std::string Output_Path() const;


	private:

	//functions used to parse, store, verify,  and immediately process SOME of the flags.
	//other verification of flag data is passed on as a responsibility of the Program_Options_Checker
	auto Get_Options_Description() -> boost::program_options::options_description;
	auto Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void;
	auto Process_Immediate_Options(boost::program_options::options_description const& desc) -> void;
	auto Check_For_Mandatory_Flags_Not_Passed() -> void;

	//Data Members
	//the variables map,  holds all of the flag data passed in through the constructor.
	boost::program_options::variables_map vm;
};
