#include <algorithm>
#include <string>
#include <iostream>
#include "src/tree.hh"

using namespace std;

tree<string> get_tree();

int main(int, char **)
{
  auto a = get_tree();
  a = get_tree();
  a = get_tree();
  
  auto b = get_tree();
  a = b;
  
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
}

tree<string> get_tree() {
  
  tree<string> tr;
  auto top=tr.begin();
  tr.insert(top, "one");
  return tr;
}
