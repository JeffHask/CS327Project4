//
// Created by jeffrey on 12/4/15.
//

#ifndef CS327PROJECT4_CONVERTSERVICE_H
#define CS327PROJECT4_CONVERTSERVICE_H


#include "Service.h"

class ConvertService : public Service {
//TODO documentation

private:
    int isWav;
    string outputFileName;
    string inputFileName;

public:
    ConvertService(int help, string inputFile, string outputFile);
    virtual void run();
    virtual void helperMessage();
};


#endif //CS327PROJECT4_CONVERTSERVICE_H
