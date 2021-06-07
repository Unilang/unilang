#include "utilities.hpp"

//System Headers
#include <sys/stat.h>

bool File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}