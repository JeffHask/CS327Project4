//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SOUNDFILE_H
#define CS327PROJECT4_SOUNDFILE_H


#include <stdio.h>
#include <iostream>
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
    void readCS299File(char* fileName);
    void readWAVFile(char* fileName);
    void addSample(SampleLine * soundLine);
public:
    SoundFile();
    SoundFile(char* fileName, int isWav);
    void writeCS229File(char* outputFile);
    void writeWAVFile(char* outputFile);
    float lengthOfSound();
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
