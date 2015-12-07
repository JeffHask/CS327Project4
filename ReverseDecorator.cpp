//
// Created by jeffrey on 12/5/15.
//

#include "headers/ReverseDecorator.h"

void ReverseDecorator::mutate() {
    int i;
    vector<SampleLine*> pSampleLine = soundFile->getSamples();
    int numSamples = soundFile->getNumberOfSamples();
    for(i = 0; i < numSamples / 2; i++) {
        SampleLine * sampleLine = pSampleLine[i];
        soundFile->setSampleLine(i,pSampleLine[numSamples - i - 1]);
        soundFile->setSampleLine(numSamples-i-1,sampleLine);
    }
    EffectDecorator::mutate();
}
