//This allows serializing trees to/from json
#pragma once
#include <string>
#include <iostream>
#include "nlohmann/json.hpp"
#include <sstream>
#include "src/tree.hh"
#include "code/utilities/types/tree/converters/depth_list.hpp"

//overloads for nlohmann json serialization
//we can't serialize the tree directly because it will lose the depth information.
//we instead, convert it to a depth list, and serialize between that.
template <typename T>
void to_json(nlohmann::json& j, tree<T> const& tr) {
    auto depth_list = to_depth_list(tr);
    j = depth_list;
}

template <typename T>
void from_json(const nlohmann::json& j, tree<T> & tr) {
    
     auto depth_list = j.get<std::vector<std::pair<int,T>>>();
     
     //If I assign directly to tr we segfault
     //https://github.com/kpeeters/tree.hh/issues/4
     tr = from_depth_list(depth_list);
}
