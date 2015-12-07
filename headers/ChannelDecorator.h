//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_CHANNELDECORATOR_H
#define CS327PROJECT4_CHANNELDECORATOR_H


#include "Sound.h"
#include "EffectDecorator.h"

class ChannelDecorator : public EffectDecorator {
public:
    ChannelDecorator(Sound * soundFile, int numChannelsToAdd) :
            EffectDecorator(soundFile), numChannelsToAdd(numChannelsToAdd){ }
    virtual void mutate();
    virtual ~ChannelDecorator() {};

private:
    int numChannelsToAdd;
};


#endif //CS327PROJECT4_CHANNELDECORATOR_H
