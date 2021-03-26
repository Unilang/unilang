#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "code/utilities/random/dice/n_sided_dice.hpp"

TEST(Serialization, BoostInt) {
    
    
    //fail 1/3 of the time
    int roll = N_Sided_Dice::Roll(3);
    EXPECT_FALSE(roll == 0);
}

