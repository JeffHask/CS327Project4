//
// Created by jeffrey on 12/5/15.
//
#include "headers/ShuffleDecorator.h"

void ShuffleDecorator::mutate() {

    int numSamples = soundFile->getNumberOfSamples();
    vector<SampleLine*> shuffledSamples;
    shuffledSamples.resize(numSamples);
    int *slotsFilled= new int[numSamples];
    fill(slotsFilled,slotsFilled + numSamples,0);
    int i;
    for(i = 0; i < numSamples; i++) {
        srand((unsigned) time(0));
        int slot = rand() % numSamples;
        while(slot != -1) {
            if(!slotsFilled[slot]) {
                shuffledSamples[slot] = soundFile->getSamples()[i];
                slotsFilled[slot] = 1;
                slot = -1;
            } else {
                slot = rand() % numSamples;
            }
        }
    }
    soundFile->setSamples(shuffledSamples);


    EffectDecorator::mutate();
}
