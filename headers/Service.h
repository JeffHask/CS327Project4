//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SERVICE_H
#define CS327PROJECT4_SERVICE_H

//TODO documentation

#include "SoundFile.h"

/**
 * Interface for the InfoService, MixService, and ConcatService. It was created to simplify the use of the 3 programs,
 * allowing them to reuse code.
 */
class Service {
protected:
    int help;
    virtual void helperMessage() = 0;
public:
    virtual ~Service() { };

    /**
     * Starts what needs to be ran,
     */
    virtual void run() = 0;
};


#endif //CS327PROJECT4_SERVICE_H
