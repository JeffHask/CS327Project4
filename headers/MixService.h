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
     *Creates a MixService for sndmix. only important switch for sndmix is at index 0, which is for the help message switch.
     *
     * If the help switch is there, no files will be processed, and the when run is called, only the help message will appear
     */
    MixService(int switches[], vector<string*> soundFiles,int numberOfSoundsFiles, string outputFileName, vector<float> multiplyers);
    virtual ~MixService() {
        soundFiles.clear();
    }
    /**
     * Method inherited by service, If help == 0, then the sound will 'mix', by multiplying all values of the samples by a
     * value that was passed in, and then add the sound files together, not to be mistaken with concatenate.
     */
    virtual void run();

private:
    vector<SoundFile *> soundFiles;
    int numberOfSoundFiles;
    string outputFileName;
    void mixSound();
};


#endif //CS327PROJECT4_MIXSERVICE_H
