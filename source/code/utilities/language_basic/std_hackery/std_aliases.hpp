#pragma once
#include <vector>
#include <string>
#include <map>

//1d lists
using strings = std::vector<std::string>; using words = std::vector<std::string>;
using ints = std::vector<int>;
using longs = std::vector<long>;
using ulongs = std::vector<unsigned long>;

//2d lists
using string_grid = std::vector<std::vector<std::string>>;

//3d lists
using string_grids = std::vector<std::vector<std::vector<std::string>>>;

//maps
using string_map = std::map<std::string,std::string>;
using long_map = std::map<long,long>;
using ulong_map = std::map<unsigned long,unsigned long>;
