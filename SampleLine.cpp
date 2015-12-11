//
// Created by jeffrey on 11/7/15.
//

#include "headers/SampleLine.h"
#include <iostream>
#include <stdexcept>
#include <cmath>
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
    int maxValue;
    int minValue;
    maxValue = pow(2, bitRes -1) -1;
    minValue = maxValue * -1;
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
            channels.push_back(singleChannel);
            numChannels++;
            i = 0;
        } else {
            sample[i] = c;
            i++;
        }
    }
    sample[i] = '\0';
    sscanf(sample,"%d", &singleChannel);
    channels.push_back(singleChannel);
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