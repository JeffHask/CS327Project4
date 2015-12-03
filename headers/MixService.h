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
    MixService(int switches[], string** soundFiles,int numberOfSoundsFiles, string outputFileName, int* multiplyers);
    virtual ~MixService() {
        delete[] soundFiles;
    }
    virtual void run();

private:
    string outputFileName;
    void mixSound();
};


#endif //CS327PROJECT4_MIXSERVICE_H
