//
// Created by jeffrey on 12/6/15.
//

#ifndef CS327PROJECT4_SAMPLEDOWNDECORATOR_H
#define CS327PROJECT4_SAMPLEDOWNDECORATOR_H


#include "EffectDecorator.h"
/**
 * SampleDownDecorator is a concrete decorator class for the sndfx program.
 */
class SampleDownDecorator : public EffectDecorator {
public:
    SampleDownDecorator(Sound * soundFile):EffectDecorator(soundFile){};
    /**
     * This method decrease the bit rate of a sound file. If it was 32, after mutate() is called the sound file will be
     * changed to 16-bit, and all the samples will be scaled appropriately. It supports scaling of 32 or 16 bit files, and
     * write an error message if an attempt was made at sampling down an 8-bit soundfile
     */
    virtual void mutate();
    virtual ~SampleDownDecorator() {};
};


#endif //CS327PROJECT4_SAMPLEDOWNDECORATOR_H
