//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_MIXSERVICE_H
#define CS327PROJECT4_MIXSERVICE_H

//TODO documentation

#include "Service.h"

/**
 * Mix Service is used to multiply sound file samples by a constant value,
 * and then add the different sound files samples together
 */
class MixService : public Service {
protected:
    /**
     * Prints to stdout infomation about the sndmix program and the acceptable switches
     */
    virtual void helperMessage();
public:
    /**
     *
     */
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
