#pragma once
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
#include <random>
#include <utility>
#include <optional>

std::string Get_As_Comma_Seperated_String(std::vector<std::string> strs);
std::string Get_As_Space_Seperated_String(std::vector<std::string> strs);
std::string Get_As_Newline_Seperated_String(std::vector<std::string> strs);
std::string Table_As_Column_Aligned(std::vector<std::vector<std::string>> table);
size_t Longest_Element_Size(std::vector<std::string> strs);
bool An_Element_Ends_With(std::vector<std::string> const& strs, std::string const& str);


template <class T>
bool All_Elements_Unique(std::vector<T> &x) {
    std::sort( x.begin(), x.end() ); // O(N log N)
    return std::adjacent_find( x.begin(), x.end() ) == x.end();
}

template <typename T, typename Fun>
void Compare_All_2_Elements(std::vector<T> const& v, Fun fun){
  for (size_t i = 0; i < v.size(); ++i){
    for (size_t j = 0; j < v.size(); ++j){
      if (i != j){
        auto should_return = fun(v[i],v[j]);
        if (should_return){
          return;
        }
      }
    }
  }
}

template <typename T, typename Fun>
void Compare_All_3_Elements(std::vector<T> const& v, Fun fun){
  for (size_t i = 0; i < v.size(); ++i){
    for (size_t j = 0; j < v.size(); ++j){
      for (size_t k = 0; k < v.size(); ++k){
        std::vector<T> temp {static_cast<int>(i),static_cast<int>(j),static_cast<int>(k)};
        if (All_Elements_Unique(temp)){
          auto should_return = fun(v[i],v[j],v[k]);
          if (should_return){
            return;
          }
        }
      }
    }
  }
}


template <typename T>
std::vector<T> Find_2_Elements_That_Sum_To(std::vector<T> const& v, T sum){
  std::vector<T> results;
  Compare_All_2_Elements(v,[&](T x, T y){
      if (x + y == sum){
        results.emplace_back(x);
        results.emplace_back(y);
        return true;
      }
      return false;
  });
  return results;
}

template <typename T>
std::vector<T> Find_3_Elements_That_Sum_To(std::vector<T> const& v, T sum){
  std::vector<T> results;
  Compare_All_3_Elements(v,[&](T x, T y, T z){
      if (x + y + z == sum){
        results.emplace_back(x);
        results.emplace_back(y);
        results.emplace_back(z);
        return true;
      }
      return false;
  });
  return results;
}


template <typename T>
size_t Next_Index_In_Round_Robin(T const& t, size_t const& i){
  if (i == t.size()-1){
    return 0;
  }
  return i+1;
}
template <typename T>
size_t Previous_Index_In_Round_Robin(T const& t, size_t const& i){
  if (i == 0){
    return t.size()-1;
  }
  return i-1;
}
template <typename T>
void Set_Next_Index_In_Round_Robin(T const& t, size_t & i){
  i = Next_Index_In_Round_Robin(t,i);
}
template <typename T>
void Set_Previous_Index_In_Round_Robin(T const& t, size_t & i){
  i = Previous_Index_In_Round_Robin(t,i);
  
}


template <typename T>
size_t Longest_Element_Size_Of_Pair_First(std::vector<std::pair<std::string,T>> const& strs){
  int size = 0;
  for (auto const& it: strs){
    if (it.first.size() > size){
      size = it.first.size();
    }
  }
  return size;
}

template <typename T>
size_t Longest_Element_Size_Of_Pair_Second(std::vector<std::pair<T,std::string>> const& strs){
  int size = 0;
  for (auto const& it: strs){
    if (it.second.size() > size){
      size = it.second.size();
    }
  }
  return size;
}

template <typename T>
size_t Largest_Element_Size_Of_Pair_First(std::vector<std::pair<int,T>> const& strs){
  int val = 0;
  for (auto const& it: strs){
    if (it.first > val){
      val = it.first;
    }
  }
  return val;
}

template <typename T>
size_t Largest_Element_Size_Of_Pair_Second(std::vector<std::pair<T,int>> const& strs){
  int val = 0;
  for (auto const& it: strs){
    if (it.second > val){
      val = it.second;
    }
  }
  return val;
}

