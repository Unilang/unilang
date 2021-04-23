#include <iostream>
#include <string>
#include "code/programs/transcompilers/tree_hcp/static_tree_pk_resolver/pk_resolver.hpp"
#include "code/programs/transcompilers/tree_hcp/static_tree_pk_resolver/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"

int main(int argc, char** argv){
    
    //Unicode please
    Set_English_UTF8_Locale();

    //get program options
    auto po = Program_Options(argc,argv);

    //build it
    Pk_Resolver::Create(po.Input_File()[0], po.Input_File()[1],po.Output_Dir() + "/" + po.Name());

}
