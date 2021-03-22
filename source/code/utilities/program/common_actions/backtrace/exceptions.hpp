#pragma once

#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"

#include <boost/exception/all.hpp>

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

namespace detail
{
/// Tag type for compatibility with boost::enable_error_info
using traced = boost::error_info<struct tag_stacktrace, StackTrace>;


template <typename Exception, typename... Args>
auto make_exception_with_stacktrace(int skip_depth, Args &&...args)
{
    return boost::enable_error_info(Exception{std::forward<Args>(args)...})
           << detail::traced(populate_stacktrace(skip_depth + 1));
}


const StackTrace *try_get_stacktrace(const std::exception &e);


const StackTrace &get_stacktrace(const std::exception &e);

} // namespace detail


template <typename Exception>
[[noreturn]] void throw_nested_if_nested(Exception &&exception)
{
    if (!std::current_exception())
    {
        throw Exception(std::forward<Exception>(exception));
    }
    std::throw_with_nested(std::forward<Exception>(exception));
}


template <bool with_trace, typename Exception, typename... Args>
[[noreturn]] void throw_exception(Args &&...args)
{
    if constexpr (with_trace)
    {
        throw_nested_if_nested(detail::make_exception_with_stacktrace<Exception>(1, std::forward<Args>(args)...));
    }
    else
    {
        throw_nested_if_nested(Exception{std::forward<Args>(args)...});
    }
}


template <typename Exception, typename... Args>
[[noreturn]] void throw_exception(Args &&...args)
{
#ifdef NDEBUG
    // If we're in release mode, we just throw the exception as normal
    throw_exception<false, Exception>(std::forward<Args>(args)...);
#else
    // If we're in debug mode, append the stack trace to the exception message
    throw_exception<true, Exception>(std::forward<Args>(args)...);
#endif
}


std::ostream &what(std::ostream &stream, const std::exception &e);
std::string what(const std::exception &e);
std::ostream &get_stacktrace(std::ostream &stream, const std::exception &e);
std::string get_stacktrace(const std::exception &e);
std::ostream &get_symbolized_stacktrace(std::ostream &stream, const std::exception &e);


std::string get_symbolized_stacktrace(const std::exception &e);


template <typename Func>
void apply_to_nested_exception(const std::exception &e, Func func, size_t level = 0)
{
    func(e, level);
    try
    {
        std::rethrow_if_nested(e);
    }
    catch (const std::exception &nested)
    {
        apply_to_nested_exception(nested, std::move(func), level + 1);
    }
    catch (...)
    {
    }
}
