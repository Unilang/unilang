#include <iostream>
#include "code/utilities/program/wrappers/git/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/random/lib.hpp"
#include "code/utilities/random/files/random_files.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/program/call/process_spawn/timed/timed_process_spawner.hpp"


std::string Download_Repo_To_Random_Name_In_Temp_Folder(std::string ssh_url)
{
	auto dir = Random_Files::Random_Tmp_Directory();
	std::string command = "git clone ";
	command += ssh_url;
	command += " ";
	command += dir;
	std::cout << command << std::endl;
	auto spawn = Timed_Process_Spawner::Execute_And_Get_Back_Results(command);
	if (spawn.results.return_code != 0){
		std::cerr << spawn.results.stderr << std::endl;
		exit(-1);
	}
	
	return dir;
}
std::string Download_Repo_To_Random_Name_In_Temp_Folder(std::string ssh_url, std::string branch)
{
	auto dir = Random_Files::Random_Tmp_Directory();
	std::string command = "git clone ";
	command += "--branch ";
	command += branch;
	command += " ";
	command += ssh_url;
	command += " ";
	command += dir;
	auto spawn = Timed_Process_Spawner::Execute_And_Get_Back_Results(command);
	if (spawn.results.return_code != 0){
		std::cerr << spawn.results.stderr << std::endl;
		exit(-1);
	}
	return dir;
}

bool Inside_Git_Repository(){
	return Directory_Exists_In_Current_Directory_Or_Any_Parents(".git");
}

bool Git_Repo_Dirty(){
	return Get_Return_Value_Of_Running("git diff-index --quiet HEAD --;");
}
bool Repo_Exists_On_Github(std::string const& user_name, std::string const& repo_name){
//return Successful_Run_Of_Command("wget -q --spider address https://github.com/" + user_name + "/" + repo_name);
return Successful_Run_Of_Command("curl -s --head https://github.com/" + user_name + "/" + repo_name + " | head -n 1 | grep \"HTTP/1.[01] [23]..\"");
}
void Create_Repo_On_Github(std::string const& user_name, std::string const& autorization, std::string const& project_name, std::string const& description){
exec_quietly("curl -u \"" + user_name + ":" + autorization + "\" https://api.github.com/user/repos -d '{\"name\": \"" + project_name + "\", " + "\"description\": \"" + description + "\"}'");
}
std::string Get_Path_Of_Directory_Starting_At_Git_Repo_Root(){
	return Get_Path_Of_Directory_Starting_From_Root_Directory_Name(".git");
}
void Go_To_Git_Repo_Root(){
	return Move_Back_Directories_Until_Directory_Exists(".git");
}
unsigned int Number_Of_Directories_Deep_In_Git_Repo(){
	return Number_Of_Directories_Deep_In_Root_Directory_Name(".git");
}
std::string Get_Project_Name(){
	return execute("basename `git rev-parse --show-toplevel`");
}
std::string Get_Project_URL(){
	return execute("git ls-remote --get-url");
}
std::string Current_Git_Branch_Name(){
	return execute("git rev-parse --abbrev-ref HEAD");
}
std::string Git_Username(){
	return execute("git config --global user.name");
}
std::string Git_Hosted_User(){
	auto str = exec("git config --get remote.origin.url");
	std::string author;

	//parse that url to get the author/organization name and repo name seperate
	bool add_to_first = true;
	if (!str.empty()) {
		str.erase(0, 15);
		for (auto const& it: str) {
			if (it == '/') {add_to_first = false;}
			else{
				if (add_to_first) {author += it;}
			}
		}
	}
	return author;
}

int Number_Of_Commits()
{
	return as_signed(execute("git rev-list --count HEAD"));
}
