#include "gtest/gtest.h"

TEST(Unilang_Tokens, Are_Unique) {
    
    auto tokens = Get_Tokens::Get();
    EXPECT_TRUE(Unique_Tokens_Checker::All_Token_Characters_Are_Unique(tokens));
}

