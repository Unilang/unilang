
#pragma once
#include "program_options_default.hpp"
#include "code/utilities/formats/artifact/artifact_type.hpp"

//Boost Libraries
#include "boost/program_options.hpp"

class Program_Options: public Program_Options_Default{

	public:

	//Constructor
	explicit Program_Options(int const& argc, char** const& argv);

	//These are functions for the client who uses the Program Options object.
	//They include all of the functions passed to the program_options_maker.
	//The options "help" and "version", do not need to be implemented by the user.
	//The "help" and "version" flags are always added automatically unless specified not to be.
	//+----------------------------------------------------------+
	//| USER FLAGS                                               |
	//+----------------------------------------------------------+
	/*  */ std::vector<std::string> Input_Files()const; //the name of the UniLang file to compile;
           std::string Dir() const;
	/*  */ Chosen_Exporter Exporter()const; //the exporter front-end to use for generating the source code (often a company or interested party);
	/*  */ std::vector<Artifact_Type> Languages()const; //the resulting language of the compiler given to the exporter;
	/*  */ std::string Style()const; //the style you'd like the exporter to employ. Each exporter has their own set of styles for each of the languages they support;
	/*  */ std::vector<std::string> Recursive_Dependency_Paths()const; //paths to recursively search for the dependencies of the file being compiled.  This can point to both real code, or Unilang files;
	/*  */ std::vector<std::string> Dependency_Paths()const; //paths to search for the dependencies of the file being compiled.  This can point to both real code, or Unilang files;
	bool Skip_Transfer()const;
	bool Skip_Remote_Programs()const;
	bool Skip_Local_Programs()const;
	bool Skip_Build()const;
	bool Build_Only()const;


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
