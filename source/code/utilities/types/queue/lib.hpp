#pragma once
#include <queue>
#include <set>
#include <vector>
#include <unordered_set>
#include "code/utilities/types/sets/lib.hpp"

template <typename T>
T Pop_Front(std::queue<T> & q){
    T x = q.front();
    q.pop();
    return x;
}

template <typename T, typename Fun>
void Observe_Each_Item_In_Queue_Avoiding_Duplicates(std::queue<T> & q, Fun fun){
    
    std::set<T> seen;
    while (!q.empty()){
        auto next = Pop_Front(q);
        if (!Exists_In_Set(seen,next)){
            seen.insert(next);
            fun(q,next);
        }
    }
    
}

template <typename T>
void Add(std::queue<T> & q, std::vector<T> const& v){
    for (auto const & it: v){
        q.push(it);
    }
}
