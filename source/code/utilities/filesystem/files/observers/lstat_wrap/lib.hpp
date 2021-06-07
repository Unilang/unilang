#pragma once
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unordered_map>

struct stat Lstat(std::string path_to_file);
    
size_t Last_Modified_Time_From_Epoch(std::string const& path_to_file);

//checking characteristics of a single file
bool Is_Symbolic_Link(std::string path_to_file);
bool Is_Directory(std::string path_to_file);
bool Is_Regular_File(std::string path_to_file);
bool Is_A_Socket(std::string path_to_file);
bool Is_A_FIFO_Special_File(std::string path_to_file);
bool Is_A_Character_Special_File(std::string path_to_file);
bool Is_A_Block_Special_File(std::string path_to_file);

//checking the existence of a particular file
bool File_Exists(std::string const& filename);
    bool File_Exists_And_Is_Symbolic_Link(std::string path_to_file);
    bool File_Exists_And_Is_Directory(std::string path_to_file);
    bool File_Exists_And_Is_Regular_File(std::string path_to_file);
    bool File_Exists_And_Is_A_Socket(std::string path_to_file);
    bool File_Exists_And_Is_A_FIFO_Special_File(std::string path_to_file);
    bool File_Exists_And_Is_A_Character_Special_File(std::string path_to_file);
    bool File_Exists_And_Is_A_Block_Special_File(std::string path_to_file);
