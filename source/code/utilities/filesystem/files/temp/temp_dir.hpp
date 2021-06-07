#pragma once
#include <string>
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/files/deleting/lib.hpp"
#include "code/utilities/random/files/random_files.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"

// sometimes you need to temporarily create a directory and put things into it.
// so other tools can reference that directory
// we use RAII to clean it up afterwards
class Temp_Dir {
    public:
        
    //provide name and whether to keep
    Temp_Dir(std::string const& path, bool keep=false){
        file_name = path;
        keep_ = keep;
        Create_Path_If_It_Doesnt_Already_Exist(file_name);
    }
    
    //derive temp name automatically
    Temp_Dir(bool keep=false){
        file_name = Random_Files::Random_Tmp_Directory();
        keep_ = keep;
        Create_Path_If_It_Doesnt_Already_Exist(file_name);
    }
    
    ~Temp_Dir(){
        if (!keep_){
            Delete_File(file_name);
        }
    }
    
    std::string Path(){
        return file_name;
    }
    
    private:
        bool keep_;
        std::string file_name;
};
