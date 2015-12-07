//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SOUNDFILE_H
#define CS327PROJECT4_SOUNDFILE_H


#include <stdio.h>
#include <iostream>
#include <fstream>
#include "SampleLine.h"
#include "Sound.h"
//TODO documentation

using namespace std;

class SoundFile : public Sound {
private:
//    string fileName;
//    string fileType;
//    int sampleRate;
//    int bitDepth;
//    int numberOfChannels;
//    SampleLine **samples;
//    int numberOfSamples;
//    int maxSamples;

private:
    void readCS299File(string fileName);
    void readWAVFile(string fileName);
public:
    SoundFile();
    SoundFile(string fileName, int isWav);
    virtual ~SoundFile() {
      delete[] samples;
    };
    void writeCS229File(string outputFileName);
    void writeWAVFile(string outputFileName);
    float lengthOfSound();
    void addSample(SampleLine * soundLine);
    void operator +=(SoundFile *soundFile);
    SoundFile *operator +(SoundFile *soundFile);
    SoundFile *operator *(int multi);
    virtual void mutate();
    virtual void print(string outputFile);
    virtual void setSampleLine(int index, SampleLine *sampleLine) {
        samples[index] = sampleLine;
    }


    virtual string getFileName() const {
        return fileName;
    }

    virtual void setFileName(char *fileName) {
        SoundFile::fileName = fileName;
    }

    virtual string getFileType() const {
        return fileType;
    }

    virtual int getSampleRate() const {
        return sampleRate;
    }

    virtual void setSampleRate(int sampleRate) {
        SoundFile::sampleRate = sampleRate;
        cout << "setting rate" << endl;
    }

    virtual int getBitDepth() const {
        return bitDepth;
    }

    virtual void setBitDepth(int bitDepth) {
        SoundFile::bitDepth = bitDepth;
    }

    virtual int getNumberOfChannels() const {
        return numberOfChannels;
    }

    virtual void setNumberOfChannels(int numberOfChannels) {
        SoundFile::numberOfChannels = numberOfChannels;
    }

    virtual SampleLine **getSamples() const {
        return samples;
    }

    virtual void setSamples(SampleLine **Samples) {
        SoundFile::samples = Samples;
    }

    virtual int getNumberOfSamples() const {
        return numberOfSamples;
    }

    virtual void setNumberOfSamples(int numberOfSamples) {
        SoundFile::numberOfSamples = numberOfSamples;
    }

    virtual void setFileType(const string &fileType) {
        SoundFile::fileType = fileType;
    }

    virtual void setFileName(const string &fileName) {
        SoundFile::fileName = fileName;
    }
};


#endif //CS327PROJECT4_SOUNDFILE_H
