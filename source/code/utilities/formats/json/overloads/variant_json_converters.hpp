//This allows serializing variants to/from json
//https://github.com/nlohmann/json/issues/1261#issuecomment-426209912
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <variant>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace detail
{
template <std::size_t N>
struct variant_switch
{
  template <typename Variant>
  void operator()(int index, json const &value, Variant &v) const
  {
    if (index == N)
      v = value.get<std::variant_alternative_t<N, Variant>>();
    else
      variant_switch<N - 1>{}(index, value, v);
  }
};

template <>
struct variant_switch<0>
{
  template <typename Variant>
  void operator()(int index, json const &value, Variant &v) const
  {
    if (index == 0)
      v = value.get<std::variant_alternative_t<0, Variant>>();
    else
    {
      throw std::runtime_error(
          "while converting json to variant: invalid index");
    }
  }
};
}

namespace nlohmann
{
template <typename ...Args>
struct adl_serializer<std::variant<Args...>>
{
  static void to_json(json& j, std::variant<Args...> const& v)
  {
    std::visit([&](auto&& value) {
      j["index"] = v.index();
      j["value"] = std::forward<decltype(value)>(value);
    }, v);
  }

  static void from_json(json const& j, std::variant<Args...>& v)
  {
    auto const index = j.at("index").get<int>();
    ::detail::variant_switch<sizeof...(Args) - 1>{}(index, j.at("value"), v);
  }
};
}
