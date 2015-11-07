//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_CONCATSERVICE_H
#define CS327PROJECT4_CONCATSERVICE_H

#include "Service.h"
#include "SoundFile.h"

class ConcatService : Service {
    private:
        int helpMessage;
        int toWav;
        char* outputFileName;
        char* soundFiles[];
        SoundFile concatFiles(char* soundFiles[]);

    public:
        ConcatService();
        ConcatService(int helpSwitch, int toWAV, char* soundFiles[], char* outptFileName);
        virtual void helperMessage();
        void run(int hasHSwitch);
    };


#endif //CS327PROJECT4_CONCATSERVICE_H
