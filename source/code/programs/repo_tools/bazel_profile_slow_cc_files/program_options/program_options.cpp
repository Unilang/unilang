
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
	options_description desc("find slowest cc files from bazel's profile-file");

	//Program Flags
	desc.add_options()

	//these are flag descriptions of that can be passed into the class.
	//the code inserted,  are the flags added by the user through the
	//program_options_maker flag interface
	("profile-out",value<std::string>(),"name for the created profile")
	("profile-in",value<std::string>(),"bazel's already created profile file")
    ("url",value<std::string>(),"url to clone")
    ("branch",value<std::string>(),"branch to go to after clone")
    ("run_dir",value<std::string>(),"don't clone; use existing dir instead")
    ("output",value<std::string>(),"where to store the results of the analysis")
    ("target",value<std::string>(),"target to build with")
    ("job",value<std::string>(),"split the work by having this invocation perform work on the fraction given")
    
    ("honeycomb-dataset",value<std::string>(),"where to send honeycomb data to")
    ("honeycomb-api-key",value<std::string>(),"api key for sending data")

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
		std::cout << "\nThis is version " << "1" << " of bazel_profile_cc_files.\n\n";
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
	//if(!vm.count("input_files")){flags_not_passed.push_back("input_files");}
	//if(!vm.count("exporter")){flags_not_passed.push_back("exporter");}
	//if(!vm.count("language")){flags_not_passed.push_back("language");}

	if (!flags_not_passed.empty()){
		std::cerr << "you need to pass the following flags still:\n";
		for (auto it: flags_not_passed){
			std::cerr << '\t' << it << '\n';
		}
		exit(EXIT_FAILURE);
	}
	return;
}
std::string Program_Options::Profile_In() const{
	std::string data;
	if (vm.count("profile-in")){
		data = vm["profile-in"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Profile_Out() const{
	std::string data;
	if (vm.count("profile-out")){
		data = vm["profile-out"].as<std::string>();
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
std::string Program_Options::Branch() const{
	std::string data;
	if (vm.count("branch")){
		data = vm["branch"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Run_Dir() const{
	std::string data;
	if (vm.count("run_dir")){
		data = vm["run_dir"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Output() const{
	std::string data;
	if (vm.count("output")){
		data = vm["output"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Target() const{
	std::string data;
	if (vm.count("target")){
		data = vm["target"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Job() const{
	std::string data;
	if (vm.count("job")){
		data = vm["job"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Honeycomb_Dataset() const{
	std::string data;
	if (vm.count("honeycomb-dataset")){
		data = vm["honeycomb-dataset"].as<std::string>();
	}

	return data;
}
std::string Program_Options::Honeycomb_API_Key() const{
	std::string data;
	if (vm.count("honeycomb-api-key")){
		data = vm["honeycomb-api-key"].as<std::string>();
	}

	return data;
}

