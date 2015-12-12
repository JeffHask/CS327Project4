//
// Created by jeffrey on 11/7/15.
//

#include <stdexcept>
#include "headers/InfoService.h"
#include "iostream"
#include "headers/SoundFile.h"
#include "headers/Utils.h"
#include "headers/InfoService.h"
#include "headers/Utils.h"

using namespace std;



InfoService ::InfoService(int switches[], vector<string*> & soundFileNames, int numberOfSoundFiles) {
    this->help = switches[0];
    this->numberOfSoundFiles = numberOfSoundFiles;
    if(numberOfSoundFiles == -1) {
        SoundFile* soundFile = new SoundFile(string(" "));
        soundFile->setFileName("From Standard Input");
        soundFiles.push_back(soundFile);
        this->numberOfSoundFiles = 1;
    } else if(help != 1) {
        int i;
        for(i = 0; i < numberOfSoundFiles; i++) {
            try {
                soundFiles.push_back(new SoundFile((*soundFileNames[i])));
            } catch (invalid_argument &e) {
                __throw_invalid_argument(e.what());
            }
        }
    }
}

void InfoService::helperMessage() {
    cout << "sndinfo: A program to tell you all about .cs229 files passed in as arguments. Information includes:" << endl << endl <<
            "File Name" << endl << "File Type(Only cs229 is supported currently)" << endl << "Sample Rate" << endl <<
            "Bit Depth" << endl << "Number of Channels" << endl << "Number of Samples" << "Length of Sound (In seconds)"
            << endl << endl << "Legal Switches:" << endl << endl;
    h_helperMessage();
    cout << "If no files are passed as arguments, then the program will read from standard input";
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