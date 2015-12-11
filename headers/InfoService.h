//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_INFOSERVICE_H
#define CS327PROJECT4_INFOSERVICE_H

#include <iostream>
#include "Service.h"

using namespace std;

/**
 * Info Service is a class used for printing out information about passed in .cs229 files.
 */
class InfoService : public Service {
//TODO documentation

private:
    /**
     * A vector holding all the sound files that were passing in
     */
    vector<SoundFile *> soundFiles;
    /**
     * The number of sound files
     */
    int numberOfSoundFiles;
    /**
     * private method that does the actual printing. It prints out everything about the file.
     */
    void printInfo();
public:
    /**
     * Constructor for InfoService
     * params:
     * switches[] - the only index that matters here is the 0 index, as it contains information if you want to print out
     * the help screen.
     *
     * soundfiles - the name of all the input files
     *
     * If the help == 1, the input files will not be read
     *
     * throws invalid argument exception if one of the sound files are invalid
     */
    InfoService(int switches[], vector<string*> & soundFiles, int numberOfSoundFiles);
    virtual ~InfoService() {
        soundFiles.clear();
    };
    /**
     * Prints out the helper page with contains information about the sndinfo program and the acceptable switches
     */
    virtual void helperMessage();
    /**
     * If help == 1, it will call helpMessage(), else if will call printInfo()
     */
    virtual void run();
};


#endif //CS327PROJECT4_INFOSERVICE_H
