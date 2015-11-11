//
// Created by jeffrey on 11/7/15.
//

#include "headers/InfoService.h"
#include "iostream"
#include "headers/SoundFile.h"

using namespace std;

InfoService ::InfoService() {

}

InfoService ::InfoService(int help, char** soundFileNames, int numberOfSoundFiles) {
    this->help = help;
    this->numberOfSoundFiles = numberOfSoundFiles;
    soundFiles = (SoundFile **) new SoundFile[numberOfSoundFiles];
    if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
//            cout << soundFileNames[i] << endl;
            soundFiles[i] = new SoundFile(soundFileNames[i], 0);
        }
    }
}

void InfoService::helperMessage() {
    cout << "sndinfo: A program to tell you all about .cs229 files passed in as arguments" << endl << endl <<
            "Legal Switches:" << endl << endl;
    Service::h_helperMessage();
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
        cout << "Sample Test: " << soundFiles[i]->getSamples()[5]->getChannels()[1] << endl;
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