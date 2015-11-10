#include <iostream>
#include "headers/Service.h"
using namespace std;

void Service ::h_helperMessage() {
    cout << "-h\t: show the help screen" << endl;
}

void Service ::o_helperMessage() {
    cout << "-o file\t: specify the output file name; if omitted, write to standard output" << endl;
}

void Service ::w_helperMessage() {
    cout << "-w\t: output in .wav format instead of .cs229";
}

void Service::allocate_SoundFiles(int numberSoundFiles) {
    int i;
    for(i = 0; i < numberSoundFiles; i++) {
        soundFiles[i] = new SoundFile();
    }
}