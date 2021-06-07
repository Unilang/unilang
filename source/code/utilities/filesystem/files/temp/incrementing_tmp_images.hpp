#pragma once
#include <string>
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/files/deleting/lib.hpp"
#include "code/utilities/random/files/random_files.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/filesystem/files/temp/temp_dir.hpp"


class Incrementing_Tmp_Images {
    public:
        
    Incrementing_Tmp_Images(std::string const& path, bool keep=false):
    dir(path,keep)
    {}
    Incrementing_Tmp_Images(bool keep=false):
    dir(keep)
    {}
    
    std::string Path(){
        return dir.Path();
    }
    
    std::string Next_Image_Name(){
        auto result = dir.Path() + "/" + std::to_string(incrementer) + ".png";
        ++incrementer;
        return result;
    }
    
    
    private:
        int incrementer = 0;
        Temp_Dir dir;
};
