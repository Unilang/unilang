#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/parser/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/class_parser/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/global_parser/lib.hpp"
#include "code/utilities/program/common_actions/exits/lib.hpp"









 Class_Structure Hcp_Parser::Parse(std::string const& hcp_file){

    //strip off the top part of the file
    std::wstring file_type;
    std::wifstream infile(hcp_file);
    std::getline(infile,file_type);
    
    //decide which parser to call
    if (file_type == L"class"){
      return Hcp_Class_Parser::Parse(infile,hcp_file,file_type);
    }
    else if(file_type != L"global"){
        Exit_With_Error("unknown hcp file type");
    }
    
    return Hcp_Global_Parser::Parse(infile,hcp_file,file_type);

}