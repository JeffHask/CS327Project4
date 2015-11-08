//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SOUNDFILE_H
#define CS327PROJECT4_SOUNDFILE_H


#include <stdio.h>
#include "../SampleLine.h"

class SoundFile {
private:
    char *fileName;
    char *fileType;
    int sampleRate;
    int bitDepth;
    int numberOfChannels;
    SampleLine *samples;
    int lengthOfSound;

public:
    SoundFile();
    SoundFile(char* fileName);
    void readCS299File(char* fileName);
    void readWAVFile(char* fileName);
    void writeFile(FILE* outputFile);
    int setSampleLine(int index, SampleLine sampleLine) {
        samples[index] = sampleLine;
    }


    char *getFileName() const {
        return fileName;
    }

    void setFileName(char *fileName) {
        SoundFile::fileName = fileName;
    }

    char *getFileType() const {
        return fileType;
    }

    void setFileType(char *fileType) {
        SoundFile::fileType = fileType;
    }

    int getSampleRate() const {
        return sampleRate;
    }

    void setSampleRate(int sampleRate) {
        SoundFile::sampleRate = sampleRate;
    }

    int getBitDepth() const {
        return bitDepth;
    }

    void setBitDepth(int bitDepth) {
        SoundFile::bitDepth = bitDepth;
    }

    int getNumberOfChannels() const {
        return numberOfChannels;
    }

    void setNumberOfChannels(int numberOfChannels) {
        SoundFile::numberOfChannels = numberOfChannels;
    }

    SampleLine *getSamples() const {
        return samples;
    }

    void setSamples(SampleLine *Samples) {
        SoundFile::samples = Samples;
    }

    int getLengthOfSound() const {
        return lengthOfSound;
    }

    void setLengthOfSound(int lengthOfSound) {
        SoundFile::lengthOfSound = lengthOfSound;
    }
};


#endif //CS327PROJECT4_SOUNDFILE_H
