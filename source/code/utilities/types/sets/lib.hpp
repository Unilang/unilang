#pragma once
#include <set>
#include <unordered_set>
#include <iostream>

//forward declerations
template <typename T>
void Add_To_Set(std::set<T> & s, T const& item_to_add);

template <typename T>
void Delete_From_Set(std::set<T> & s, T const& item_to_delete);

template <typename T>
bool Exists_In_Set(std::set<T> const& s, T const& item);

template <typename T>
bool Exists_In_Set(std::unordered_set<T> const& s, T const& item);

//int Get_From_Set_Add_Assumed_Zero_If_Missing(std::set<int> const& s, int const& item);

template <typename T>
void Print_On_Each_Line(std::set<T> const& s);

//functions
template <typename T>
void Add_To_Set(std::set<T> & s, T const& item_to_add){
  s.insert(item_to_add);
}

template <typename T>
void Delete_From_Set(std::set<T> & s, T const& item_to_delete){
  if (Exists_In_Set(s,item_to_delete)){
    s.erase(s.find(item_to_delete));
  }
}

template <typename T>
bool Exists_In_Set(std::set<T> const& s, T const& item){
  return s.count(item);
}
template <typename T>
bool Exists_In_Set(std::unordered_set<T> const& s, T const& item){
  return s.count(item);
}

template <typename T>
void Print_On_Each_Line(std::set<T> const& s)
{
    for (auto const& it: s){
        std::cout << it << '\n';
    }
}
