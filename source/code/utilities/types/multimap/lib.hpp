#pragma once
#include <map>
#include <vector>

template <typename T>
std::map<T,std::vector<T>> Convert_To_Map(std::multimap<T,T> map){
    std::map<T,std::vector<T>> results;
    
    for(auto it = map.begin(), end = map.end(); it != end; ++it)
    {
      results[it->first].emplace_back(it->second);
    }

    return results;
}

template <typename T>
std::multimap<T,T> Convert_To_Mulimap(std::map<T,std::vector<T>> map){
    std::multimap<T,T> results;
    for (auto const& it: map){
        for (auto const& val: it.second){
            results.insert({it.first,val});
        }
    }
    return results;
}