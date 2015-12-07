//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_ECHODECORATOR_H
#define CS327PROJECT4_ECHODECORATOR_H


#include "Sound.h"
#include "EffectDecorator.h"

class EchoDecorator : public EffectDecorator  {
public:
    EchoDecorator(Sound *soundFile): EffectDecorator(soundFile){};
    virtual void mutate();
    virtual ~EchoDecorator() {
    cout << "Deleting echo" << endl;
    };
};


#endif //CS327PROJECT4_ECHODECORATOR_H
