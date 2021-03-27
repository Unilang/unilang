#include <iostream>
#include "code/programs/deskstock/deskstock_runner.hpp"
#include "code/programs/deskstock/meta_settings.hpp"

int main(int const argc, char** const argv){
    
    //should probably do prog args and stuff
    
    Meta_Settings meta;
    meta.program_name = "deskstock";
    Deskstock_Runner::Run(meta);
}
