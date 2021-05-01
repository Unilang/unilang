//This allows serializing std::chrono related types to/from json
#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include "nlohmann/json.hpp"
#include <sstream>


//https://github.com/nlohmann/json/issues/2159
//You'll noticed I wrote specific overloads for each duration type.
//Maybe there is a more generic way to do them all in 1 function.
//I did it this way for no particular reason.
namespace nlohmann {
    template<>
    struct adl_serializer<std::chrono::seconds>
    {
        static void to_json(json& j, std::chrono::nanoseconds const& time)
        {
            long count{ time.count() };
            j = count;
        }
        static void from_json(json const& j, std::chrono::nanoseconds & time)
        {
            auto const count = j.get<long>();
            time = std::chrono::nanoseconds(count);
        }
        
        static void to_json(json& j, std::chrono::microseconds const& time)
        {
            long count{ time.count() };
            j = count;
        }
        static void from_json(json const& j, std::chrono::microseconds & time)
        {
            auto const count = j.get<long>();
            time = std::chrono::microseconds(count);
        }
        
        static void to_json(json& j, std::chrono::milliseconds const& time)
        {
            long count{ time.count() };
            j = count;
        }
        static void from_json(json const& j, std::chrono::milliseconds & time)
        {
            auto const count = j.get<long>();
            time = std::chrono::milliseconds(count);
        }
        
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
        
        static void to_json(json& j, std::chrono::minutes const& time)
        {
            long count{ time.count() };
            j = count;
        }
        static void from_json(json const& j, std::chrono::minutes & time)
        {
            auto const count = j.get<long>();
            time = std::chrono::minutes(count);
        }
        
        static void to_json(json& j, std::chrono::hours const& time)
        {
            long count{ time.count() };
            j = count;
        }
        static void from_json(json const& j, std::chrono::hours & time)
        {
            auto const count = j.get<long>();
            time = std::chrono::hours(count);
        }
        
        
    };
}