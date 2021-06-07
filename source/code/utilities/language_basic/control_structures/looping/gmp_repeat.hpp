#pragma once
#include <string>
#include "code/utilities/math/gmp/lib.hpp"


//uses string and in term gmp library
template <typename Function>
void repeat(Function f, std::string amount) {
    mpz_class i (amount);
    while (i > 0) {f(); i -= 1;}
    return;
}

//uses char
template <typename Function>
void repeat(Function f, const char* amount) {
    mpz_class i (amount);
    while (i > 0) {f(); i -= 1;}
    return;
}

//uses gmp library
template <typename Function>
void repeat(Function f, mpz_class amount) {
    while (amount > 0) {f(); amount -= 1;}
    return;
}
template <typename Function>
void repeat(mpz_class amount, Function f) {
    while (amount > 0) {f(); amount -= 1;}
    return;
}
