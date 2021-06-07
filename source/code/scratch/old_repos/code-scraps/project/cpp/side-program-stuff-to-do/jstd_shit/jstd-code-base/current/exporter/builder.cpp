#include "builder.hpp"
#include "utilities.hpp"
#include "global.hpp"
#include <cstdlib>
#include <fstream>
void Builder::Build(Program_Options const& program_options){
	Perform_Timed_Builds(program_options);
	return;
}

void Builder::Perform_Timed_Builds(Program_Options const& program_options){
	std::cout << "Building... "; std::cout.flush();
	
	//start recording the time 
	//it takes to perform the builds
	Build_Stats stats; stats.Start_Timer();
	
		//perform the builds
		Perform_Builds(program_options,stats);
	
	//builds are done.
	//stop the timer
	stats.End_Timer();
	
	//building is complete.
	Green_Message("Success!\n");
	
	//after the successful conversion, output any other kind of desired results
	//Output_Additional_Logging_Information(timer);
}
void Builder::Perform_Builds(Program_Options const& program_options, Build_Stats & stats){
	
		//set the root of where the exported library will be.
		auto exported_library = boost::filesystem::current_path()
		/= constant::EXPORT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT;
		
		//set the root of where the built library data will be.
		auto built_library = boost::filesystem::current_path()
		/= constant::BUILT_LIBRARY_ROOT_RELATIVE_TO_PSEUDO_LIBRARY_ROOT;
		
		//make sure the root of the exported/built library is there
		//and that the path to it, doesn't have any redirection.
		Create_Path_If_It_Doesnt_Already_Exist(exported_library);
		Create_Path_If_It_Doesnt_Already_Exist(built_library);
		Shortify_Path(exported_library);
		Shortify_Path(built_library);
		
		//assuming the program is being run at the root of the pseudo library,
		//this function will export the complete working version of the actual library.
		//(it will only update/create parts of the library that aren't already done)
		//(it will also remove parts of the actual library, that are no longer in the pseudo library)
		Start_The_Builds(program_options, exported_library, built_library, stats);
	
	return;
}
void Builder::Start_The_Builds(Program_Options const& program_options, boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats){
	
	Build_Pre_Compiled_Header(exported_library, built_library, stats);
	Build_Libraries(exported_library, built_library, stats);
	
	return;
}
void Builder::Build_Pre_Compiled_Header(boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats){
	system(("g++ -std=c++11 -o " + built_library.string() + "/jstd.hpp.gch " + exported_library.string() + "/jstd.hpp").c_str());
	Build_Header_That_Is_Looked_For_But_Doesnt_Need_Included_In_Code_But_Needs_To_Be_Specified_In_Command_Line(built_library.string() + "/jstd.hpp");
	return;
}
void Builder::Build_Header_That_Is_Looked_For_But_Doesnt_Need_Included_In_Code_But_Needs_To_Be_Specified_In_Command_Line(std::string const& file_name){
	std::ofstream outfile(file_name);
	outfile << "//You don't need to include this file in your actual source code.\n";
	outfile << "//In fact, since the library code is never going to change once you build it,\n";
	outfile << "//I recommend you don't include this file in your code.\n\n";
	
	outfile << "//So what's the point of this header then?\n";
	outfile << "//The idea behind pre-compiled headers is that they should only be pre-processed when they actually change.\n";
	outfile << "//So IF YOU DID include this header, nothing would be different. It would make sure jstd.hpp exists, but then it\n";
	outfile << "//would go and use jstd.hpp.gch provided IT exists and is up-to-date.\n\n";
	
	outfile << "//How will your program get the library decelerations if you're not going to be including this file in your code?\n";
	outfile << "//You will provide the header through the command line.\n\n";
	
	outfile << "//Like this for example: g++ -std=c++11 -include jstd.hpp main.cpp;\n";
	outfile << "//That will create an a.out without having to pre-process the gigantic library.\n";
	outfile << "//You will still need to link the library as well\n\n";
	
	outfile <<  "//You know what,  I take back not including this file.  If your intellisense system reads from header files, maybe you should include this file\n";
	outfile <<  "//#include \"local path to jstd root header\"\n";
	outfile <<  "or\n";
	outfile <<  "//#include <jstd system header>\n";
	
	
	
	
	return;
}
void Builder::Build_Libraries(boost::filesystem::path const& exported_library, boost::filesystem::path const& built_library, Build_Stats & stats){
	
	auto sources = Recursively_Get_All_Source_File_Paths_Of_Path(exported_library.string());
	
	
	//YOU DON'T HAVE TO STEP INTO THE PATH LIKE I HAD THOUGHT
	//JUST FIX THE LAYOUT OF HEADERS IN THE EXPORT CODE
	for (auto const& it: sources){
		system(("g++ -std=c++11 -c " + it + " -o " + built_library.string() + "/" + Convert_To_Suitable_File_Name(it,built_library)).c_str());
	}
	
	return;
}

std::string Builder::Convert_To_Suitable_File_Name(std::string str,boost::filesystem::path const& built_library){
	
	str.erase(0,built_library.string().size()-1);
	
	std::string return_value;
	for (auto const& it: str){
		if (it == '~' || it == '/' || it == '-'){
			return_value+="_";
		}else if(it == '.'){
			return_value+=".o";
			break;
		}else{
			return_value+=it;
		}
	}
	
	return return_value;
}

std::string Builder::Get_Directory_Of_File(std::string const& path){
	
	std::string return_value = "/";
	
	bool slash_found = false;
	
	for (auto it = path.rbegin(); it != path.rend(); ++it){
		if (!slash_found){
			if (*it == '/'){
				slash_found = true;
			}
		}else{
			return_value = *it + return_value;
		}
	}
	
	
	
	return return_value;
}

std::string Builder::Get_Just_File_Name(std::string const& path){
	
	std::string return_value;
	
		for (auto it = path.rbegin(); it != path.rend(); ++it){
			if (*it == '/'){
				break;
			}
		return_value = *it + return_value;
	}
	
	
	
	return return_value;
}

















