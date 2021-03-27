
#include "program_options.hpp"
#include <string>
#include <iostream>

//constructor
Program_Options::Program_Options(int const& argc, char** const& argv){
	using namespace boost::program_options;

	//build all the possible flags and add description.
    options_description desc (Get_Options_Description());

	//set positional arguments
	positional_options_description pod;


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
	options_description desc(DESCRIPTION);

	//Program Flags
	desc.add_options()

	//these are flag descriptions of that can be passed into the class.
	//the code inserted,  are the flags added by the user through the
	//program_options_maker flag interface
	("input_files",value<std::vector<std::string>>()->multitoken(),"the name of the UniLang file to compile")
	("dir",value<std::string>(),"the directory to convert all unilang files from")
	("exporter",value<std::string>(),"the exporter front-end to use for generating the source code (often a company or interested party)")
	("languages",value<std::vector<std::string>>(),"the resulting languages to export unilang to")
	("style",value<std::string>(),"the style you'd like the exporter to employ. Each exporter has their own set of styles for each of the languages they support")
	("recursive_dependency_paths",value<std::vector<std::string>>()->multitoken(),"paths to recursively search for the dependencies of the file being compiled.  This can point to both real code, or Unilang files")
	("dependency_paths",value<std::vector<std::string>>()->multitoken(),"paths to search for the dependencies of the file being compiled.  This can point to both real code, or Unilang files")
	("no-transfer","Decide whether to skip transferring the exported file (this usually entails sending over files over a network possibly)")
	("no-remote-programs","Dont run remote programs on transfered code")
	("no-local-programs","Dont run local programs on exported code")
	("no-build","Decide whether we should try to build the repo where could would be transfered to")
	("build-only","Only do a build")

	//+----------------------------------------------------------+
	//| Obligatory                                               |
	//+----------------------------------------------------------+
	("help,h","produce this help message")
	("version,v","display version")
	;

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
		std::cout << "\nThis is version " << VERSION_NUMBER << " of the " + TOOL_NAME + ".\n\n";
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
std::vector<std::string> Program_Options::Input_Files() const{
	std::vector<std::string> data;
	if (vm.count("input_files")){
		data = vm["input_files"].as<std::vector<std::string>>();
	}

	return data;
}
std::string Program_Options::Dir() const{
	std::string data;
	if (vm.count("dir")){
		data = vm["dir"].as<std::string>();
	}

	return data;
}
Chosen_Exporter Program_Options::Exporter() const{
	std::string data;
	if (vm.count("exporter")){
		data = vm["exporter"].as<std::string>();
	}
	else
	{
		return Chosen_Exporter::NONE;
	}

	return enum_cast_to_Chosen_Exporter(data);
}
std::vector<Artifact_Type> Program_Options::Languages() const{
	std::vector<std::string> data;
	if (vm.count("languages")){
		data = vm["languages"].as<std::vector<std::string>>();
	}
	
	//convert strings to enums
	auto data2 = enum_cast_to_Artifact_Type(data);
	return data2;
}

std::string Program_Options::Style() const{
	std::string data;
	if (vm.count("style")){
		data = vm["style"].as<std::string>();
	}

	return data;
}
std::vector<std::string> Program_Options::Recursive_Dependency_Paths() const{
	std::vector<std::string> data;
	if (vm.count("recursive_dependency_paths")){
		data = vm["recursive_dependency_paths"].as<std::vector<std::string>>();
	}

	return data;
}
std::vector<std::string> Program_Options::Dependency_Paths() const{
	std::vector<std::string> data;
	if (vm.count("dependency_paths")){
		data = vm["dependency_paths"].as<std::vector<std::string>>();
	}

	return data;
}
bool Program_Options::Skip_Transfer() const{
return vm.count("no-transfer");}

bool Program_Options::Skip_Build() const{
return vm.count("no-build");}

bool Program_Options::Build_Only()const{
return vm.count("build-only");}

bool Program_Options::Skip_Remote_Programs() const{
return vm.count("no-remote-programs");}

bool Program_Options::Skip_Local_Programs() const{
return vm.count("no-local-programs");}
