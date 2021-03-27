#include <iostream>
#include "code/programs/gcalviz/gcalviz_runner.hpp"
#include "code/programs/gcalviz/meta_settings.hpp"

int main(int const argc, char** const argv){
    
    Meta_Settings meta;
    meta.program_name = "gcalviz";
    Gcalviz_Runner::Run(meta);
}