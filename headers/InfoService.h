//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_INFOSERVICE_H
#define CS327PROJECT4_INFOSERVICE_H


#include "Service.h"

class InfoService : Service {

private:
    int help;
    void printInfo();
public:
    virtual void helperMessage();
    void run();
};


#endif //CS327PROJECT4_INFOSERVICE_H
