#include <iostream>
#include <string>
#include "code/programs/transcompilers/unilang/unilang_to_code/program_options/program_options.hpp"
#include "code/utilities/formats/json/converters/json_file_io.hpp"
#include "code/programs/ide/global_actions/save_state_serializer.hpp"
#include "code/utilities/code/save/state_to_code_converter.hpp"
#include "code/utilities/code/save/save_state_loader.hpp"

int main(int argc, char** argv){

    //get program options
    Program_Options po = Program_Options(argc,argv);
    
    //std::cout << po.Input_File() << std::endl;
    //std::cout << po.Output_File() << std::endl;

    //read
    auto elements = Save_State_Loader::Load(po.Input_File());
    
    //convert
    auto code = State_To_Code_Converter::Convert(elements);
    
    //write
    Json_File_Io::Write_Json_To_File(code,po.Output_File());
    
}
