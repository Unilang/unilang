#include <iostream>
#include <string>
#include "code/programs/transcompilers/enum_cpp/enum_cpp_maker.hpp"
#include "code/programs/transcompilers/enum_cpp/enum.hpp"
#include "code/programs/transcompilers/enum_cpp/program_options/program_options_creator.hpp"

int main(int argc, char** argv){

	//get program options
    auto po = Program_Options_Creator::Create(argc,argv);

    //build enum
    Enum e;
    e.name = po.Enum_Name();
    e.values = po.Enum_Values();

    //store it
    std::vector<Enum> enums;
    enums.emplace_back(e);

    auto path_name = po.Enum_Name();
    if (!po.Output_Path().empty()){
    	path_name = po.Output_Path() + "/" + path_name;
    }

    //build it
    Enum_Cpp_Maker::Create_Enums_Header(path_name,enums);
    Enum_Cpp_Maker::Create_Enums_Source(path_name,enums);

}
