#include <iostream>
#include "nlohmann/json.hpp"
#include "code/utilities/formats/json/patching/json_patch_builder.hpp"

//making certain adjustments to a list of sub json objects did not seem possible
//with the json patch and json pointer mechanisms.  Imagine a case where extra nesting is added to
//a data structure, and that data structure exists in a list of the overall json object.
//maybe fixing a previously saved json object would best be done by directly iterating and editing it
int main(){

    
    nlohmann::json original = R"({
  "baz": [{ "element": "one" }, { "element": "two" }, { "element": "three" }],
  "foo": "bar"
})"_json;
    
    //before
    std::cout << original.dump(2) << std::endl;
    
    //adjust nesting
    for (auto & it: original["baz"].items()){
        for (auto & it2: it.value().items()){
            
            nlohmann::json nested;
            nested["new"] = it2.value();
            it2.value() = nested;
            //std::cout << it2.key() << " " << it2.value() << std::endl;
        }
    }
    
    //after
    std::cout << original.dump(2) << std::endl;
    
}