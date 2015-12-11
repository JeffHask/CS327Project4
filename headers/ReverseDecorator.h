//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_REVERSEDECORATOR_H
#define CS327PROJECT4_REVERSEDECORATOR_H

#include "EffectDecorator.h"

/**
 * Reverse Decorator is one of the concrete classes for sndfx.
 */
class ReverseDecorator : public EffectDecorator {
public:
    ReverseDecorator(Sound * soundFile) : EffectDecorator(soundFile){};
    /**
     * ReverseDecorator mutate() does exactly what the class name implies, it reverses the samples.
     *
     */
    virtual void mutate();
    virtual ~ReverseDecorator() {
    };
};


#endif //CS327PROJECT4_REVERSEDECORATOR_H
