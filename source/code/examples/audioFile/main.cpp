#include "AudioFile.h"
#include "code/utilities/types/vectors/operators/lib.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_join_settings.hpp"
#include "code/utilities/peripheral/sound/wav/wav_file_joiner.hpp"
#include "code/utilities/assets/english_sounds.hpp"
#include "code/utilities/peripheral/sound/wav/pitch_adjuster.hpp"
#include "code/utilities/peripheral/sound/wav/tempo_adjuster.hpp"
#include "code/utilities/filesystem/files/temp/existing_temp_file.hpp"
#include "code/utilities/linguistics/speak/animal_crossing_speaker.hpp"

int main(int argc, char** argv){
    
    
    
    std::string message = argv[1];
    
    Animal_Crossing_Speaker::Speak(message,"/home/laptop/Desktop/","out");
}