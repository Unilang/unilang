#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/global_parser/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/global_structure_creator/lib.hpp"






 Class_Structure Hcp_Global_Parser::Parse(std::wifstream & infile, std::string const& hcp_file, std::wstring const& file_type){
    
    Global_Structure_Creator creator(hcp_file);
    auto structure = creator.Create(infile,file_type);
    return structure;
}
