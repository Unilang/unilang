#include <string>
#include "nlohmann/json.hpp"
#include <sstream>
#include "gtest/gtest.h"
#include "src/tree.hh"
#include "code/utilities/formats/json/overloads/tree_json_converters.hpp"
#include "code/utilities/formats/json/converters/lib.hpp"


//TEST OBJECT
struct foo{
    int i;
};

//SERIALIZATION
void to_json(nlohmann::json& j, const foo& f) {
    j = nlohmann::json{{"i", f.i}};
}

void from_json(const nlohmann::json& j, foo& f) {
    j.at("i").get_to(f.i);
}

tree<foo> Build_Tree() {
    tree<foo> tr;
    auto top = tr.begin();
    
    foo f;
    f.i = 1;
    auto f1=tr.insert(top,f);
    f.i = 2;
    auto f2=tr.insert(top,f);
    f.i = 3;
    auto f3=tr.insert(top,f);
    f.i = 4;
    auto f4=tr.append_child(f2,f);
    f.i = 5;
    auto f5=tr.append_child(f4,f);
    f.i = 6;
    auto f6=tr.append_child(f5,f);
    f.i = 7;
    auto f7=tr.insert(top,f);
    f.i = 8;
    auto f8=tr.insert(f7,f);
    
    return tr;
}

TEST(Serialization, TreeNonIntrusive) {
    
    auto tr = Build_Tree();
    auto results = json_serialize_deserialize_serialize(tr);
    EXPECT_EQ(results.first,results.second);
}