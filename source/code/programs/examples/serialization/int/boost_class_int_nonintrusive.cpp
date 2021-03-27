#include <string>
#include <sstream>
#include "gtest/gtest.h"
#define _LIBCPP_ENABLE_CXX17_REMOVED_AUTO_PTR
#define BOOST_NO_AUTO_PTR
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

struct foo{
    int i;
};

namespace boost {
namespace serialization {
    template <class Archive>
    void serialize( Archive & ar, foo & f, const unsigned int version)
    {
    ar & f.i;
    }
}
}

TEST(Serialization, BoostClassIntNonIntrusive) {
    
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

