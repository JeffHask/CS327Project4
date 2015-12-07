//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_RANDOMDECORATOR_H
#define CS327PROJECT4_RANDOMDECORATOR_H

#include "EffectDecorator.h"

//TODO
class SampleUpDecorator : public EffectDecorator {
public:
    SampleUpDecorator(Sound * soundFile): EffectDecorator(soundFile){};
    virtual void mutate();
    virtual ~SampleUpDecorator(){

    };
};


#endif //CS327PROJECT4_RANDOMDECORATOR_H
