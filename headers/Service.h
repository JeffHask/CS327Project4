//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SERVICE_H
#define CS327PROJECT4_SERVICE_H


#include "IService.h"
#include "SoundFile.h"

class Service : public IService {
protected:
    int numberOfSoundFiles;
    int help;
    SoundFile **soundFiles;
    virtual void helperMessage() = 0;
public:
    virtual ~Service() { };
    virtual void run() = 0;
};


#endif //CS327PROJECT4_SERVICE_H
