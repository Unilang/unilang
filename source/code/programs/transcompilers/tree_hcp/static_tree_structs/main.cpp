#include <iostream>
#include <string>
#include "code/programs/transcompilers/tree_hcp/static_tree_structs/structs_creator.hpp"
#include "code/programs/transcompilers/tree_hcp/static_tree_structs/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"

int main(int argc, char** argv){
    
    //Unicode please
    Set_English_UTF8_Locale();

    //get program options
    auto po = Program_Options(argc,argv);

    //build it
    Structs_Creator::Create(po.Input_File(),po.Output_Dir() + "/" + po.Name());

}
