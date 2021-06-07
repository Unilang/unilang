#pragma once
#include <vector>
#include <string>
#include <utility>

//getting files from a path
std::vector<std::string> Get_Everything_At_Path(std::string path = ".");
std::vector<std::string> Get_Symbolic_Links_Of_Path(std::string path = ".");
std::vector<std::string> Get_Dirs_Of_Path(std::string path = ".");
std::vector<std::string> Get_Regular_Files_Of_Path(std::string path = ".");
std::vector<std::string> Get_Sockets_Of_Path(std::string path = ".");
std::vector<std::string> Get_FIFO_Special_Files_Of_Path(std::string path = ".");
std::vector<std::string> Get_Character_Special_Files_Of_Path(std::string path = ".");
std::vector<std::string> Get_Block_Special_Files_Of_Path(std::string path = ".");

std::vector<std::string> Get_Full_Paths_Of_Everything_At_Path(std::string path = ".");

//getting files from a path based on file extension
std::vector<std::string> Get_Everything_At_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_Symbolic_Links_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_Dirs_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_Regular_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_Sockets_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_FIFO_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_Character_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");
std::vector<std::string> Get_Block_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path = ".");

std::string First_Filename_Found_At_Current_Path(std::vector<std::string> const& file_names);
std::string First_Filename_Found_At_Path(std::vector<std::string> const& file_names, std::string const& path);

//getting files from a path based on basename
std::vector<std::string> Get_Everything_At_Path_With_The_Basename(std::string const& base_name, std::string path = ".");
bool Path_Contains_File_With_Basename(std::string const& base_name, std::string path = ".");
bool Path_Contains_File_With_Same_Basename_As_File(std::string const& file, std::string path = ".");
    
    std::vector<std::pair<std::string,std::string>> Get_File_Names_And_File_Contents_Of_Path(std::string path = ".");

    //recursively getting files from a path
    std::vector<std::string> Recursively_Get_All_Paths_To_Files_From_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path(std::string file_extension, std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_cpp_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_hpp_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_hcp_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_Deb_Files_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_Static_Libraries_Of_Path(std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_Directories_Of_Given_Name_From_Path(std::string directory_name, std::string const& path = ".");
    
    std::vector<std::string> Recursively_Get_All_Paths_To_Non_Symlink_Files_Of_Given_File_Extension_From_Path(std::string file_extension, std::string const& path = ".");
    std::vector<std::string> Recursively_Get_All_Paths_To_Non_Symlink_Deb_Files_Of_Path(std::string const& path = ".");


bool Recursive_Path_Contains_File_With_Same_Basename_As_File(std::string const& file, std::string path);


char Get_Last_Char_Of_File(std::string const& file);
bool File_Ends_In_Newline(std::string const& file);