#pragma once
#include <string>
#include <vector>

void Copy_File_And_Follow_Symlink(std::string file, std::string to);
void Copy_File_To_Dir(std::string file, std::string dir);
void Copy_Dereferenced_File_To_Dir(std::string file, std::string dir);
void Copy_Folder_To_Path(std::string folder_name, std::string directory_to_copy_to);
void Copy_Folder_Contents_To_Path(std::string folder_name, std::string directory_to_copy_to);
void Copy_Folder_Contents_To_Path_Only_If_Contents_Are_Different(std::string folder_name, std::string directory_to_copy_to);
void Copy_Files_To_Current_Directory(std::vector<std::string> const& files);
