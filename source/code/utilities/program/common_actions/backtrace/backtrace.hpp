#pragma once

#include <array>
#include <ostream>
#include <string>


struct StackTrace
{
    // The maximum depth of stack we can trace
    static constexpr size_t max_stack_depth = 32;
    
    // An array of PC locations corresponding to stack frames
    std::array<void *, max_stack_depth> frame_pointers{};
    
    // The depth of the recorded trace
    int depth = 0;
    
    // The count of frames dropped due to either insufficient stack depth buffer or other reasons
    int dropped_frames = 0;
};

//operators
bool operator==(const StackTrace &lhs, const StackTrace &rhs);
bool operator!=(const StackTrace &lhs, const StackTrace &rhs);
std::ostream &operator<<(std::ostream &lhs, const StackTrace &rhs);

//functions
std::string get_stacktrace();
std::ostream &symbolize_stacktrace(std::ostream &stream, const StackTrace &trace);
std::string symbolize_stacktrace(const StackTrace &trace);
void populate_stacktrace(StackTrace &trace, int skip_frames);
StackTrace populate_stacktrace(int skip_frames);
const StackTrace &get_throw_stacktrace();

