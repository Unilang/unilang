#include <iostream>
#include "code/utilities/assets/chrome_drivers.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"

int main(){
    
    
    for (auto const& it: Get_Everything_At_Path(Chrome_Drivers::Folder_Of_Drivers())){
        std::cout << it << std::endl;
    }
}