#pragma once
#include <functional>
#include <string>
#include <vector>

//general functions for general files
void Transform_Each_Line_Of_File_With_Function(std::string const& path_to_file, std::function<std::string& (std::string &)> const& func);
void Transform_File_Lines_In_Bulk_With_Function(std::string const& path_to_file, std::function<std::vector<std::string>& (std::vector<std::string> &)> const& func);


//specific functions for general files
void Reverse_Each_Line_From_File(std::string const& path_to_file);
void Make_The_File_Have_A_Single_Blank_Line_At_The_Bottom(std::string path_to_file);

//c / c++ code file related
void Rename_Preprocessor_Include_Directive_To_Match_File_Name(std::string path_to_file);

//dealing with file types
void Turn_Symbolic_Linked_File_Into_Regular_File(std::string const& path_to_file);


void Append_To_File(std::string const& path, std::string const& str);