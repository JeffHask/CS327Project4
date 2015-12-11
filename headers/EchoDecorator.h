//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_ECHODECORATOR_H
#define CS327PROJECT4_ECHODECORATOR_H


#include "Sound.h"
#include "EffectDecorator.h"

/**
 * Concrete Decotator that will add an echo to the sound file passed in
 */
class EchoDecorator : public EffectDecorator  {
public:
    /**
     * An empty constructor that passes the param soundFile to its superclass
     */
    EchoDecorator(Sound *soundFile): EffectDecorator(soundFile){};
    /**
     * Modifies the samples by adding an 'echo' to it. It triples the number of samples, as it places the a sample, then
     * fills all channels with 0's, then places the same sample again, effectively creating a small echo.
     */
    virtual void mutate();
    virtual ~EchoDecorator() {
    };
};


#endif //CS327PROJECT4_ECHODECORATOR_H
