#include <iostream>
#include <string>
#include "code/utilities/program/common_actions/locale/lib.hpp"
#include "code/programs/reflexivity/publish/software/software_deployer.hpp"

int main(int argc, char** argv){
    Set_English_UTF8_Locale();
    
    //things to export out of the repository
    Software_Deployer::Deploy();
}