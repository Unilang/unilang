#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/compiler/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/class_compiler/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/global_compiler/lib.hpp"
#include "code/utilities/program/common_actions/exits/lib.hpp"






 void Hcp_Compiler::Compile(Class_Structure const& structure, std::string const& directory, bool const& utility_functions){

  if (structure.File_Type() == L"class"){
    Class_Compiler::Compile_HCP_File(structure,directory,utility_functions);
  }
  else if (structure.File_Type() == L"global"){
    Global_Compiler::Compile_HCP_File(structure);
  }
  else{
    Exit_With_Error(structure.File_Name() + ": invalid file type given on first line");
  }

}
