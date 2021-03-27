#include <locale>
#include "code/programs/transcompilers/hcp-compiler/official/program_options/program_options_creator.hpp"
#include "code/programs/transcompilers/hcp-compiler/official_pos/task_executer.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"

int main(int const argc, char** const argv) {

    //Unicode please
    Set_English_UTF8_Locale();

    //get program options from command line
    auto program_options = Program_Options_Creator::Create(argc, argv);
        
    //continue on to process the file
    Task_Executer::Execute_Needed_Tasks(program_options);

    return EXIT_SUCCESS;
}