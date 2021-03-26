#include <algorithm>
#include <string>
#include <iostream>
#include "src/tree.hh"

using namespace std;

int main(int, char **)
   {
   tree<string> tr;
   tree<string>::iterator top, one, two, loc, banana;

   top=tr.begin();
   one=tr.insert(top, "one");
   two=tr.append_child(one, "two");
   tr.append_child(two, "apple");
   banana=tr.append_child(two, "banana");
   tr.append_child(banana,"cherry");
   tr.append_child(two, "peach");
   tr.append_child(one,"three");

   loc=find(tr.begin(), tr.end(), "two");
   if(loc!=tr.end()) {
   tree<string>::sibling_iterator sib=tr.begin(loc);
   while(sib!=tr.end(loc)) {
     cout << (*sib) << endl;
     ++sib;
     }
   cout << endl;
   tree<string>::iterator sib2=tr.begin(loc);
   tree<string>::iterator end2=tr.end(loc);
   while(sib2!=end2) {
     for(int i=0; i<tr.depth(sib2)-2; ++i)
        cout << " ";
     cout << (*sib2) << endl;
     ++sib2;
     }
   }
}