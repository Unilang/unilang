#include <iostream>
#include "nlohmann/json.hpp"
#include "code/utilities/formats/json/patching/json_patch_builder.hpp"

//this is an example of using some methods to build up a json patch.
//a json patch is described in this RFC: https://tools.ietf.org/html/rfc6902
int main(){
    

    //first we construct an example json patch according to:
    //https://tools.ietf.org/html/rfc6902#section-3
    nlohmann::json rfc_example = R"(
       [
         { "op": "test", "path": "/a/b/c", "value": "foo" },
         { "op": "remove", "path": "/a/b/c" },
         { "op": "add", "path": "/a/b/c", "value": [ "foo", "bar" ] },
         { "op": "replace", "path": "/a/b/c", "value": 42 },
         { "op": "move", "from": "/a/b/c", "path": "/a/b/d" },
         { "op": "copy", "from": "/a/b/d", "path": "/a/b/e" }
       ]
       
    )"_json;
    
    //then we build the same thing using helper methods
    nlohmann::json patches;
    Json_Patch_Builder::Add_Test_Patch(patches,"/a/b/c","foo");
    Json_Patch_Builder::Add_Remove_Patch(patches,"/a/b/c");
    Json_Patch_Builder::Add_Add_Patch(patches,"/a/b/c",std::vector<std::string>{"foo", "bar"});
    Json_Patch_Builder::Add_Replace_Patch(patches,"/a/b/c",42);
    Json_Patch_Builder::Add_Move_Patch(patches,"/a/b/c","/a/b/d");
    Json_Patch_Builder::Add_Copy_Patch(patches,"/a/b/d","/a/b/e");
    
    //see the results
    std::cout << patches.dump(2) << std::endl;
    
    //ensure that we are matching the format of the RFC
    if (rfc_example == patches){
        std::cout << "match" << std::endl;
    }
    else{
        std::cout << "DOES NOT match" << std::endl;
    }
}