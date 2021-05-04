#pragma once
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <functional>


//TODO: turn into global functions
template <typename T>
class Unique_Counter{
  
  public:
  std::map<T,int> hash_table;
  
  void Add(T const& t){
    auto search = hash_table.find(t);
    if(search != hash_table.end()) {
      search->second++;
    }
    else{
      hash_table.emplace(t,1);
    }
  }
  
  void Add_Empty(T const& t){
    hash_table.emplace(t,0);
  }
  
  size_t Number_Of_Unique_Entries() const{
    return hash_table.size();
  }
  
  T Most_Common() const{
    auto it = std::max_element(hash_table.begin(),hash_table.end(),[](auto x, auto y){
      return x.second < y.second;
    });
    return it->first;
  }
  
  T Least_Common() const{
    auto it = std::min_element(hash_table.begin(),hash_table.end(),[](auto x, auto y){
      return x.second < y.second;
    });
    return it->first;
  }
  
  std::vector<std::pair<int,T>> Top_N_Most_Common(int amount) const{
    auto q = Convert_To_P_Queue();
    
    std::vector<std::pair<int,T>> results;
    for (size_t i = 0; i < amount && !q.empty(); ++i){
      
      auto p = q.top();
      q.pop();
      results.emplace_back(p);
    }
    return results;
  }
  
  template <typename Fun>
  std::vector<std::pair<int,T>> Top_N_Most_Common_Passing_Predicate(int amount, Fun fun) const{
    auto q = Convert_To_P_Queue();
    
    std::vector<std::pair<int,T>> results;
    for (size_t i = 0; i < amount && !q.empty();){
      
      auto p = q.top();
      q.pop();
      
      if (fun(p.second)){
        results.emplace_back(p);
        ++i;
      }
    }
    return results;
  }
  
private:
  std::priority_queue<std::pair<int,T>> Convert_To_P_Queue() const {
    std::priority_queue<std::pair<int,T>> q;
    
    for (auto const& it: hash_table){
      auto add = std::make_pair(it.second,it.first);
      q.push(add);
    }
    return q;
  }
  
};
