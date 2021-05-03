#include <iostream>
#include "code/programs/repo_tools/repo_stats/task_executer.hpp"
#include "code/programs/repo_tools/repo_stats/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/main/catching_main.hpp"


int main(int const argc, char** const argv){
    
    return Catching_Main::Run([&](){
        Program_Options program_options(argc, argv);
        Task_Executer::Execute_Needed_Tasks(program_options);
        return 0;
    });
}

