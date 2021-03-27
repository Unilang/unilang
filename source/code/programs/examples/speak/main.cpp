#include <iostream>
#include <thread>
#include "code/utilities/linguistics/speak/word_speaker.hpp"

int main(int argc, char** argv){
    Word_Speaker::Speak(argv[1]);
}