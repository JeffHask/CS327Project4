//
// Created by jeffrey on 11/7/15.
//
#include <iostream>
#include "headers/ConcatService.h"
#include "headers/Utils.h"


using namespace std;

ConcatService::ConcatService(int switches[], string** soundFileNames, int numberOfFiles, string outputFileName) {
    this->help = switches[0];
    this->toWav = switches[1];
    this->outputFileName = outputFileName;
    this->numberOfSoundFiles = numberOfFiles;
    this->soundFiles = (SoundFile**)new SoundFile[numberOfFiles];
    if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
            soundFiles[i] = new SoundFile(*soundFileNames[i], toWav);
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

void ConcatService::concatFiles(SoundFile **soundFiles) {
    SoundFile soundFile = *soundFiles[0];
    FILE* fp;
    int i;
    for(i = 1; i < numberOfSoundFiles; i++) {
        soundFile += soundFiles[i];
    }
    if(!outputFileName.compare(" ")) {
       fp = stdout;
    } else {
        if((!toWav && outputFileName.find(".cs229") == string::npos) || toWav && outputFileName.find(".wav") == string::npos) {
            __throw_invalid_argument("Invalid output file, make sure you specify .wav file if you use the -w switch, otherwise use an output file that ends with .cs229");
        }
        fp = fopen(outputFileName.c_str(), "w");
    }
    if(!toWav) {
        soundFile.writeCS229File(fp);
    } else {
        soundFile.writeWAVFile(fp);
    }
}