#include <iostream>
#include <string>
#include "code/programs/transcompilers/code/code_to_java/program_options/program_options.hpp"
#include "code/utilities/formats/json/converters/json_file_io.hpp"
#include "code/utilities/code/concept_static_tree_structs.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/contributor/contributor.hpp"
#include "code/utilities/linguistics/computer/frontends/java/settings/java_settings.hpp"
#include "code/utilities/linguistics/computer/frontends/java/java_str_getter.hpp"
#include "code/utilities/linguistics/computer/frontends/java/settings/java_default_rule_settings.hpp"

int main(int argc, char** argv){

    //get program options
    Program_Options po = Program_Options(argc,argv);
    
    //std::cout << po.Input_File() << std::endl;
    //std::cout << po.Output_File() << std::endl;
    
    //read in
    model::Code code;
    Json_File_Io::Read_Json_From_File(code,po.Input_File());
    
    //convert to java code
    std::vector<Contributor> contributors;
    Java_Settings settings = Java_Default_Rule_Settings::Get();
    std::string str = Java_Str_Getter::Get(code.module[0],contributors,settings);
    
    //export
    Write_To_File(po.Output_File(),str);
    
}
