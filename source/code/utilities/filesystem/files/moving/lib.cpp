#include "code/utilities/filesystem/files/moving/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/types/vectors/transformers/lib.hpp"
#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"
#include "code/utilities/filesystem/files/deleting/lib.hpp"
#include "code/utilities/filesystem/files/observers/other/lib.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include <iostream>

void Copy_File_And_Follow_Symlink(std::string file, std::string to){
    execute("cp -rfHL " + file + " " + to);
}
void Copy_Folder_To_Path(std::string folder_name, std::string directory_to_copy_to){
    execute("cp -rf " + folder_name + " " + directory_to_copy_to);
}
void Copy_File_To_Dir(std::string file, std::string dir){
    execute("cp -rf " + file + " " + dir);
}
void Copy_Dereferenced_File_To_Dir(std::string file, std::string dir){
    execute("cp -rfL " + file + " " + dir);
}

void Copy_Folder_Contents_To_Path(std::string folder_name, std::string directory_to_copy_to){
    execute("cp -rf " + folder_name + "/* " + directory_to_copy_to);
}

void Copy_Files_To_Current_Directory(std::vector<std::string> const& files){
    for (auto const& it: files){
        execute("cp -f " + it + " .");
    }
}

void Copy_Folder_Contents_To_Path_Only_If_Contents_Are_Different(std::string folder_name, std::string directory_to_copy_to){
    
    //get all the files we might want to copy over
    auto from_files = Recursively_Get_All_Paths_To_Files_From_Path(folder_name);
    
	//first element is the name of the directories.  don't want that
	Remove_First_Element(from_files);
	
	//remove directories
	std::vector<std::string> new_from_files;
	for (auto & it: from_files){
		if (!Is_Directory(it)){
			new_from_files.push_back(it);
		}
	}
	
       //trim off the base directory names
	for (auto & it: new_from_files){
		Remove_First_N_Chars(it,folder_name.size()+1);
	}
	
	
    
    //copy over only the files that have different content
    //if the file doesn't exist where we are copying it to, it will not be the same and thus copied over
    for (auto & it: new_from_files){
        auto from_file = folder_name + "/" + it;
        auto to_file = directory_to_copy_to + "/" + it;
        if (!Files_Are_The_Same(from_file,to_file)){
	    Create_File_Even_If_The_Path_Doesnt_Exist(to_file);
            std::string command = std::string("cp -f ") + from_file + " " + to_file;
			std::cout << command << std::endl;
			execute_quietly(command);
        }
    }
}
