#include <string>
#include <sstream>
#include "gtest/gtest.h"
#define _LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR
#define BOOST_NO_AUTO_PTR
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

struct foo{
    int i;
    
  template <class Archive>
  void serialize( Archive & ar, const unsigned int version)
  {
    ar & i;
  }
};

TEST(Serialization, BoostClassIntIntrusive) {
    
    std::stringstream ss;
    {
        boost::archive::text_oarchive oarchive(ss);
        foo f;
        f.i = 5;
        oarchive << f;
    }
    {
        boost::archive::text_iarchive iarchive(ss);
        foo f;
        f.i = 0;
        iarchive >> f;
        EXPECT_EQ(f.i,5);
    }
}

