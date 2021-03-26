#include <string>
#include "nlohmann/json.hpp"
#include <sstream>
#include <variant>
#include "gtest/gtest.h"
#include "code/utilities/formats/json/converters/lib.hpp"
#include "code/utilities/formats/json/overloads/variant_json_converters.hpp"


//TEST OBJECT
struct foo{
    std::variant<int,std::string> v;
};

//SERIALIZATION
void to_json(nlohmann::json& j, const foo& f) {
    j = nlohmann::json{{"v", f.v}};
}

void from_json(const nlohmann::json& j, foo& f) {
    j.at("v").get_to(f.v);
}

foo Build_Foo() {
    foo f;
    f.v = "hello";
    return f;
}

TEST(Serialization, VariantNonIntrusive) {
    auto f = Build_Foo();
    auto results = json_serialize_deserialize_serialize(f);
    EXPECT_EQ(results.first,results.second);
}