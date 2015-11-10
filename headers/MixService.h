//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_MIXSERVICE_H
#define CS327PROJECT4_MIXSERVICE_H


#include "Service.h"

class MixService : public Service {
protected:
    virtual void helperMessage();
public:
    MixService();
    MixService(int helpMessage, char* outputFile);
    virtual void run();
};


#endif //CS327PROJECT4_MIXSERVICE_H
