//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_RANDOMDECORATOR_H
#define CS327PROJECT4_RANDOMDECORATOR_H

#include "EffectDecorator.h"

//TODO
/**
 * SamplesUpDecorator is a concrete decorator for the sndfx program.
 */
class SampleUpDecorator : public EffectDecorator {
public:
    SampleUpDecorator(Sound * soundFile): EffectDecorator(soundFile){};
    /**
     * This function up samples the samples of the given SoundFile. It scales the samples up appropriately.
     * It is valid on 8-bit and 16-bit sound files only. Throws an invalid argument exception if an attempt was made to
     * up sample a 32-bit sound file
     */
    virtual void mutate();
    virtual ~SampleUpDecorator(){

    };
};


#endif //CS327PROJECT4_RANDOMDECORATOR_H
