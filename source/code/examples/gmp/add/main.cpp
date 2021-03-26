#include <gmpxx.h>
#include <iostream>
#include <sstream>

int main (void)
{
  mpz_class a, b, c;

  a = 1234;
  b = "-5678";
  c = a+b;
  std::cout << "sum is " << c.get_str() << "\n";

  return 0;
}