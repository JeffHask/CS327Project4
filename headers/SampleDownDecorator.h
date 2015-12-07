//
// Created by jeffrey on 12/6/15.
//

#ifndef CS327PROJECT4_SAMPLEDOWNDECORATOR_H
#define CS327PROJECT4_SAMPLEDOWNDECORATOR_H


#include "EffectDecorator.h"

class SampleDownDecorator : public EffectDecorator {
public:
    SampleDownDecorator(Sound * soundFile):EffectDecorator(soundFile){};
    virtual void mutate();
    virtual ~SampleDownDecorator() {}
};


#endif //CS327PROJECT4_SAMPLEDOWNDECORATOR_H
