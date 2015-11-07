//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SOUNDFILE_H
#define CS327PROJECT4_SOUNDFILE_H


#include <stdio.h>

class soundFile {
private:
    char *fileName;
    char *fileType;
    int sampleRate;
    int bitDepth;
    int numberOfChannels;
    int* Samples;
    int lengthOfSound;

public:
    soundFile();
    soundFile(char* fileName);
    void readCS299File(char* fileName);
    void readWAVFile(char* fileName);
    void writeFile(FILE* outputFile);

};


#endif //CS327PROJECT4_SOUNDFILE_H
