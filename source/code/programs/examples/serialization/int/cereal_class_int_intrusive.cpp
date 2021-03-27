#include <string>
#include <sstream>
#include "gtest/gtest.h"
#include "cereal/archives/binary.hpp"

struct foo{
    int i;
    
  template <class Archive>
  void serialize( Archive & ar)
  {
    ar & i;
  }
};

TEST(Serialization, CerealClassIntIntrusive) {
    
    std::stringstream ss;
    {
        cereal::BinaryOutputArchive oarchive(ss);
        foo f;
        f.i = 5;
        oarchive(f);
    }
    {
        cereal::BinaryInputArchive iarchive(ss);
        foo f;
        f.i = 0;
        iarchive(f);
        EXPECT_EQ(f.i,5);
    }
}

