#pragma once
#include <string>

//file path
std::string Get_File_Extension(std::string const& str);
bool File_Has_Extension(std::string const& path_to_file, std::string const& file_extension);
bool File_Has_Extension(std::string const& path_to_file);
std::string Get_File_Name(std::string const& str);
std::string Get_File_Name_Without_Extension(std::string const& str);
std::string Get_First_Folder_Name(std::string const& str);
bool File_Name_Starts_With(std::string const& str, std::string const& prefix);

std::string Prepend_Path_To_Program_Execution_Unless_Global_Call(std::string const& program_execution, std::string const& path);
std::string Prepend_Cd_Path(std::string const& program_execution, std::string const& path);
std::string Prepend_Cd_Path_Unless_Its_Dot(std::string const& program_execution, std::string const& path);

std::string Replace_File_Name(std::string const& path, std::string const& new_file_name);

//base name
std::string Prepend_Onto_Basename(std::string const& path, std::string const& add);
std::string Append_onto_Basename(std::string const& path, std::string const& add);

std::vector<std::string> All_Paths_Of_Path(std::string const& path);
