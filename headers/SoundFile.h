//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SOUNDFILE_H
#define CS327PROJECT4_SOUNDFILE_H


#include <stdio.h>
#include <iostream>
#include <fstream>
#include "SampleLine.h"

using namespace std;

class SoundFile {
private:
    string fileName;
    string fileType;
    int sampleRate;
    int bitDepth;
    int numberOfChannels;
    SampleLine **samples;
    int numberOfSamples;
    int maxSamples;

private:
    void readCS299File(string fileName);
    void readWAVFile(string fileName);
public:
    SoundFile();
    SoundFile(string fileName, int isWav);
    ~SoundFile() {
      delete[] samples;
    };
    void writeCS229File(FILE* outputFile);
    void writeWAVFile(FILE* outputFile);
    float lengthOfSound();
    void addSample(SampleLine * soundLine);
    void operator +=(SoundFile *soundFile);
    SoundFile *operator +(SoundFile *soundFile);
    SoundFile *operator *(int multi);
    void setSampleLine(int index, SampleLine *sampleLine) {
        samples[index] = sampleLine;
    }


    string getFileName() const {
        return fileName;
    }

    void setFileName(char *fileName) {
        SoundFile::fileName = fileName;
    }

    string getFileType() const {
        return fileType;
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

    SampleLine **getSamples() const {
        return samples;
    }

    void setSamples(SampleLine **Samples) {
        SoundFile::samples = Samples;
    }

    int getNumberOfSamples() const {
        return numberOfSamples;
    }

    void setNumberOfSamples(int numberOfSamples) {
        SoundFile::numberOfSamples = numberOfSamples;
    }

    void setFileType(const string &fileType) {
        SoundFile::fileType = fileType;
    }

    void setFileName(const string &fileName) {
        SoundFile::fileName = fileName;
    }
};


#endif //CS327PROJECT4_SOUNDFILE_H
