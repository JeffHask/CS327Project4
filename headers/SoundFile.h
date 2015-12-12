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
using namespace std;
/**
 * Main class for holding information about a cs229 file.
 */
class SoundFile : public Sound {

private:
    /**
     * As it says, it reads a given .cs229 and updates itself with the information
     */
    void readCS299File(string fileName);
public:
    SoundFile();
    SoundFile(string fileName);
    virtual ~SoundFile() {

    };
    /**
     * This writes out the sound file as a .cs229 file to a specific outputFile. If no outputfile was passed in, it
     * will print out to stdout.
     */
    void writeCS229File(string outputFileName);
    /**
     * Finds the length of how many seconds this file is
     */
    float lengthOfSound();
    /**
     * Adds another sample to the end of the file
     */
    void addSample(SampleLine * soundLine);
    /**
     * Operator overload used to concatenate SoundFiles together. Throws out an error if the Sounds do not have the
     * same bit rate, sample rate, or channels.
     */
    void operator +=(SoundFile *soundFile);
    /**
     * Operator overload used for adding samples together. It adds the sample lines of the same index together, and if
     * the passed in SoundFile has more samples it will concatenate them on the end of the file.
     */
    SoundFile *operator +(SoundFile *soundFile);
    /**
     * Operator overload that multiplies all values of the SoundFile by the multiplyer, and then adds the same numbered
     * channels together.
     */
    SoundFile *operator *(float multi);
    /**
     * The cool overload. It is used with sndplay, and it adds the passed in SoundFile as a new channel, making sure not
     * to go over the number of samples of each, as doing so would result in a seg fault.
     */
    void operator |(SoundFile * soundFile);
    /**
     * Empty mutate function, as it needs not do anything for sndFx
     */
    virtual void mutate();
    /**
     * print function for sndfx. Initially was going to be used for both writing to wav and cs229, but because of time
     * constraints writing and reading wav files is not implemented yet.
     */
    virtual void print(string outputFile);
    virtual void setSampleLine(int index, SampleLine *sampleLine) {
        *samples[index] = *sampleLine;
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

    virtual vector<SampleLine*> getSamples() const {
        return samples;
    }

    SampleLine* getSampleLine(int index) {
        return samples[index];
    }

    virtual void setSamples(vector<SampleLine*> samples) {
        SoundFile::samples = samples;
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
