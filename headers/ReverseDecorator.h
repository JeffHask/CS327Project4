//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_REVERSEDECORATOR_H
#define CS327PROJECT4_REVERSEDECORATOR_H

#include "EffectDecorator.h"

//TODO
class ReverseDecorator : public EffectDecorator {
public:
    ReverseDecorator(Sound * soundFile) : EffectDecorator(soundFile){};
    virtual void mutate();
    virtual ~ReverseDecorator() {

    };
};


#endif //CS327PROJECT4_REVERSEDECORATOR_H
