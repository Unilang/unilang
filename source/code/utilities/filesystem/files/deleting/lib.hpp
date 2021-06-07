#pragma once
#include <string>

void Delete_Files_That_Exist_In_Second_Dir_But_Not_In_First(std::string const& based_on, std::string const& delete_from);
void Delete_Files_That_Exist_In_Second_Dir_But_Not_In_First_Based_On_Basename(std::string const& based_on, std::string const& delete_from);
void Empty_Out_Folder_But_Keep_Folder(std::string path);

void Delete_File(std::string const& file);
void Delete_Files(std::vector<std::string> const& files);
