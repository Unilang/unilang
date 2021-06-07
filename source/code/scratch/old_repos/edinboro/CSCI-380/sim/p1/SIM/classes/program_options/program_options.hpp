#pragma once

//Boost Libraries
#include <boost/program_options.hpp>

#include "constants.hpp"
#include <vector>
#include <string>

/*

*/
class Program_Options{

	public:

	//Constructors
	explicit Program_Options(int const& argc, char** const& argv);

	//Observers
	std::vector<std::string> Files(void) const;

	//Transformers


	protected:
	private:

	//functions
	auto Get_Options_Description(void) -> boost::program_options::options_description;
	auto Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void;
	auto Process_Immediate_Options(boost::program_options::options_description const& desc) -> void;

	//data members
	boost::program_options::variables_map vm;

};
