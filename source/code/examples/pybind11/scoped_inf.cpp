#include <pybind11/embed.h>
#include <iostream>

//https://github.com/pybind/pybind11/issues/1813


void signalHandler( int signum ) {
    exit(signum);
}

int main() {
    signal(SIGINT, signalHandler);
    pybind11::scoped_interpreter guard{};
    while (true){
        //can't ctrl+C
    }
}