template <typename T, typename U>
std::vector<T> Take_Firsts(std::vector<std::pair<T,U>> const& v){
  std::vector<T> x;
  for (auto const& it: v){
    x.emplace_back(it.first);
  }
  return x;
}
template <typename T, typename U>
std::vector<U> Take_Seconds(std::vector<std::pair<T,U>> const& v){
  std::vector<U> x;
  for (auto const& it: v){
    x.emplace_back(it.second);
  }
  return x;
}


template<typename T>
size_t Get_Index_Of_Element(std::vector<T> const& v, T const& element){
    return std::find(v.begin(), v.end(), element) - v.begin();
}

template<typename T>
int Get_Index_Of_Element_If_Exists(std::vector<T> const& v, T const& element){
    auto found = std::find(v.begin(), v.end(), element);
    if (found == std::end(v)){
      return -1;
    }
    return found - v.begin();
}

template<typename T>
bool Safe_Is_Index_Equal(std::vector<T> const& v, int i, T t){
  
  //out of range
  if (i < 0 || i >= v.size()){
    return false;
  }
  
  //in range, make check
  return v[i] == t;
}

template<typename T>
T Safe_Index_Get(std::vector<T> const& v, int i, T if_missing){
  
  //out of range
  if (i < 0 || i >= v.size()){
    return if_missing;
  }
  
  //in range, get
  return v[i];
}

template<typename T>
T& Safe_Index_Capped(std::vector<T> & v, int i){
  
  //out of range
  if (i < 0){
    return v[0];
  }
  if (i >= v.size()){
    return v[v.size()-1];
  }
  
  //in range, get
  return v[i];
}

template<typename T>
size_t Adjust_Index_Capped(std::vector<T> const& v, int i){
  //out of range
  if (i < 0){
    return 0;
  }
  if (i >= v.size()){
    return v.size()-1;
  }
  
  //in range, get
  return i;
}

template<typename T>
T Last_Element(std::vector<T> const& v){
    return v.back();
}
template<typename T>
T& Modifiable_Last_Element(std::vector<T> & v){
    return v.back();
}
template<typename T>
T& Safe_Modifiable_Last_Element(std::vector<T> & v){
    if (v.empty()){
      v.emplace_back(T{});
    }
    return v.back();
}
template<typename T>
T& Add_Modifiable_Last_Element(std::vector<T> & v){
    v.emplace_back(T{});
    return v.back();
}
template<typename T>
T Second_To_Last_Element(std::vector<T> const& v){
    return v[v.size()-2];
}
template<typename T>
T First_Element(std::vector<T> const& v){
    return v.front();
}
template<typename T>
T First_Element_Or(std::vector<T> const& v, T const& val_if_empty){
    if (!v.empty()){
      return v.front();
    }
    return val_if_empty;
}
template<typename T>
T First_Element_Or_Default(std::vector<T> const& v){
    if (!v.empty()){
      return v.front();
    }
    return T{};
}

template <class T>
std::vector<T> Flatten(std::vector<std::vector<T>> const& v){
  std::vector<T> results;
  for (auto const& it: v){
    results.insert(results.end(), it.begin(), it.end());
  }
  
  return results;
}

template<typename T>
T Flatten(std::vector<T> const& v){
	T t;
	for (auto const& it: v){
		t += it;
	}
	return t;
}

std::vector<std::string> Each_Element_As_Space_Seperated_String(std::vector<std::vector<std::string>> const& v);

template<typename T>
bool The_Same_Except_For_One_Element(std::vector<T> const& v1, std::vector<T> const& v2){
	int differences = 0;
	
	if (v1.size() != v2.size()){
		return false;
	}
	
	for (int i = 0; i < v1.size(); ++i){
		if (v1[i].id != v2[i].id){
			differences++;
			if (differences > 1){
				return false;
			}
		}
	}
	
	
	
	if (differences == 1){
		return true;
	}
	return false;
}

template <typename T, typename Fun>
std::vector<T> Filter(std::vector<T> const& vec, Fun pred){
  std::vector<T> new_vec;
  for (auto const& it: vec){
    if (pred(it)){
      new_vec.emplace_back(it);
    }
  }
  
  return new_vec;
}


