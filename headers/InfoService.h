//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_INFOSERVICE_H
#define CS327PROJECT4_INFOSERVICE_H

#include <iostream>
#include "Service.h"

using namespace std;

class InfoService : public Service {

private:
    void printInfo();
public:
    InfoService();
    InfoService(int switches[],string** soundFiles, int numberOfSoundFiles);
    ~InfoService();
    virtual void helperMessage();
    virtual void run();
};


#endif //CS327PROJECT4_INFOSERVICE_H
