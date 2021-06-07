#pragma once
#include <string>

//observers
bool Inside_Git_Repository();
bool Git_Repo_Dirty();
bool Repo_Exists_On_Github(std::string const& user_name, std::string const& repo_name);
std::string Get_Project_Name();
std::string Get_Project_URL();
std::string Get_Path_Of_Directory_Starting_At_Git_Repo_Root(); //Get_Path_Of_Directory_Starting_At_Directory_Name(std::string directory_name);
unsigned int Number_Of_Directories_Deep_In_Git_Repo(); //unsigned int Number_Of_Directories_Deep_In_Folder_Name(std::string directory_name);
std::string Current_Git_Branch_Name();
std::string Git_Username();
std::string Git_Hosted_User();

//returns path to a newly cloned repo
std::string Download_Repo_To_Random_Name_In_Temp_Folder(std::string ssh_url);
std::string Download_Repo_To_Random_Name_In_Temp_Folder(std::string ssh_url, std::string branch);

//transformers
void Create_Repo_On_Github(std::string const& user_name, std::string const& autorization, std::string const& project_name, std::string const& description);
void Go_To_Git_Repo_Root(); //Move_Back_Directories_Until_Directory_Exists(std::string directory_name);

int Number_Of_Commits();



//find something in source code across history:
//git rev-list --all | xargs git grep <regexp>
