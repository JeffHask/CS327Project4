//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_CONCATSERVICE_H
#define CS327PROJECT4_CONCATSERVICE_H

#include "Service.h"
#include "SoundFile.h"
//TODO documentation
class ConcatService : public Service {
    private:
        SoundFile **soundFiles;
        int numberOfSoundFiles;
        int toWav;
        string outputFileName;
        void concatFiles(SoundFile** soundFiles);

    public:
        ConcatService();
        virtual ~ConcatService() {
            delete[] soundFiles;
        }
        ConcatService(int switches[], string** soundFiles,int numberOfSoundsFiles, string outputFileName);
        virtual void helperMessage();
        virtual void run();
    };


#endif //CS327PROJECT4_CONCATSERVICE_H
