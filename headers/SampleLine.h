//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SAMPLELINE_H
#define CS327PROJECT4_SAMPLELINE_H


#include <iostream>

class SampleLine {
private:
    int *channels;
    int numberOfChannels;
    void handleSamples(std::string samples, int samplesNeeded, int bitRes);
public:
    SampleLine(){}
//    ~SampleLine();
    SampleLine(SampleLine *copy);
    SampleLine(std::string, int samplesNeeded, int bitRes);
    int* getChannels() {
        return channels;
    };
    int getNumberOfChannels() {
        return numberOfChannels;
    };
};


#endif //CS327PROJECT4_SAMPLELINE_H
