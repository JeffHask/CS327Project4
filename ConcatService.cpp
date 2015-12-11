//
// Created by jeffrey on 11/7/15.
//
#include <iostream>
#include "headers/ConcatService.h"
#include "headers/Utils.h"


using namespace std;

ConcatService::ConcatService(int switches[], vector<string*> soundFileNames, int numberOfFiles, string outputFileName) {
    this->help = switches[0];
    this->outputFileName = outputFileName;
    this->numberOfSoundFiles = numberOfFiles;
    if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
            soundFiles.push_back(new SoundFile(*soundFileNames[i]));
        }
    }
}

ConcatService::ConcatService() {

}

void ConcatService ::helperMessage() {
    cout << "sndcat: A program that allows you to concatenate .cs227 files together" << endl
    << endl << "Valid switches:" << endl << endl;
    h_helperMessage();
    o_helperMessage();
    w_helperMessage();
}

void ConcatService::run() {
    if(help == 1) {
        helperMessage();
    } else {
        concatFiles(soundFiles);
    }
}

void ConcatService::concatFiles(vector<SoundFile*> soundFiles) {
    SoundFile soundFile = *soundFiles[0];
    int i;
    for(i = 1; i < numberOfSoundFiles; i++) {
        soundFile += soundFiles[i];
    }
    if(outputFileName.compare(" ")) {
        if((outputFileName.find(".cs229") == string::npos) ) {
            __throw_invalid_argument("Invalid output file, must use an output file that ends with .cs229");
        }
    }
    soundFile.writeCS229File(outputFileName);
}