#pragma once
#include <string>
#include "code/utilities/linguistics/computer/source_language.hpp"

void Create_File_If_It_Doesnt_Exist(std::string const& path_to_file);
void Create_File_Even_If_The_Path_Doesnt_Exist(std::string const& path_to_file);
void Write_To_File(std::string path_to_file, std::string const& content);
void Write_To_File(std::string path_to_file, std::wstring const& content);
void Write_To_File_As_Wstring(std::string path_to_file, std::wstring const& content);

void Write_To_File_With_Auto_Gen_Comment(std::string const& path_to_file, Source_Language const& source_language, std::string const& content);