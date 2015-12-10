//
// Created by jeffrey on 11/7/15.
//

#include "headers/SampleLine.h"
#include <iostream>
#include <stdexcept>
//TODO, max of 8 bit is 125, or 2^7 - 1
using namespace std;

SampleLine::SampleLine(string line, int samplesNeeded, int bitRes) {
    numberOfChannels = samplesNeeded;
    handleSamples(line,samplesNeeded, bitRes);
}

SampleLine::SampleLine(int val) {
    numberOfChannels = 1;
    channels.push_back(val);
}

SampleLine::SampleLine(const SampleLine &copy) {
    this->numberOfChannels = copy.numberOfChannels;
    for (int i = 0; i < numberOfChannels; ++i) {
        channels.push_back(copy.channels[i]);
    }
}

void SampleLine::handleSamples(string samples, int samplesNeeded, int bitRes) {
    int maxValue = 1;
    int minValue = -1;
    int j;
    for(j = 1; j < bitRes; j++) {
        maxValue = maxValue * 2;
        minValue = minValue * 2;
    }
    int numChannels = 0;
    int i = 0;
    int singleChannel;
    char sample[33];
    for(char c : samples) {
        if(c > '9') {
            __throw_invalid_argument("Invalid Sample: Not a number");
        }
        if(c < '0') {
            if(i == 0) {
                continue;
            }
            sample[i] = '\0';
            sscanf(sample,"%d", &singleChannel);
            if(singleChannel > maxValue) {
                singleChannel = maxValue;
            }
            if(singleChannel < minValue) {
                singleChannel = minValue;
            }
            channels[numChannels] = singleChannel;
            numChannels++;
            i = 0;
        } else {
            sample[i] = c;
            i++;
        }
    }
    sample[i] = '\0';
    sscanf(sample,"%d", &singleChannel);
    channels[numChannels] = singleChannel;
    numChannels++;
    if(numChannels != samplesNeeded) {
        throw invalid_argument("Invalid number of channels in the sample data");
    }
}

void SampleLine::operator+=(SampleLine *sampleLine) {
    int i;
    for (i = 0; i < numberOfChannels; ++i) {
        this->channels[i]+=sampleLine->channels[i];
    }
}

//void SampleLine::operator=(SampleLine *sampleLine) {
//    for (int i = 0; i <  this->numberOfChannels; ++i) {
//        this->channels[i] = sampleLine->channels[i];
//    }
//}