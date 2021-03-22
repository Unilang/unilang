#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"

#include "absl/base/attributes.h"
#include "absl/debugging/stacktrace.h"
#include "absl/debugging/symbolize.h"
#include "fmt/format.h"

#include <cstdio>
#include <sstream>
#include <typeinfo>

#include <dlfcn.h>

extern "C" {
__attribute__((weak)) void __cxa_throw(void *thrown_exception, struct std::type_info *tinfo, void (*dest)(void *));
void __real___cxa_throw(void *thrown_exception, struct std::type_info *tinfo, void (*dest)(void *));
void __wrap___cxa_throw(void *thrown_exception, struct std::type_info *tinfo, void (*dest)(void *));
}

namespace
{

__attribute__((constructor)) void init_symbolizer(int argc, char **argv)
{
    absl::InitializeSymbolizer(argv[0]);
}

StackTrace &get_thread_local_throw_stacktrace()
{
    static thread_local StackTrace stacktrace;
    return stacktrace;
}

void real_cxa_throw(void *thrown_exception, struct std::type_info *tinfo, void (*dest)(void *))
{
    static auto real_cxa_throw_impl = [] {
        auto next_cxa_throw = reinterpret_cast<decltype(&__cxa_throw)>(dlsym(RTLD_NEXT, "__cxa_throw"));
        return next_cxa_throw ? next_cxa_throw : __real___cxa_throw;
    }();
    real_cxa_throw_impl(thrown_exception, tinfo, dest);
}

}

extern "C" {

namespace __cxxabiv1
{
    

__attribute__((weak)) void __cxa_throw(void *thrown_exception, struct std::type_info *tinfo, void (*dest)(void *))
{
    populate_stacktrace(get_thread_local_throw_stacktrace(), 1);
    real_cxa_throw(thrown_exception, tinfo, dest);
}
}


void __wrap___cxa_throw(void *thrown_exception, struct std::type_info *tinfo, void (*dest)(void *))
{
    populate_stacktrace(get_thread_local_throw_stacktrace(), 1);
    real_cxa_throw(thrown_exception, tinfo, dest);
}
}


bool operator==(const StackTrace &lhs, const StackTrace &rhs)
{
    return lhs.depth == rhs.depth && lhs.dropped_frames == rhs.dropped_frames &&
           lhs.frame_pointers == rhs.frame_pointers;
}

bool operator!=(const StackTrace &lhs, const StackTrace &rhs)
{
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &lhs, const StackTrace &rhs)
{
    lhs << "StackTrace(depth=" << rhs.depth << ", dropped_frames=" << rhs.dropped_frames << ", frame_pointers={"
        << fmt::format("{}", fmt::join(rhs.frame_pointers, ", ")) << "})";
    return lhs;
}

std::ostream &symbolize_stacktrace(std::ostream &stream, const StackTrace &trace)
{
    char buff[1024];
    stream << "Stack Trace, Depth=" << trace.depth << ", Dropped Frames=" << trace.dropped_frames << ":\n";
    for (size_t frame_idx = 0; static_cast<int>(frame_idx) < trace.depth; frame_idx++)
    {
        stream << frame_idx << ": ";
        auto frame = trace.frame_pointers[frame_idx];
        if (absl::Symbolize(frame, buff, sizeof(buff)))
        {
            stream << buff;
        }
        else
        {
            stream << "Could Not Symbolize frame at: " << frame;
        }
        stream << '\n';
    }
    return stream;
}

std::string get_stacktrace(){
    auto stracktrace = populate_stacktrace(0);
    return symbolize_stacktrace(stracktrace);
}

std::string symbolize_stacktrace(const StackTrace &trace)
{
    std::stringstream ss;
    symbolize_stacktrace(ss, trace);
    return ss.str();
}


// We need to prevent inlining of this
// because otherwise the number of frames to skip changes, and you'll lose the frame
// the throw actually happened in.
ABSL_ATTRIBUTE_NOINLINE ABSL_ATTRIBUTE_NO_TAIL_CALL void populate_stacktrace(StackTrace &trace, int skip_frames)
{
    // We skip an additional frame so populate_stacktrace doesn't show up in the trace
    skip_frames += 1;
    trace.depth = absl::GetStackTraceWithContext(reinterpret_cast<void **>(&trace.frame_pointers[0]),
                                                 static_cast<int>(trace.frame_pointers.size()),
                                                 skip_frames,
                                                 nullptr,
                                                 &trace.dropped_frames);
}

ABSL_ATTRIBUTE_NOINLINE ABSL_ATTRIBUTE_NO_TAIL_CALL StackTrace populate_stacktrace(int skip_frames)
{
    // We skip an additional frame so populate_stacktrace doesn't show up in the trace
    skip_frames += 1;
    StackTrace trace;
    populate_stacktrace(trace, skip_frames);
    return trace;
}

const StackTrace &get_throw_stacktrace()
{
    return get_thread_local_throw_stacktrace();
}

