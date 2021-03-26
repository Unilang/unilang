#include <iostream>
#include <utility>
#include "code/examples/unilang/hello_world/hello_world_json_data_getter.hpp"
#include "code/utilities/streams/filestreams/read_all/lib.hpp"

int main(){
    
    std::cout << Read_Entire_File_Into_String(Hello_World_Json_Data_Getter::Get()) << std::endl;
    
}