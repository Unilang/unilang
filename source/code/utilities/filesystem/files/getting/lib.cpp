#include <iostream>
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/strings/observers/splitting/lib.hpp"
#include "code/utilities/types/vectors/operators/lib.hpp"
#include "code/utilities/types/strings/observers/front_back/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/vectors/transformers/lib.hpp"
#include "code/utilities/types/vectors/observers/lib.hpp"
#include "code/utilities/types/strings/observers/front_back/lib.hpp"
#include "code/utilities/streams/filestreams/read_all/lib.hpp"
#include <dirent.h>

std::string First_Filename_Found_At_Current_Path(std::vector<std::string> const& file_names)
{
    auto files = Get_Everything_At_Path();
    for (auto const& it: file_names){
        for (auto const& x: files){
            if (it == x){
                return it;
            }
        }
    }
    return "";
}
std::string First_Filename_Found_At_Path(std::vector<std::string> const& file_names, std::string const& path)
{
    auto files = Get_Everything_At_Path(path);
    for (auto const& it: file_names){
        for (auto const& x: files){
            if (it == x){
                return it;
            }
        }
    }
    return "";
}

std::vector<std::string> Get_Everything_At_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if we need it, since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    std::string str;
    while ((entry = readdir(dp))){
        str = entry->d_name;
        if (str != "." && str != ".."){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}

std::vector<std::string> Get_Full_Paths_Of_Everything_At_Path(std::string path){
    auto get = Get_Everything_At_Path(path);
    
    std::vector<std::string> results;
    for (auto const& it: get){
        results.emplace_back(path + "/" + it);
    }
    return results;
}

std::vector<std::string> Get_Symbolic_Links_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_Symbolic_Link(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Dirs_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    std::string str;
    while ((entry = readdir(dp))){
        str = entry->d_name;
        if (str != "." && str != ".."){
            if (Is_Directory(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Regular_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_Regular_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Sockets_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_Socket(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_FIFO_Special_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_FIFO_Special_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Character_Special_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_Character_Special_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Block_Special_Files_Of_Path(std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Is_A_Block_Special_File(path + entry->d_name)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}

std::vector<std::pair<std::string,std::string>> Get_File_Names_And_File_Contents_Of_Path(std::string path){
    
    std::vector<std::pair<std::string,std::string>> names_and_contents;
    auto file_names = Get_Regular_Files_Of_Path(path);
    std::vector<std::string> contents;
    for (auto const& it: file_names){
        contents.push_back(Read_Entire_File_Into_String(path + '/' + it));
    }
    
    for (size_t i = 0; i < file_names.size(); ++i){
        names_and_contents.emplace_back(file_names[i],contents[i]);
    }
    
    return names_and_contents;
}

std::vector<std::string> Get_Everything_At_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ 
	std::cerr << "couldn't open dir" << std::endl;
	return elements;
   }
    
    //skip over the "." and ".."
    //readdir(dp);
    //readdir(dp);
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Symbolic_Links_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_Symbolic_Link(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Dirs_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_Directory(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Regular_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_Regular_File(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Sockets_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_Socket(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_FIFO_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_FIFO_Special_File(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Character_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_Character_Special_File(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}
std::vector<std::string> Get_Block_Special_Files_Of_Path_With_The_File_Extension(std::string const& file_extension, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //loop and store
    while ((entry = readdir(dp))){
        if (Ends_With(entry->d_name,file_extension)){
            if (Is_A_Block_Special_File(path + entry->d_name)){
                elements.push_back(entry->d_name);
            }
        }
    }
    
    closedir(dp);
    
    return elements;
}

std::vector<std::string> Get_Everything_At_Path_With_The_Basename(std::string const& base_name, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return elements;}
    
    //skip over the "." and ".."
    readdir(dp);
    readdir(dp);
    
    //loop and store
    while ((entry = readdir(dp))){
        if (As_Removed_Suffix(entry->d_name) == base_name){
            elements.push_back(entry->d_name);
        }
    }
    
    closedir(dp);
    return elements;
}
bool Path_Contains_File_With_Basename(std::string const& base_name, std::string path){
    std::vector<std::string> elements;
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if wer need it since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return false;}
    
    //skip over the "." and ".."
    readdir(dp);
    readdir(dp);
    
    //loop and store
    while ((entry = readdir(dp))){
        if (As_Removed_Suffix(entry->d_name) == base_name){
            closedir(dp);
            return true;
        }
    }
    
    closedir(dp);
    return false;
}

bool Path_Contains_File_With_Same_Basename_As_File(std::string const& file, std::string path){
    
    struct dirent* entry;
    DIR* dp;
    
    //add slash to the end if we need it, since we append the path onto the filename when storing
    if (path[path.size()-1] != '/'){path+="/";}
    
    //open folder
    dp = opendir(path.c_str());
    if (dp == NULL){ return false;}
    
    //loop and store
    std::string str;
    while ((entry = readdir(dp))){
        str = entry->d_name;
        if (str != "." && str != ".."){
            //std::cout << As_Removed_Suffix(entry->d_name) << " == " << As_Removed_Suffix(file) << std::endl;
            if (As_Removed_Suffix(entry->d_name) == As_Removed_Suffix(file)){
                closedir(dp);
                return true;
            }
        }
    }
    
    closedir(dp);
    return false;
}

//filename may have nested directory as prefix
bool Recursive_Path_Contains_File_With_Same_Basename_As_File(std::string const& file, std::string path){
    
    //get just the directory names where the file lives
    auto parts = Get_Path_In_Parts(file);
    if (parts.size() > 1){
        auto actual_filename = Last_Element(parts);
        Remove_Last_Element(parts);
        
        std::string directory_part;
        for (auto const& it: parts){
            directory_part += it + "/";
        }
        
        return Path_Contains_File_With_Same_Basename_As_File(actual_filename, path + "/" + directory_part);
    }
    
    //the file passed in, is indeed just a file, and not a path to a file
    return Path_Contains_File_With_Same_Basename_As_File(file,path);

}





//these need changed
//I'd like to replace them with the file system traverser, and we should start pulling objects into the pre-jstd
//I don't really want the path to change for these function though; you know- thread safety
//I'll keep these shell call ones for now
std::vector<std::string> Recursively_Get_All_Paths_To_Files_From_Path(std::string const& path){
    auto str = exec("find " + path + " 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str);
    return vec;
}
std::vector<std::string> Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path(std::string file_extension, std::string const& path){
    auto str_1 = exec("find " + path + " -type f -name \\*." + file_extension + " 2>/dev/null;");
    auto str_2 = exec("find " + path + " -type l -name \\*." + file_extension + " 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str_1);
    vec += Put_Each_Line_Of_String_Into_A_Vector(str_2);
    return vec;
}
std::vector<std::string> Recursively_Get_All_Paths_To_Non_Symlink_Files_Of_Given_File_Extension_From_Path(std::string file_extension, std::string const& path){
    auto str_1 = exec("find " + path + " -type f -name \\*." + file_extension + " 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str_1);
    return vec;
}
 
 
std::vector<std::string> Recursively_Get_All_Paths_To_cpp_Files_Of_Path(std::string const& path){
    return Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path("cpp",path);
 }
 std::vector<std::string> Recursively_Get_All_Paths_To_hpp_Files_Of_Path(std::string const& path){
    return Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path("hpp",path);
 }
  std::vector<std::string> Recursively_Get_All_Paths_To_hcp_Files_Of_Path(std::string const& path){
    return Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path("hcp",path);
 }
 std::vector<std::string> Recursively_Get_All_Paths_To_Deb_Files_Of_Path(std::string const& path){
    return Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path("deb",path);
 }
 std::vector<std::string> Recursively_Get_All_Paths_To_Static_Libraries_Of_Path(std::string const& path){
    return Recursively_Get_All_Paths_To_Files_Of_Given_File_Extension_From_Path("a",path);
 }
std::vector<std::string> Recursively_Get_All_Paths_To_Directories_Of_Given_Name_From_Path(std::string directory_name, std::string const& path){
  std::string str = exec("find " + path + " -type d -name " + directory_name + " 2>/dev/null;");
    auto vec = Put_Each_Line_Of_String_Into_A_Vector(str);

  return vec;
 }
 
std::vector<std::string> Recursively_Get_All_Paths_To_Non_Symlink_Deb_Files_Of_Path(std::string const& path){
    return Recursively_Get_All_Paths_To_Non_Symlink_Files_Of_Given_File_Extension_From_Path("deb",path);
}

char Get_Last_Char_Of_File(std::string const& file){
    auto str = execute(std::string("tail -c1 ") + file);
    return str[0];
}
bool File_Ends_In_Newline(std::string const& file){
    auto str = execute(std::string("tail -c1 ") + file);
    if (str.empty()){
        return false;
    }
    if (str[0] == '\n'){
        return true;
    }
    return false;
}
