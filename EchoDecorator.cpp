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
    SampleLine *lowValSample = new SampleLine();
    int channels = soundFile->getNumberOfChannels();
    lowValSample->setNumberOfChannels(channels);
    int i;
    for(i = 0; i < channels; i++) {
        lowValSample->setChannel(i,0);
    }
    for(i = 0; i < numSamples; i++) {
        echoSamples.push_back(soundFileSamples[i]);
        echoSamples.push_back(lowValSample);
        echoSamples.push_back(soundFileSamples[i]);
    }
    soundFile->setSamples(echoSamples);
    soundFile->setNumberOfSamples(numSamples * 3);
    EffectDecorator::mutate();
}