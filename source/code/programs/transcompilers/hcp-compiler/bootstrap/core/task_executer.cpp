#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/task_executer.hpp"
#include "code/utilities/program/common_actions/exits/lib.hpp"
#include "code/utilities/types/strings/observers/path/lib.hpp"
#include "code/utilities/filesystem/files/observers/lstat_wrap/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/parser/lib.hpp"
#include "code/programs/transcompilers/hcp-compiler/bootstrap/core/compiler/lib.hpp"

 void Task_Executer::Execute_Needed_Tasks(Program_Options const& program_options){
     //process each file at a time
     for (auto const& hcp_file: program_options.Input_Files()){
      
        //exit if anything is initially wrong with the file name sent to the compiler
        Immediate_Checks_On_Filename_Sent_To_Compiler(hcp_file);

        //parse the hcp file and get back a class that represents it
        auto structure = Hcp_Parser::Parse(hcp_file);
    
        //compile that structure into the appropriate files (hcp -> hpp and cpp)
        Hcp_Compiler::Compile(structure,program_options.Output_Directory(),program_options.Utility_Functions());
  }
}

 void Task_Executer::Immediate_Checks_On_Filename_Sent_To_Compiler(std::string const& file_name){

    //file must be a .hcp file
    if (Get_File_Extension(file_name) != "hcp"){
        Exit_With_Error(file_name + " must have a .hcp file extension");
    }

    //file must exist
    if (!File_Exists(file_name)){
        Exit_With_Error(file_name + " not found");
    }
}