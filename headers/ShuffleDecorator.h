//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_SHUFFLEDECORATOR_H
#define CS327PROJECT4_SHUFFLEDECORATOR_H

#include "EffectDecorator.h"

//TODO
class ShuffleDecorator : public EffectDecorator {
public:
    ShuffleDecorator(Sound * soundFile) : EffectDecorator(soundFile){};
    virtual void mutate();
    virtual ~ShuffleDecorator(){};
};


#endif //CS327PROJECT4_SHUFFLEDECORATOR_H
