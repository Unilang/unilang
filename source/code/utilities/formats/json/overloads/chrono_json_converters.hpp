//This allows serializing std::chrono related types to/from json
#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include "nlohmann/json.hpp"
#include <sstream>

// template <typename T>
// void to_json(nlohmann::json& j, std::chrono::nanoseconds const& time) {
//     long long count{ time.count() };
//     j["time_ns"] = count;
// }

// template <typename T>
// void from_json(const nlohmann::json& j, std::chrono::nanoseconds & time) {
//     auto const count = j.at("time_ns").get<long long>();
//     time = std::chrono::nanoseconds(count);
// }

// template <typename T>
// void to_json(nlohmann::json& j, std::chrono::seconds const& time) {
//     long count{ time.count() };
//     j["time_s"] = count;
// }

// template <typename T>
// void from_json(const nlohmann::json& j, std::chrono::seconds & time) {
//     auto const count = j.at("time_s").get<long>();
//     time = std::chrono::seconds(count);
// }

// external/nlohmann_json/include/nlohmann/json.hpp:2676:17: note:
// candidate template ignored:
// requirement 'detail::has_from_json<nlohmann::basic_json<std::map, std::vector, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>, bool, long, unsigned long, double, std::allocator, adl_serializer>, std::__1::chrono::duration<long long, std::__1::ratio<1, 1>>, void>::value'
// was not satisfied [with ValueType = std::__1::chrono::duration<long long, std::__1::ratio<1, 1>>]
//     ValueType & get_to(ValueType& v) const noexcept(noexcept(



// namespace nlohmann {
//     template<typename Clock, typename Duration>
//     struct adl_serializer<std::chrono::time_point<Clock, Duration>>
//     {
//         static void to_json(json& j, const std::chrono::seconds& time)
//         {
//             long count{ time.count() };
//             j["time_s"] = count;
//         }
        
//         static void from_json(json const& j, std::chrono::seconds& time)
//         {
//             auto const count = j.at("time_s").get<long>();
//             time = std::chrono::seconds(count);
//         }
//     };
// }


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