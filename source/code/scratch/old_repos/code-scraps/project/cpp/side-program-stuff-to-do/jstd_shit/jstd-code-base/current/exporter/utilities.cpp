#include "utilities.hpp"
#include "global.hpp"
#include <string>
#include <boost/filesystem.hpp>
#include <sys/stat.h>
#include <iostream>

//general system stuff
std::string exec(std::string const& cmd){
	return exec(cmd.c_str());
}
std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
		if (result.size() > 0){
	result.resize(result.size()-1);
	}
    return result;
}

//filesystem stuff
void Create_Path_If_It_Doesnt_Already_Exist(boost::filesystem::path const& path){
	
	if (!File_Exists(path.string())){
		system(("mkdir -p " + path.string()).c_str());
	}
	
	return;
}
std::string Current_Folder_Name(void){
	
	//there is probably a way to get just the current folder name, but i couldn't find it
	std::string full = boost::filesystem::current_path().string();
	std::string name;
	for (auto it = full.rbegin(); it != full.rend(); ++it){
		if (*it == '/'){
			break;
		}
		name+=*it;
	}
	
	std::reverse(name.begin(), name.end());
	return name;
	

}
void Step_Into_Folder(std::string const folder_name){
	
	//not sure if that "./" really needs to be there
	boost::filesystem::current_path("./" + folder_name);
	return;
}
void Step_Out_Of_Folder(void){
	
	//not sure if that "./" really needs to be there
	boost::filesystem::current_path(std::string("./") + std::string("../"));
	return;
}
bool File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}
std::vector<std::string> Get_Dirs_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list = exec("find " + path + " -maxdepth 1 -type d 2>/dev/null; " + "find " + path + " -maxdepth 1 -type l 2>/dev/null;");
	std::string list2;
	
	bool done=false;
	for (auto it = list.begin(); it != list.end(); ++it){
		
		if (*it == '\n' && done == false){
			done = true;
			++it;
			if (it == list.end()){
				break;
			}
		}
		
		if (done){
			list2+=*it;
		}
	}
	
	std::string temp;
	for (auto it: list2){
		if (it == '/'){
			temp.clear();
		}else if (it == '\n'){
			dirs.push_back(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(temp);
	}
	
	return dirs;
}
std::vector<std::string> Get_Files_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list = exec("find " + path + " -maxdepth 1 -type f 2>/dev/null;");
	std::string list2;
	
	bool done=false;
	for (auto it = list.begin(); it != list.end(); ++it){
		
		if (*it == '\n' && done == false){
			done = true;
			++it;
			if (it == list.end()){
				break;
			}
		}
		
		if (done){
			list2+=*it;
		}
	}
	
	std::string temp;
	for (auto it: list2){
		if (it == '/'){
			temp.clear();
		}else if (it == '\n'){
			dirs.push_back(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(temp);
	}
	
	return dirs;
}
std::vector<std::string> Recursively_Get_All_Source_File_Paths_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list = exec("find " + path + " -type f -name \\*.cpp 2>/dev/null;");
	std::string list2;
	
	bool done=false;
	for (auto it = list.begin(); it != list.end(); ++it){
		
		if (*it == '\n' && done == false){
			done = true;
			++it;
			if (it == list.end()){
				break;
			}
		}
		
		if (done){
			list2+=*it;
		}
	}
	
	std::string temp;
	for (auto it: list2){
		if (it == '\n'){
			dirs.push_back(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(temp);
	}
	
	return dirs;
}
	
void Shortify_Path(boost::filesystem::path & path){
	path = boost::filesystem::canonical(path);
	return;
}
std::vector<std::string> Get_Results_Of_Regular_Expression_Solver(std::string const& regular_expression){
	std::vector<std::string> function_names;
	std::string all = exec(("python " + constant::PATH_TO_EXPRESSION_SOLVER + " '" + regular_expression + "'").c_str());
	
	//push into the vector
	std::string str;
	for (auto const& it: all){
		if (it == '\n'){
			function_names.push_back(str);
			str.clear();
		}else{
			str+=it;
		}
	}
	
	//i don't think this if statement will ever be true..
	if (str.size() > 0){
		function_names.push_back(str);
	}
	
	return function_names;
}

//string functions
std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}
std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}
std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}
std::string& Squeeze_Away_Spaces(std::string &s){
	std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
	s.erase(new_end, s.end()); 
	return s;
}

//vector functions
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
	return std::find(vec.begin(), vec.end(), str) != vec.end();
}
//color functions
void Green_Message(std::string const& str){
	std::cout << "\033[22;32m" << str << "\x1b[0m";
	return;
}
void Red_Message(std::string const& str){
	
	std::cerr << "\033[22;31m" << str << "\x1b[0m";
	
	return;
}
void Exit_With_Error_Message(std::string const& str){
	Red_Message(str);
	exit(EXIT_SUCCESS);
	return;
}



