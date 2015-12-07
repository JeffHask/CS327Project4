//
// Created by jeffrey on 12/6/15.
//

#include <cmath>
#include "headers/SampleDownDecorator.h"
void SampleDownDecorator::mutate() {
    if(soundFile->getBitDepth() == 8) {
        __throw_invalid_argument("ERROR: down sampling below 8 bit not allowed");
    }
    int bitDepth = soundFile->getBitDepth() == 32 ? 16 : 8;
    soundFile->setBitDepth(bitDepth == 16 ? 16 : 8);
    double val = pow(2,bitDepth);
    vector<SampleLine*> sampleLines = soundFile->getSamples();
    int i;
    for(i = 0; i < soundFile->getNumberOfSamples(); i++) {
        int j;
        for(j = 0; j < soundFile->getNumberOfChannels(); j++) {
            sampleLines[i]->setChannel(j,(int)(sampleLines[i]->getChannels()[j] / val + 0.5));
        }
    }
    EffectDecorator::mutate();
}