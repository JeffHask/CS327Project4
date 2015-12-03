//
// Created by jeffrey on 11/7/15.
//

#include "headers/SampleLine.h"
#include <iostream>
#include <stdexcept>

using namespace std;

SampleLine::SampleLine(string line, int samplesNeeded, int bitRes) {
    numberOfChannels = samplesNeeded;
    channels = new int[samplesNeeded];
    handleSamples(line,samplesNeeded, bitRes);
}

SampleLine::SampleLine(const SampleLine &copy) {
    this->numberOfChannels = copy.numberOfChannels;
    this->channels = new int[numberOfChannels];
    for (int i = 0; i < numberOfChannels; ++i) {
        this->channels[i] = copy.channels[i];
    }
}

void SampleLine::handleSamples(string samples, int samplesNeeded, int bitRes) {
    int maxValue = 1;
    int minValue = -1;
    int j;
    for(j = 0; j < bitRes; j++) {
        maxValue = maxValue * 2;
        minValue = minValue * 2;
    }
    int numChannels = 0;
    int i = 0;
    int singleChannel;
    char sample[10];
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

//    std::cout << channels[0] << std::endl;
//    std::cout << channels[1] << std::endl;
//    std::cout << channels[2] << std::endl;

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