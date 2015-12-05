//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SERVICE_H
#define CS327PROJECT4_SERVICE_H

//TODO documentation

#include "IService.h"
#include "SoundFile.h"

class Service : public IService {
protected:
    int help;
    virtual void helperMessage() = 0;
public:
    virtual ~Service() { };
    virtual void run() = 0;
};


#endif //CS327PROJECT4_SERVICE_H
