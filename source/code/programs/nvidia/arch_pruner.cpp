#include <iostream>
#include "code/utilities/formats/objects/tgz_cuda_arch_pruner.hpp"
#include "code/utilities/formats/objects/arch_prune_settings.hpp"
#include "code/programs/nvidia/program_options/program_options.hpp"

int main(int const argc, char** const argv){
    
    //create arch prune settings
    Program_Options program_options(argc, argv);
    Arch_Prune_Settings settings;
    settings.file_name = program_options.File();
    settings.keep_archs = program_options.Keep();
    settings.skip_archs = program_options.Skip();
    
    Tgz_Cuda_Arch_Pruner::Prune(settings);
}
