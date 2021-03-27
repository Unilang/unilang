#include <iostream>
#include <string>
#include <fstream>
#include "code/programs/transcompilers/data_getter/program_options/program_options.hpp"
#include "code/programs/transcompilers/hcp-compiler/programatic/data/code.hpp"
#include "code/programs/transcompilers/hcp-compiler/programatic/code_getter.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"


//a program that exports an hcp file for getting a particular path to a data file
//this is useful inside bazel rules for making sure data can be accessed through code, and to ensure
//that code which uses this generated API does not break.
Code Build_Code(Program_Options const& po){

    Code x;
    
    x.headers.public_headers.emplace_back("string");
    
    //TODO is there an easy generic safe reliable way to get the correct relative path to data?
    std::string path_to_data = po.Input_File();
    Remove_Everything_Before_Found_Instance(path_to_data,"bin/");
    
    Function f;
    f.name = "Get";
    f.return_val = "std::string";
    f.body += "return ";
    f.body += "\"";
    f.body += path_to_data;
    f.body += "\"";
    f.body += ";";
    
    x.functions.emplace_back(f);
    
    return x;
}

void Write_Output(std::string const& output_file, std::wstring const& file_content){
    std::wofstream outfile(output_file);
    outfile << file_content;
    outfile.close();
}

int main(int argc, char** argv){
    
    //Unicode please
    Set_English_UTF8_Locale();

    //get program options
    Program_Options po = Program_Options(argc,argv);
    
    Code x = Build_Code(po);
    
    auto text = Code_Getter::Get(x);
    
    Write_Output(po.Output_File(),text);
    
}