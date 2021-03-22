#include "code/utilities/program/common_actions/backtrace/exceptions.hpp"
#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"
#include "absl/debugging/symbolize.h"

#include <boost/exception/all.hpp>

#include <sstream>
#include <string>
#include <utility>

namespace detail
{

const StackTrace *try_get_stacktrace(const std::exception &e)
{
    return boost::get_error_info<detail::traced>(e);
}

const StackTrace &get_stacktrace(const std::exception &e)
{
    auto maybe_exception_trace = try_get_stacktrace(e);
    if (maybe_exception_trace)
    {
        return *maybe_exception_trace;
    }
    return get_throw_stacktrace();
}
} // namespace detail

std::ostream &what(std::ostream &stream, const std::exception &exception)
{
    apply_to_nested_exception(exception, [&stream](const std::exception &e, size_t level) {
        if (level == 0)
        {
            stream << "Exception: ";
        }
        else
        {
            stream << std::string(level, ' ') << "Caused By: ";
        }
        stream << e.what() << '\n';
    });
    return stream;
};
std::string what(const std::exception &e)
{
    std::stringstream ss;
    what(ss, e);
    return ss.str();
}

std::ostream &get_stacktrace(std::ostream &stream, const std::exception &exception)
{
    apply_to_nested_exception(exception, [&stream](const std::exception &e, size_t level) {
        if (level > 0)
        {
            stream << "-----Caused By------\n";
        }
        stream << detail::get_stacktrace(e);
    });
    return stream;
}

std::string get_stacktrace(const std::exception &e)
{
    std::stringstream ss;
    get_stacktrace(ss, e);
    return ss.str();
}

std::ostream &get_symbolized_stacktrace(std::ostream &stream, const std::exception &exception)
{
    apply_to_nested_exception(exception, [&stream](const std::exception &e, size_t level) {
        if (level > 0)
        {
            stream << "-----Caused By------\n";
        }
        symbolize_stacktrace(stream, detail::get_stacktrace(e));
    });
    return stream;
};

std::string get_symbolized_stacktrace(const std::exception &e)
{
    std::stringstream ss;
    get_symbolized_stacktrace(ss, e);
    return ss.str();
}
