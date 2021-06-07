#pragma once

//Boost Libraries
#include <boost/program_options.hpp>

/*

*/
class Program_Options{

	public:

	//Constructors
	explicit Program_Options(int const& argc, char** const& argv);

	//Observers
	
	//scanning and exporting
	bool Scan(void) const;
	bool Export(void) const;
	bool Build(void) const;
	int Warn_Amount(void) const;
	bool Fix_Warnings(void) const;
	bool Prompt_Automatic_Warning_Fixes(void) const;
	
	//library customizations
	std::string Cases(void) const;
	
	//library details
	bool Inclusion_Guards(void) const;
	bool CPP11(void) const;
	
	//build
	bool Static_Library(void) const;
	bool Dynamic_Library(void) const;
	bool Windows(void) const;
	bool Linux(void) const;
	
	//Documentation
	bool Documentation(void) const;
	
	//Library Stats
	bool Stats() const;
	

	protected:
	private:

	//functions
	auto Get_Options_Description(void) -> boost::program_options::options_description;
	auto Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void;
	auto Process_Immediate_Options(boost::program_options::options_description const& desc) -> void;

	//data members
	boost::program_options::variables_map vm;
	static const std::string VERSION_NUMBER;

};