//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_SOUND_H
#define CS327PROJECT4_SOUND_H

//TODO documentation

#include <vector>
#include "SampleLine.h"

using namespace std;
class SampleLine;
class Sound {

protected:
    string fileName;
    string fileType;
    int sampleRate;
    int bitDepth;
    int numberOfChannels;
    std::vector<SampleLine*> samples;
    int numberOfSamples;
public:
    virtual ~Sound() {
        samples.clear();
    }
    virtual void print(string outputFile)= 0;
    virtual void mutate() = 0;
    virtual void setSampleLine(int index, SampleLine *sampleLine) = 0;


    virtual string getFileName() const = 0;

    virtual void setFileName(char *fileName) =0;

    virtual string getFileType() const = 0;

    virtual int getSampleRate() const =0;

    virtual void setSampleRate(int sampleRate) =0;

    virtual int getBitDepth() const =0;

    virtual void setBitDepth(int bitDepth) =0;

    virtual int getNumberOfChannels() const =0;

    virtual void setNumberOfChannels(int numberOfChannels) =0;

    virtual vector<SampleLine*> getSamples() const =0;

    virtual void setSamples(vector<SampleLine*> samples) =0;

    virtual int getNumberOfSamples() const =0;

    virtual void setNumberOfSamples(int numberOfSamples) =0;

    virtual void setFileType(const string &fileType) = 0;

    virtual void setFileName(const string &fileName) =0;
};


#endif //CS327PROJECT4_SOUND_H
