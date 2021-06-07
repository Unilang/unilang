#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include "code/utilities/types/strings/transformers/casing/lib.hpp"
#include "code/utilities/data_structures/index_mode.hpp"
#include "code/utilities/data_structures/index/moded_index.hpp"
#include "code/utilities/types/map/lib.hpp"
#include "code/utilities/language_basic/std_hackery/std_aliases.hpp"
#include "code/utilities/math/gmp/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"

template<typename T>
T Index_Into_Available_Container(std::vector<T> & t, string_map & extra, std::string index){
    if (greater_equal(index,"0") && less_than(index,std::to_string(t.size()))){
        return t[as_signed(index)];
    }
    //std::cout << "geting map" << std::endl;
    return Get_Value_Add_Zero_If_Missing(extra,index);
}
template<typename T>
void Set_Index_Into_Available_Container(std::vector<T> & t, string_map & extra, std::string index, std::string value){
    if (greater_equal(index,"0") && less_than(index,std::to_string(t.size()))){
        t[as_signed(index)] = value;
        return;
    }
    Add_To_Map(extra,index,value);
    return;
}



//directly / indirectly indexing into a vector
template<typename T>
T Get_Position_Mode_Index(std::vector<T> & t, string_map & extra, std::string index){
    
  //std::cout << "position index with: " << index << std::endl;
  auto new_index = Index_Into_Available_Container(t,extra,index);
  return Index_Into_Available_Container(t,extra,new_index);
  
}
template<typename T>
T Get_Immediate_Mode_Index(std::vector<T> & t, string_map & extra, std::string index){
  //std::cout << "immediate index with: " << index << std::endl;
  return Index_Into_Available_Container(t,extra,index);
}
template<typename T>
T Get_Relative_Mode_Index(std::vector<T> & t, string_map & extra, std::string index, std::string base){
  
  auto start_index = Index_Into_Available_Container(t,extra,index);
  auto derived_index = add_big_numbers(base,start_index);
  return Index_Into_Available_Container(t,extra,derived_index);
    
    //auto offset = add_big_numbers(index,base);
    //std::cout << index << " " << base << std::endl;
    //auto new_index = Index_Into_Available_Container(t,extra,offset);
    //return Index_Into_Available_Container(t,extra,offset);
}
template<typename T>
void Set_Position_Mode_Index(std::vector<T> & t, string_map & extra, std::string index, std::string set_value){
    
    auto new_index = Index_Into_Available_Container(t,extra,index);
    Set_Index_Into_Available_Container(t,extra,new_index,set_value);
}
template<typename T>
void Set_Immediate_Mode_Index(std::vector<T> & t, string_map & extra, std::string index, std::string set_value){
  
    Set_Index_Into_Available_Container(t,extra,index,set_value);
}
template<typename T>
void Set_Relative_Mode_Index(std::vector<T> & t, string_map & extra, std::string index, std::string base, T set_value){
    
    //std::cout << index << " " << base << std::endl;
    //auto offset = add_big_numbers(index,base);
    //auto new_index = Index_Into_Available_Container(t,extra,offset);
    //Set_Index_Into_Available_Container(t,extra,offset,set_value);
    
    auto start_index = Index_Into_Available_Container(t,extra,index);
    auto derived_index = add_big_numbers(base,start_index);
    Set_Index_Into_Available_Container(t,extra,derived_index,set_value);
    std::cout << derived_index << " = " << set_value << std::endl;
}




template<typename T>
T Get_Mode_Index(std::vector<T> & t, string_map & extra, std::string index, std::string base, Index_Mode mode){
    
    if (mode == Index_Mode::POSITION){ return Get_Position_Mode_Index(t,extra,index); }
    if (mode == Index_Mode::IMMEDIATE){ return Get_Immediate_Mode_Index(t,extra,index); }
    if (mode == Index_Mode::RELATIVE){ return Get_Relative_Mode_Index(t,extra,index, base); }
    //if (mode == Index_Mode::RELATIVE){ return Get_Immediate_Mode_Index(t,extra,index); }
    
    std::cout << "unknown" << std::endl;
    return Get_Immediate_Mode_Index(t,extra,index);
}
template<typename T>
void Set_Mode_Index(std::vector<T> & t, string_map & extra, std::string index, std::string base, Index_Mode mode, std::string set_value){
    
    if (mode == Index_Mode::POSITION){ return Set_Position_Mode_Index(t,extra,index,set_value); }
    if (mode == Index_Mode::IMMEDIATE){ return Set_Immediate_Mode_Index(t,extra,index,set_value); }
    if (mode == Index_Mode::RELATIVE){ return Set_Relative_Mode_Index(t,extra,index, base,set_value); }
    //if (mode == Index_Mode::RELATIVE){ return Set_Immediate_Mode_Index(t,extra,index,set_value); }
    
    std::cout << "unknown" << std::endl;
    return;
}





