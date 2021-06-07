#pragma once

Recurse_Each_Regular_File

for(auto iterEntry = fs::recursive_directory_iterator(pathToShow); iterEntry != fs::recursive_directory_iterator(); ++iterEntry ) {
    const auto filenameStr = iterEntry->path().filename().string();
    std::cout << std::setw(iterEntry.depth()*3) << "";
    if (iterEntry->is_directory()) {
        std::cout << "dir:  " << filenameStr << '\n';
    }
    else if (iterEntry->is_regular_file()) {
        std::cout << "file: " << filenameStr << '\n';
    }
    else
        std::cout << "??    " << filenameStr << '\n';
}
