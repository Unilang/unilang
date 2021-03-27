#include <iostream>
#include "code/programs/reflexivity/target_build_file_refresher.hpp"
#include "code/programs/reflexivity/settings/reflexive_refresh_settings_getter.hpp"


int main(int argc, char** argv){
    
    auto settings = Reflexive_Refresh_Settings_Getter::Get();
    Target_Build_File_Refresher::Refresh(settings);
}