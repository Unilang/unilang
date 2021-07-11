#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include "src/tree.hh"

using namespace std;

struct bigger_object {
  int a;
  int b;
  int c;
  std::string d;
  std::vector<std::string> e;
  tree<string> t;
};

tree<string> get_tree();

int main(int, char **)
{
  auto a = get_tree();
  a = get_tree();
  a = get_tree();
  
  auto b = get_tree();
  a = b;
  
  tree<string> c;
  bigger_object object;
  
  auto t2 = get_tree();
  object.t = t2;
  
  
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
  std::cout << t2.size() << std::endl;
}

tree<string> get_tree() {
  
  tree<string> tr;
  auto top=tr.begin();
  tr.insert(top, "one");
  return tr;
}





