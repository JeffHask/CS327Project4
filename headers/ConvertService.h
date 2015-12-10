//
// Created by jeffrey on 12/4/15.
//

#ifndef CS327PROJECT4_CONVERTSERVICE_H
#define CS327PROJECT4_CONVERTSERVICE_H


#include "Service.h"

/**
 * Convert Service is used to convert sound files from .cs229 to .wav, and .wav to .cs229
 */
class ConvertService : public Service {

private:
    /**
     * Indicates if the file being converted is a .wav file
     */
    int isWav;
    /**
     * The file that the sound file will be written to.
     */
    string outputFileName;
    /**
     * The name of the input file.
     */
    string inputFileName;

public:
    /**
     * params:
     *
     * help - equals 1 if the -h switch is present.
     * inputfile - the filename of the sound file that will be converted
     * outputfile - the filename that the sound file will be written to
     *
     * The constructor sets all the variables that convertService has access to. It sets isWav depending on if the
     * inputFile ends with .wav
     */
    ConvertService(int help, string inputFile, string outputFile);
    /**
     * Inherited method from Service.cpp.
     *
     * If the protected variable from superclass Service 'help' equals 1, then the program will call the helperMessage()
     * method and the program will exit. Otherwise, it will create the sound file and call either writeCs229File() or
     * writeWavFile(), depending on what type the inputFile is
     */
    virtual void run();
    /**
     * Method that shows the help screen, which gives information about the program and acceptable switches
     */
    virtual void helperMessage();
};


#endif //CS327PROJECT4_CONVERTSERVICE_H
