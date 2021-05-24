#pragma once
#include <string>
#include <utility>
#include <sstream>
#include "src/tree.hh"

// convert a tree to/from a "depth list"
// a "depth list" represents the nodes in a preorder list with their depths attached
// this makes it easy to serialize the tree since it will exclude the pointers
// Be careful not to serialize a tree directly with nlohmann::json, because it will use
// the iterators and lose the depth and store it incorrectly.
// these functions are intended to be used in nlohmann::json's custom serialize functions.
template <typename T>
std::vector<std::pair<int,T>> to_depth_list(tree<T> const& tr){
    std::vector<std::pair<int,T>> depth_list;
    for (auto it = tr.begin(); it != tr.end(); ++it){
        auto depth = tr.depth(it);
        T obj = *it;
        depth_list.emplace_back(std::pair<int,T>{depth,obj});
    }
    return depth_list;
}
template <typename T>
tree<T> from_depth_list(std::vector<std::pair<int,T>> const& depth_list){
    tree<T> tr;
    auto top = tr.begin();
    auto current_node = tr.begin();
    int previous_depth = 0;
    for (auto const& it: depth_list){
        
        //at root
        if (it.first == 0){
            current_node = tr.insert(top,it.second);
        }
        
        //go deeper
        else if (previous_depth < it.first){
            current_node = tr.append_child(current_node,it.second);
            
        }
        //climb higher
        else {
            while (previous_depth >= it.first){
                current_node = tr.parent(current_node);
                previous_depth--;
            }
            current_node = tr.append_child(current_node,it.second);
        }
        previous_depth = it.first;
    }
    return tr;
}
