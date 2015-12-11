//
// Created by jeffrey on 12/5/15.
//
#include <cmath>
#include "headers/SampleUpDecorator.h"

void SampleUpDecorator::mutate() {
    if(soundFile->getBitDepth() == 32) {
        __throw_invalid_argument("Error: up sampling above 32 bit is not allowed.");
    }
    int bitDepth = soundFile->getBitDepth() == 16 ? 16 : 8;
    soundFile->setBitDepth(bitDepth == 16 ? 32 : 16);
    double val = pow(2,bitDepth);
    vector<SampleLine*> sampleLines = soundFile->getSamples();
    int i;
    for(i = 0; i < soundFile->getNumberOfSamples(); i++) {
        int j;
        for(j = 0; j < soundFile->getNumberOfChannels(); j++) {
            sampleLines[i]->setChannel(j,(int)(sampleLines[i]->getChannels()[j] * val));
        }
    }
    EffectDecorator::mutate();
}