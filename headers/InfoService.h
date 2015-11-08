//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_INFOSERVICE_H
#define CS327PROJECT4_INFOSERVICE_H


#include "Service.h"

class InfoService : public Service {

private:
    int help;
    void printInfo();
public:
    InfoService();
    InfoService(int help);
    virtual void helperMessage();
    virtual void run();
};


#endif //CS327PROJECT4_INFOSERVICE_H
