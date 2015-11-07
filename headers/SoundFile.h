//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SOUNDFILE_H
#define CS327PROJECT4_SOUNDFILE_H


#include "ISound.h"

class soundFile : iSound {
protected:
    char *fileName;
    char *fileType;
    int sampleRate;
    int bitDepth;
    int numberOfChannels;
    int* numberOfSamples;
    int lengthOfSound;
    soundFile();
    soundFile(char* fileName);
    void readCS299File();
    void readWAVFile();

};


#endif //CS327PROJECT4_SOUNDFILE_H
