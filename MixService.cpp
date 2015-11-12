//
// Created by jeffrey on 11/7/15.
//

#include "headers/MixService.h"


MixService::MixService() {

}

MixService::MixService(int helpSwitch, char **soundFileNames, int numberOfFiles, string outputFileName,
                       int *multiplyers) {
    this->help = helpSwitch;
    this->outputFileName = outputFileName;
    this->numberOfSoundFiles = numberOfFiles;
    this->soundFiles = (SoundFile**)new SoundFile[numberOfFiles];
    if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
//            cout << soundFileNames[i] << endl;
            *soundFiles[i] = *(new SoundFile(soundFileNames[i], 0)) * multiplyers[i];
        }
    }
}

void MixService::run() {
    if(help) {
        helperMessage();
    } else {

    }
}

void MixService::helperMessage() {
//    TODO make better message
    cout << "sndcat: A program that allows you to mix .cs227 files together" << endl
    << endl << "Valid switches:" << endl << endl;
    h_helperMessage();
    o_helperMessage();
}

void MixService::mixSound(SoundFile **soundfiles, int numberOfFiles, int *multiplyers, string outputFileName) {

}
