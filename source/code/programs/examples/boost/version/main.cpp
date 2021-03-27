#include <boost/version.hpp>
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Boost version: " 
          << BOOST_VERSION / 100000
          << "."
          << BOOST_VERSION / 100 % 1000
          << "."
          << BOOST_VERSION % 100 
          << std::endl;
    return 0;
}