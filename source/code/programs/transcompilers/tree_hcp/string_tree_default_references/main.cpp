#include <iostream>
#include <string>
#include "code/programs/transcompilers/tree_hcp/string_tree_default_references/export_default_references.hpp"
#include "code/programs/transcompilers/tree_hcp/string_tree_default_references/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"

int main(int argc, char** argv){
    
    //Unicode please
    Set_English_UTF8_Locale();

    //get program options
    auto po = Program_Options(argc,argv);

    //build it
    Export_Default_References::Create(po.Output_Dir());

}
