#include <iostream>
#include <string>
#include "code/programs/transcompilers/tree_hcp/string_tree_getter/hcp_maker.hpp"
#include "code/programs/transcompilers/tree_hcp/string_tree_getter/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"

int main(int argc, char** argv){
    
    //Unicode please
    Set_English_UTF8_Locale();

    //get program options
    auto po = Program_Options(argc,argv);

    //build it
    Hcp_Maker::Create(po.Input_File(),po.Output_File());

}
