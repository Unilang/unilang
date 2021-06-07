#pragma once
#include <string>
#include <optional>
#include <ctime>

bool Regular_File_Exists_Recursively(std::string const& path, std::string const& match_name);
    
std::string Get_File_That_Symbolic_Link_Points_To(std::string const& path_to_symbolic_link);

//basically a diff
bool Files_Are_The_Same(const std::string& path_to_file1, const std::string& path_to_file2);

bool Folder_Has_C_Or_CPP_File(std::string folder_name);

std::string Type_Of_File(std::string const& path);

bool Is_A_Dynamic_Executable_According_to_Ldd(std::string const& path);

std::optional<std::time_t> Last_Modification_Time_If_File_Exists(std::string path_to_file);

std::string Instances_Of_Double_Semicolon(std::string const& filename);
