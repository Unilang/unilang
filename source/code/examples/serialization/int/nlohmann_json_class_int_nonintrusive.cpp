#include <string>
#include "nlohmann/json.hpp"
#include <sstream>
#include "gtest/gtest.h"

struct foo{
    int i;
};

void to_json(nlohmann::json& j, const foo& f) {
	j = nlohmann::json{{"i", f.i}};
}

void from_json(const nlohmann::json& j, foo& f) {
	j.at("i").get_to(f.i);
}

TEST(Serialization, NlohmannClassIntNonIntrusive) {
    
    foo f;
    f.i = 5;
    nlohmann::json j = f;
    auto f2 = j.get<foo>();
    EXPECT_EQ(f.i,f2.i);
}