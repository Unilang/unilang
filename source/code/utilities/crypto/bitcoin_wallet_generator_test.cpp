#include "gtest/gtest.h"
#include "code/utilities/crypto/bitcoin_wallet_generator.hpp"

TEST(TestGeneration, WordToWallet) {
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("hello world").wallet_address,"12q7HJP6LFwMHFWCogVzjq7BsHt8tqWfur");
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("bitcoin").wallet_address,"18VkRiDhFu2Z17AvtpU3vL2LbTXDzCvDVo");
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("bitcoin!").wallet_address,"19fQQ5FruqpmvbRzeEn6CHJHLvHxD59ph9");
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("a").wallet_address,"14dD6ygPi5WXdwwBTt1FBZK3aD8uDem1FY");
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("0").wallet_address,"13AJqFKTAMQwqLEaQTphEi9Evpyi4UxWen");
  EXPECT_EQ(Bitcoin_Wallet_Generator::Create("foo").wallet_address,"1LEH8BEZgC4onZ4GLm8UpZ3vXGAr6LYKST");
}
