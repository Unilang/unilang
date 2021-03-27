#include <iostream>
#include <utility>
#include <type_traits>
#include "CppConsoleTable.hpp"

using namespace std;
using ConsoleTable = samilton::ConsoleTable;

int main()
{
    ConsoleTable table(1, 1, samilton::Alignment::centre);

    table[0][0] = "Some String";
    table[1][3] = true;
    table[2][1] = 10;
    table[3][3] = "Some\nMulti String";
    table[2][2] = 2.354;
    table[0][1] = false;

    cout << table;
}