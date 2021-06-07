#include "program_options.hpp"
const std::string Program_Options::VERSION_NUMBER = "2.1.0";
Program_Options::Program_Options(int const& argc, char** const& argv){
	using namespace boost::program_options;

	//build all the possible flags and add description.
    options_description desc (Get_Options_Description());

	//set positional arguments
	positional_options_description pod;
	//pod.add("something",-1);

	//build variable map
	Build_Variable_Map(argc,argv,desc,pod);
	Process_Immediate_Options(desc);
}
boost::program_options::options_description Program_Options::Get_Options_Description(void){
    using namespace boost::program_options;

    //Program Description
    options_description desc("The exporter will convert the jstd pseudo library code into the real jstd library code");

    //Program Flags
    desc.add_options()
	
	("no_scan","don't scan the pseudo library for issues. [will scan by default]\n")
	("no_export","don't export the library. [will export by default]\n")
	("no_build","don't build any libraries or pre-compiled headers. [will build these by default.  Note: individual build tasks may be specified off though.]\n")
	("prompt_automatic_warning_fixes","ask the user if they would like to fix each warning one at a time. [by default, warnings are fixed automatically.]\n")
	("unresolve_warnings","don't automatically fix warnings. [warnings will be fixed by default.]\n")
	("warn_amount",value<int>(),"The amount of warnings to output before quiting. 0 is infinity, i.e. output every error that is not critical enough to end the application. [0 by default]\n")
	
	("cases",value<std::string>(),"a string of 1s and 0s representing what cases should be on/off.  All cases are on by default.  The case order is:  lowercase underscore, uppercase underscore, lowercase camelCase, uppercase camelCase")

	("inclusion_guards","use inclusion guards over pragma once. [will be use pragma once by default]\n")
	("no_cpp11","don't export any functionality that is C++11 or later.  Export an older compliant solution if available. [c++11 and later functionality will be exported by default]\n")
	
	("no_static","don't export a static library implementation. [will build a static library by default]\n")
	("no_dynamic","don't export a dynamic library implementation. [will build a dynamic library by default]\n")
	("no_windows","don't create a windows version of anything specified to be built. [windows creation is on by default]\n")
	("no_linux","don't create a linux version of anything specified to be built. [linux creation is on by default]\n")
	
	("no_documentation","don't create documentation. [documentation created by default]\n")
	
	("no_stats","don't create library stats. [stats created by default]\n")
	
	("help,h","produce this help message")
    ("version,v","display version");

    return desc;
}
void Program_Options::Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod){
	using namespace boost::program_options;

	//store user flag data. crash elegantly if they pass incorrect flags.
    try{
        store(command_line_parser(argc, argv).options(desc).positional(pod).run(), vm);
        notify(vm);
    }
    catch(error& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cerr << desc << std::endl;
        exit(EXIT_FAILURE);
    }

	return;
}
void Program_Options::Process_Immediate_Options( boost::program_options::options_description const& desc){

    //do not continue the program if the user wanted to see the version or help data
    if (vm.count("version")){
        std::cout << "\nThis is version " << VERSION_NUMBER << " of the Jstd Exporting Tool.\n\n";
        exit(EXIT_SUCCESS);
    }
    else if (vm.count("help")){
        std::cout << '\n' << desc << '\n';
        exit(EXIT_SUCCESS);
    }

    return;
}


std::string Program_Options::Cases(void) const{
	std::string data;
    if (vm.count("cases")){
        data = vm["cases"].as<std::string>();
    }
    
    if(data.empty()){
		data = "1111";
	}
    if (data.size() != 4){
		std::cerr << "--cases does not have enough values specified.\n";
		exit(EXIT_FAILURE);
	}
	
	return data;
}
bool Program_Options::Scan(void) const{
	return !vm.count("no_scan");
}
bool Program_Options::Export(void) const{
	return !vm.count("no_export");
}
bool Program_Options::Build(void) const{
	return !vm.count("no_build");
}
int Program_Options::Warn_Amount(void) const{
	int data;
    if (vm.count("warn_amount")){
        data = vm["warn_amount"].as<int>();
    }
	return data;
}
bool Program_Options::Inclusion_Guards(void) const{
	return vm.count("inclusion_guards");
}
bool Program_Options::CPP11(void) const{
	return !vm.count("no_cpp11");
}
bool Program_Options::Static_Library(void) const{
	return !vm.count("no_static");
}
bool Program_Options::Dynamic_Library(void) const{
	return !vm.count("no_dynamic");
}
bool Program_Options::Documentation(void) const{
	return !vm.count("no_documentation");
}
bool Program_Options::Windows(void) const{
	return !vm.count("no_windows");
}
bool Program_Options::Linux(void) const{
	return !vm.count("no_linux");
}
bool Program_Options::Stats(void) const{
	return !vm.count("no_status");
}
bool Program_Options::Fix_Warnings(void) const{
	return !vm.count("unresolve_warnings");
}
bool Program_Options::Prompt_Automatic_Warning_Fixes(void) const{
	return vm.count("prompt_automatic_warning_fixes");
}


