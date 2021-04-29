//This allows serializing std::chrono related types to/from json
#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include "nlohmann/json.hpp"
#include <sstream>


//https://github.com/nlohmann/json/issues/2159
namespace nlohmann {
    template<>
    struct adl_serializer<std::chrono::seconds>
    {
        static void to_json(json& j, std::chrono::seconds const& time)
        {
            long count{ time.count() };
            j = count;
        }
        static void from_json(json const& j, std::chrono::seconds & time)
        {
            auto const count = j.get<long>();
            time = std::chrono::seconds(count);
        }
    };
}