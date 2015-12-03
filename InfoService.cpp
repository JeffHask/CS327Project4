//
// Created by jeffrey on 11/7/15.
//

#include <stdexcept>
#include "headers/InfoService.h"
#include "iostream"
#include "headers/SoundFile.h"
#include "headers/Utils.h"

using namespace std;

InfoService ::InfoService() {

}

InfoService ::InfoService(int switches[], string** soundFileNames, int numberOfSoundFiles) {
    this->help = switches[0];
    this->numberOfSoundFiles = numberOfSoundFiles;
    if(help != 1) {
        soundFiles = (SoundFile**)new SoundFile[numberOfSoundFiles];
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {

            try {
                soundFiles[i] = new SoundFile((soundFileNames[i][0]), 0);
            } catch (invalid_argument &e) {
                __throw_invalid_argument(e.what());
            }
            }
    }
}

void InfoService::helperMessage() {
    cout << "sndinfo: A program to tell you all about .cs229 files passed in as arguments" << endl << endl <<
            "Legal Switches:" << endl << endl;
    h_helperMessage();
}

void InfoService::printInfo() {
    int i;
    for(i = 0; i < numberOfSoundFiles; i++) {
        cout << "File Name: " << soundFiles[i]->getFileName() << endl;
        cout << "File Type: " << soundFiles[i]->getFileType() << endl;
        cout << "Sample Rate: " << soundFiles[i]->getSampleRate() << endl;
        cout << "Bit Depth: " << soundFiles[i]->getBitDepth() << endl;
        cout << "Number of Channels: " << soundFiles[i]->getNumberOfChannels() << endl;
        cout << "Number of Samples: " << soundFiles[i]->getNumberOfSamples() << endl;
        cout << "Length of Sound: " << soundFiles[i]->lengthOfSound() << " Seconds" << endl << endl;
    }
}

void InfoService::run() {
    if(help == 1) {
        helperMessage();
    } else {
        printInfo();
    }
}