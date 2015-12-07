//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_MIXSERVICE_H
#define CS327PROJECT4_MIXSERVICE_H

//TODO documentation

#include "Service.h"

class MixService : public Service {
protected:
    virtual void helperMessage();
public:
    MixService();
    MixService(int switches[], string** soundFiles,int numberOfSoundsFiles, string outputFileName, int* multiplyers);
    virtual ~MixService() {
        soundFiles.clear();
    }
    virtual void run();

private:
    vector<SoundFile *> soundFiles;
    int numberOfSoundFiles;
    string outputFileName;
    void mixSound();
};


#endif //CS327PROJECT4_MIXSERVICE_H
