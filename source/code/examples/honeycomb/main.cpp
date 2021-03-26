#include <iostream>
#include <string>
#include "code/utilities/web/honeycomb/honeycomb_poster.hpp"

int main(){
    
    
    std::string dataset = "https://api.honeycomb.io/1/events/compilation_speed";
    std::string api_key = "<ADD>";
    std::string data = "{\"shard\":\"users\",\"dur_ms\":33}";
    std::cout << Honeycomb_Poster::Post(dataset,api_key,data) << std::endl;
}