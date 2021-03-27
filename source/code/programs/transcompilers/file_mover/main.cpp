#include <iostream>
#include <string>
#include "code/programs/transcompilers/file_mover/program_options/program_options.hpp"
#include "code/utilities/formats/json/converters/json_file_io.hpp"
#include "code/utilities/code/concept_static_tree_structs.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/files/moving/lib.hpp"
#include "code/utilities/program/call/lib.hpp"

int main(int argc, char** argv){

    //get program options
    Program_Options po = Program_Options(argc,argv);
    
    //unhermetically move the file
    Copy_File_And_Follow_Symlink(po.Input_File(),po.Move_Path());
    execute("chmod 664 " + po.Move_Path());
    
    //export a dummy file because that's what bazel expects
    Write_To_File(po.Output_File(),"");
    
}
