#pragma once
#include "code/utilities/math/gmp/lib.hpp"

namespace global{
    static gmp_randclass gen(gmp_randinit_default);
}
