#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/global_compiler/lib.hpp"
#include "code/utilities/types/strings/observers/other/lib.hpp"
#include "code/utilities/types/strings/transformers/removing/lib.hpp"
#include "code/utilities/types/wstrings/transformers/trimming/lib.hpp"
#include "code/utilities/types/wstrings/transformers/other/lib.hpp"








 void Global_Compiler::Compile_HCP_File(Class_Structure const& structure){

    //use the structure to print the cpp and hpp versions of the file
    std::wofstream hpp_stream(As_Removed_Suffix(structure.Path_To_File_Name()) + ".hpp");
    std::wofstream cpp_stream(As_Removed_Suffix(structure.Path_To_File_Name()) + ".cpp");

    auto str = As_Removed_Suffix(structure.File_Name());
    std::wstring wstr(str.begin(),str.end());
    cpp_stream << "#include " << '"' << wstr << ".hpp" << '"' << '\n';
    hpp_stream << "#pragma once\n";
    Print_Include_Files(hpp_stream,structure.Header_Includes());
    Print_Include_Files(cpp_stream,structure.Source_Includes());
    hpp_stream << '\n';
    cpp_stream << '\n';

    //dump hpp code wrapped in class name
    Dump_HPP(hpp_stream,structure,structure.File_Name());

    //dump cpp
    cpp_stream << structure.CPP_Code();
}

 void Global_Compiler::Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes){

    for (auto it: includes){
        if (it.second){
            outfile << "#include ";
            if (Begins_And_Ends_With(it.first,L'"')){
                outfile << As_Last_Char_Removed(it.first) << ".hpp\"";
            }else{
                outfile << "<" << it.first << ">";
            }
            outfile << '\n';
        }
    }
}

 void Global_Compiler::Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file){

    //dump
    outfile << structure.HPP_Code();
    
}



