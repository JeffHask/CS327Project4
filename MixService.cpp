//
// Created by jeffrey on 11/7/15.
//

#include "headers/MixService.h"
#include "headers/Utils.h"

MixService::MixService(int switches[], vector<string*> & soundFileNames, int numberOfFiles, string outputFileName,
                       vector<float> & multiplyers) {
    this->help = switches[0];
    this->outputFileName = outputFileName;
    this->numberOfSoundFiles = numberOfFiles;
    if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
            soundFiles.push_back(new SoundFile(*soundFileNames[i]));
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
    cout << "sndmix is a program that 'mixes' samples together. It multiples the samples of one file by a number provided"
            << " by the user, muiliplies the other sound files passed in also by values passed in by the user, then it "
                                   "adds the values together"<<endl
    << "Example use: sndmix [switches] mult1 file1 mult2 file2.... multn filen"
    << endl << "Valid switches:" << endl << endl;
    h_helperMessage();
    o_helperMessage();
}

void MixService::mixSound() {
    int i;
    if(!numberOfSoundFiles) {
        __throw_invalid_argument("Please specify at least one .cs229 file");
    }
    SoundFile *soundFile = soundFiles[0];
    for (i = 1; i < numberOfSoundFiles; ++i) {
        soundFile = *soundFile + soundFiles[i];
    }

    soundFile->writeCS229File(outputFileName);
}
