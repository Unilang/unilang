
#include "program_options.hpp"
#include <string>
#include <iostream>
#include <sstream>

//constructor
Program_Options::Program_Options(int const& argc, char** const& argv){
	using namespace boost::program_options;

	//build all the possible flags and add description.
    options_description desc (Get_Options_Description());

	//set positional arguments
	positional_options_description pod;
	pod.add("query", -1);

	//build variable map
	Build_Variable_Map(argc,argv,desc,pod);

	//process immediate options
	Process_Immediate_Options(desc);

	//validate the mandatory flags
	Check_For_Mandatory_Flags_Not_Passed();
}
boost::program_options::options_description Program_Options::Get_Options_Description(void){
	using namespace boost::program_options;

	//Program Description
	options_description desc("test for build determinism on a particular target");

	//Program Flags
	desc.add_options()

	//these are flag descriptions of that can be passed into the class.
	//the code inserted,  are the flags added by the user through the
	//program_options_maker flag interface
	
	//what target we are building and where
	("target",value<std::string>(),"what you would pass to bazel build")
	("url",value<std::string>(),"git url to clone with")
	
	
	//how to setup the repo(s) for multi A/B testing
    ("run_dirs",value<std::vector<std::string>>(),"which directories to run the analysis")
    ("branches",value<std::vector<std::string>>(),"which branches to run the analysis")
        
        
        ("synthesize_problems","synthesize the nondeterminism problems in a human friendly way")
        ("environment_scan",value<int>(),"try the A/B tests in different environments n number of times to evaluate any flakiness of nondeterminism")
        ("augment_scan",value<int>(),"try the A/B tests with different augmentations on the environment n number of times to evaluate any flakiness of nondeterminism")
        
        ("output_dir",value<std::string>(),"the directory to output artifacts")
        ("bazel",value<std::string>(),"the name of the bazel runner (useful if repo has a bazel wrapper or using bazelisk)")
        ("verbose","show verbose progress")

	//+----------------------------------------------------------+
	//| Obligatory                                               |
	//+----------------------------------------------------------+
	("help,h","produce this help message")
	("version,v","display version")
	;

    return desc;
}
std::string Program_Options::Get_Help_Message(){
	std::stringstream ss;
	ss << Get_Options_Description();
	return ss.str();
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
		std::cout << "\nThis is version " << "1" << " of noogle.\n\n";
		exit(EXIT_SUCCESS);
	}
	else if (vm.count("help")){
		std::cout << '\n' << desc << '\n';
		exit(EXIT_SUCCESS);
	}

	return;
}

void Program_Options::Check_For_Mandatory_Flags_Not_Passed(){
	std::vector<std::string> flags_not_passed;

	if (!flags_not_passed.empty()){
		std::cerr << "you need to pass the following flags still:\n";
		for (auto it: flags_not_passed){
			std::cerr << '\t' << it << '\n';
		}
		exit(EXIT_FAILURE);
	}
	return;
}
std::string Program_Options::Target() const{
	std::string data;
	if (vm.count("target")){
		data = vm["target"].as<std::string>();
	}

	return data;
}
std::vector<std::string> Program_Options::Run_Dirs() const{
	std::vector<std::string> data;
	if (vm.count("run_dirs")){
		data = vm["run_dirs"].as<std::vector<std::string>>();
	}

	return data;
}
std::vector<std::string> Program_Options::Branches() const{
	std::vector<std::string> data;
	if (vm.count("branches")){
		data = vm["branches"].as<std::vector<std::string>>();
	}

	return data;
}
std::string Program_Options::Output_Dir() const{
	std::string data;
	if (vm.count("output_dir")){
		data = vm["output_dir"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Bazel() const{
	std::string data;
	if (vm.count("bazel")){
		data = vm["bazel"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Url() const{
	std::string data;
	if (vm.count("url")){
		data = vm["url"].as<std::string>();
	}

	return data;
}
int Program_Options::Environment_Scan() const{
	int data = 0;
	if (vm.count("environment_scan")){
		data = vm["environment_scan"].as<int>();
	}

	return data;
}
int Program_Options::Augmented_Scan() const{
	int data = 0;
	if (vm.count("augment_scan")){
		data = vm["augment_scan"].as<int>();
	}

	return data;
}
bool Program_Options::Synthesize() const{
return vm.count("synthesize_problems");}

bool Program_Options::Verbose() const{
return vm.count("verbose");}
