//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_SHUFFLEDECORATOR_H
#define CS327PROJECT4_SHUFFLEDECORATOR_H

#include "EffectDecorator.h"

/**
 * Concrete Decorator for the sndfx program.
 */
class ShuffleDecorator : public EffectDecorator {
public:
    ShuffleDecorator(Sound * soundFile) : EffectDecorator(soundFile){};
    /**
     * This function shuffles the samples around, while keeping the channels together.
     */
    virtual void mutate();
    virtual ~ShuffleDecorator(){

    };
};


#endif //CS327PROJECT4_SHUFFLEDECORATOR_H
