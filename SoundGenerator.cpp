//
// Created by jeffrey on 11/30/15.
//

#include "headers/SoundGenerator.h"

//SoundFile SoundGenerator::setupFile() {
//}

void SoundGenerator::print() {

    cout << "Bit Rate: " << bitDepth << endl;
    cout << "Sample Rate: " << sampleRate << endl;
    cout <<"Frequency: " << frequency << endl;
    cout << "Duration: " << duration << endl;
    cout << "Peak Volume: " << volume * 100 << endl;
    cout << "Attack Time: " << attack << endl;
    cout << "Decay Time: " << decay << endl;
    cout << "Sustain Time :" << sustain << endl;
    cout << "Release Time :" << release << endl;
    cout << "Type: " << type << endl;
    cout << "Pulse Time: " << pulseTime << endl;

}