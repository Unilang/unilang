#pragma once
#include <string>
#include <vector>

template <typename... T>
auto make_vector(T&&... args)
{
    using first_type = typename std::tuple_element<0, std::tuple<T...>>::type;
    return std::vector<first_type>{std::forward<T>(args)...};
}



template<typename T>
std::vector<std::vector<T>> Create_N_By_N_Vector(int x, int y, T value){
  std::vector<std::vector<T>> result;
  std::vector<T> row;
  for (int i = 0; i < y; ++i){
      for (int j = 0; j < x; ++j){
        row.push_back(value);
      }
    result.push_back(row);
    row.clear();
  }
  return result;
}

template<typename T>
std::vector<std::vector<T>> Create_A_Square_Vector(int size, T value){
  return Create_N_By_N_Vector(size,size,value);
}


std::vector<std::string> Get_Comma_Seperated_Values_From_File(std::string const& path_to_file);
std::vector<std::vector<std::string>> Create_N_By_N_Vector_Of_Question_Marks(int x, int y);
std::vector<std::vector<std::string>> Create_N_By_N_Vector_Of_Strs(int x, int y, std::string const& str);
                                                                   
std::vector<std::string> StringToVector(std::string const& str, char const delimiter);
