//
// Created by jeffrey on 11/7/15.
//

#include "headers/MixService.h"
#include "headers/Utils.h"


MixService::MixService() {

}

MixService::MixService(int switches[], string **soundFileNames, int numberOfFiles, string outputFileName,
                       int *multiplyers) {
    this->help = switches[0];
    this->outputFileName = outputFileName;
    this->numberOfSoundFiles = numberOfFiles;
    this->soundFiles = (SoundFile**)new SoundFile[numberOfFiles];
    if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
            soundFiles[i] = new SoundFile(*soundFileNames[i], 0);
            soundFiles[i] = *soundFiles[i] * multiplyers[i];
        }
    }
}

void MixService::run() {
    if(help == 1) {
        helperMessage();
    } else {
        mixSound();
    }
}

void MixService::helperMessage() {
//    TODO make better message
    cout << "sndcat: A program that allows you to mix .cs227 files together" << endl
    << endl << "Valid switches:" << endl << endl;
    h_helperMessage();
    o_helperMessage();
}

void MixService::mixSound() {
    int i;
    FILE * file;
    if(!outputFileName.compare(" ")) {
        file = stdout;
    } else {
        file = fopen(outputFileName.c_str(), "w");
    }
    if(!numberOfSoundFiles) {
        __throw_invalid_argument("Please specify atleast one .cs229 file");
    }
    SoundFile *soundFile = soundFiles[0];
    for (i = 1; i < numberOfSoundFiles; ++i) {
        soundFile = *soundFile + soundFiles[i];
    }

    soundFile->writeCS229File(outputFileName);
}
