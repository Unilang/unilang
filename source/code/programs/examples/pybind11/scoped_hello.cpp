#include <pybind11/embed.h> // everything needed for embedding

int main() {
    pybind11::scoped_interpreter guard{}; // start the interpreter and keep it alive

    pybind11::print("Hello, World!"); // use the Python API
}