//treating the vector as addressable memory or with an artificial program counter
template<typename T>
void Position_Mode_Set_Input(std::vector<T> & t, T & pc){
    T input;
    std::cout << "input: ";
    std::cout.flush();
    std::cin >> input;
    //Set_Mode_Index(t,extra,add_big_numbers(pc,"1"),"0",Index_Mode::POSITION,input);
    pc = add_big_numbers(pc,"2");
}


template<typename T>
void Position_Mode_Print(std::vector<T> & t, T & pc){
    //std::cout << Get_Position_Mode_Index(t,add_big_numbers(pc,"1")) << std::endl;
    pc = add_big_numbers(pc,"2");
}
template<typename T>
void Mode_Print(std::vector<T> & t, T & pc, Index_Mode m){
    //std::cout << Get_Mode_Index(t,add_big_numbers(pc,"1"),"0",m) << std::endl;
    pc = add_big_numbers(pc,"2");
}


//main op codes
template<typename T>
void Mode_Set(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, T const& input){
    Set_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1,input);
    pc = add_big_numbers(pc,"2");
}
template<typename T>
T Mode_Get(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m){
    auto val = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m);
    pc = add_big_numbers(pc,"2");
    //std::cout << "get: " << val << std::endl;
    return val;
}
template<typename T>
void Mode_Linear_Addition(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, Index_Mode m2, Index_Mode m3){
    auto a = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1);
    auto b = Get_Mode_Index(t,extra,add_big_numbers(pc,"2"),relative_base,m2);
    Set_Mode_Index(t,extra,add_big_numbers(pc,"3"),relative_base,m3,add_big_numbers(a,b));
    pc = add_big_numbers(pc,"4");
    //std::cout << "add: " << a << " " << b << std::endl;
}
template<typename T>
void Mode_Linear_Multiply(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, Index_Mode m2, Index_Mode m3){
    auto a = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1);
    auto b = Get_Mode_Index(t,extra,add_big_numbers(pc,"2"),relative_base,m2);
    Set_Mode_Index(t,extra,add_big_numbers(pc,"3"),relative_base,m3,multiply_big_numbers(a,b));
    pc = add_big_numbers(pc,"4");
    //std::cout << "mult: " << a << " " << b << std::endl;
}
template<typename T>
void Mode_Jump_If_True(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, Index_Mode m2){
    auto a = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1);
    auto b = Get_Mode_Index(t,extra,add_big_numbers(pc,"2"),relative_base,m2);
    if (a != "0"){
        pc = b;
    }
    else{
        pc = add_big_numbers(pc,"3");
    }
    //std::cout << "jump_if_true" << std::endl;
}
template<typename T>
void Mode_Jump_If_False(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, Index_Mode m2){
    auto a = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1);
    auto b = Get_Mode_Index(t,extra,add_big_numbers(pc,"2"),relative_base,m2);
    if (a == "0"){
        pc = b;
    }
    else{
        pc = add_big_numbers(pc,"3");
    }
    //std::cout << "jump_if_false" << std::endl;
}
template<typename T>
void Mode_Jump_Less_Than(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, Index_Mode m2, Index_Mode m3){
    auto a = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1);
    auto b = Get_Mode_Index(t,extra,add_big_numbers(pc,"2"),relative_base,m2);
    if (less_than(a,b)){
        Set_Mode_Index(t,extra,add_big_numbers(pc,"3"),relative_base,m3,"1");
    }
    else{
        Set_Mode_Index(t,extra,add_big_numbers(pc,"3"),relative_base,m3,"0");
    }
    pc = add_big_numbers(pc,"4");
    //std::cout << "jump_less_than" << std::endl;
}
template<typename T>
void Mode_Jump_Equals(std::vector<T> & t, string_map & extra, T & pc, T & relative_base, Index_Mode m1, Index_Mode m2, Index_Mode m3){
    auto a = Get_Mode_Index(t,extra,add_big_numbers(pc,"1"),relative_base,m1);
    auto b = Get_Mode_Index(t,extra,add_big_numbers(pc,"2"),relative_base,m2);
    if (a == b){
        Set_Mode_Index(t,extra,add_big_numbers(pc,"3"),relative_base,m3,"1");
        //std::cout << "jump_equals=true" << std::endl;
    }
    else{
        Set_Mode_Index(t,extra,add_big_numbers(pc,"3"),relative_base,m3,"0");
        //std::cout << "jump_equals=false" << std::endl;
    }
    pc = add_big_numbers(pc,"4");
}
