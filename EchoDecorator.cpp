//
// Created by jeffrey on 12/5/15.
//

#include <cmath>
#include "headers/EchoDecorator.h"
#include "headers/SoundFile.h"

void EchoDecorator::mutate() {
    int numSamples = soundFile->getNumberOfSamples();
    vector<SampleLine*> soundFileSamples = soundFile->getSamples();
    vector<SampleLine*> echoSamples;
    echoSamples.resize(numSamples);
    SampleLine *lowValSample = new SampleLine();
    int channels = soundFile->getNumberOfChannels();
    lowValSample->setNumberOfChannels(channels);
    lowValSample->allocateChannels(channels);
    int lowVal = ((int)pow(2,soundFile->getBitDepth()) -1) * -1;
    int echoSampleIndex = 0;
    int i;
    for(i = 0; i < channels; i++) {
        lowValSample->setChannel(i,lowVal);
    }
    for(i = 0; i < numSamples; i++) {
        echoSamples[echoSampleIndex++] = soundFileSamples[i];
        echoSamples[echoSampleIndex++] = lowValSample;
        echoSamples[echoSampleIndex++] = soundFileSamples[i];
    }
    soundFile->setSamples(echoSamples);
    soundFile->setNumberOfSamples(numSamples * 3);
    EffectDecorator::mutate();
}