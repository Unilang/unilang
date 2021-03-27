#include "include/rang.hpp"

using namespace std;
using namespace rang;

int main()
{
    cout << "Plain old text" << std::endl
         << style::bold << rang::fg::green << "Rang styled text!!"
         << style::reset << endl;
}