template<typename T>
const T& Get_Nth_Element(std::vector<T> const& container, size_t n) {
  return container[n];
}

template<typename T>
T& Get_Random_Element(std::vector<T> & container) {
	std::random_device random_device;
	std::mt19937 engine{random_device()};
	std::uniform_int_distribution<int> dist(0, container.size() - 1);
	return container[dist(engine)];
}

template <typename T>
bool In_Vector(std::vector<T> const& vec, T const& item){
    return std::find(vec.begin(), vec.end(), item) != vec.end();
}

template <typename T>
bool Vector_Contains_Any_Elements_In_Vector(std::vector<T> const& vec, std::vector<T> const& elements){
    for (auto const& it: elements){
        if (In_Vector(vec,it)){
            return true;
        }
    }
    return false;
}

bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str);
size_t Get_Longest_String_Length_In_Vector(std::vector<std::string> const& v);

template<typename T>
unsigned int Number_Of_Times_Element_Shows_Up_In_Vector(std::vector<T> const& vec, T const& t){
  unsigned int count = 0;
  for (auto it: vec){
    if (it == t){
      ++count;
    }
  }
  return count;
}

template <class T>
bool Contains_All_Unique_Items(const std::vector<T>& vec)
{
    std::set<T> test;
    for (typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        if (!test.insert(*it).second) {
            return false;
        }
    }
    return true;
}


template<class InputIt, class MemberType>
auto Destructure_Out_Vec_Of_Data_Member(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name){
  
  //not ideal, but works
  auto i = *first.*member_name;
  std::vector<decltype(i)> v;
  
  while(first != last){
    v.push_back(*first.*member_name);
    ++first;
  }
  
  return v;
}

template<class InputIt, class MemberType, class Value>
auto Get_First_Object_Whose_Data_Member_Matches_Value(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name, Value const& value){
  
  //not ideal, but works
  auto i = *first.*member_name;
  std::vector<decltype(i)> v;
  
  while(first != last){
    if (*first.*member_name == value){
    	return *first;
    }
    ++first;
  }
  
  return *first;
}

template <typename T>
std::vector<std::vector<T>> Split_Every_N(std::vector<T> const& v, size_t amount){
  std::vector<std::vector<T>> all;
  
  std::vector<T> temp;
  size_t current = 0;
  for (auto const& it: v){
    
    temp.emplace_back(it);
    ++current;
    
    if (current == amount){
      current = 0;
      all.emplace_back(temp);
      temp.clear();
    }
  }
  
  if (!temp.empty()){
    all.emplace_back(temp);
  }
  
  return all;
}

template <typename T>
std::vector<std::vector<T>> Split_Into_N_Parts(std::vector<T> const& v, size_t amount){
  std::vector<std::vector<T>> all;
  
  std::vector<T> temp;
  auto max_amount = (v.size() / amount);
  if (max_amount == 0){
    max_amount = 0;
  }
  
  for (auto const& it: v){
    temp.emplace_back(it);
    if (temp.size() >= max_amount){
      all.emplace_back(temp);
      temp.clear();
    }
  }
  
  if (!temp.empty()){
    all.emplace_back(temp);
  }
  
  return all;
  
}

template<class InputIt, class MemberType>
auto Split_By_Data_Member_Uniqueness(InputIt first, InputIt last, MemberType std::iterator_traits<InputIt>::value_type::* member_name){

  //would like to no need to instantiate i here
  auto i = *first.*member_name;
  std::vector<std::vector<decltype(i)>> all;
  std::vector<decltype(i)> some;
  
  std::set<decltype(i)> s;
  
  while(first != last){
    if (Exists_In_Set(s,*first.*member_name)){
      all.push_back(some);
      some.clear();
      s.clear();
      
      //then add the one we just found
      some.push_back(*first.*member_name);
      Add_To_Set(s,*first.*member_name);
    }
    else{
      some.push_back(*first.*member_name);
      Add_To_Set(s,*first.*member_name);
    }
    ++first;
  }
  
  if (!some.empty()){
    all.push_back(some);
  }
  
  return all;
}
