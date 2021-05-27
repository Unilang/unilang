#include "gtest/gtest.h"
#include "code/utilities/crypto/bitcoin_wallet_generator.hpp"

TEST(TestGeneration, WordToWallet) {
  //EXPECT_EQ(Bitcoin_Wallet_Generator::Create("bitcoin").wallet_address,"18VkRiDhFu2Z17AvtpU3vL2LbTXDzCvDVo");
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("bitcoin!").wallet_address,"19fQQ5FruqpmvbRzeEn6CHJHLvHxD59ph9");
}
