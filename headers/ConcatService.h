//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_CONCATSERVICE_H
#define CS327PROJECT4_CONCATSERVICE_H

#include "Service.h"
#include "SoundFile.h"
/**
 * Concat Service is used for completing concatenation of SoundFiles.
 */
class ConcatService : public Service {
    private:
        /**
         * A Vector that holds all sound files passed in
         */
        vector<SoundFile*> soundFiles;
        /**
         * Keeps try of how many SoundFiles that were read in
         */
        int numberOfSoundFiles;
        /**
         * holds the name of the concatenated output file
         */
        string outputFileName;
        /**
         * Method that does the concatenation. It goes through the vector of sound files, adding the samples to the first
         * sound file argument. It outputs the sound file to stdout unless an output file is specified.
         *
         * If the -w switch is present and the outputfile is not a file ending with .wav, an invalid argument exception
         * is thrown. It also throws an invalid argument exception if the outputfile is not a .cs229 file when the -w switch
         * is not present.
         */
        void concatFiles(vector<SoundFile*> soundFiles);

    public:
        /**
         * Default constructor for concat service. It sets nothing.
         */
        ConcatService();
        virtual ~ConcatService() {
            soundFiles.clear();
        }
        /**
         * Constructor for ConcatService.
         * param switches - filled with switch information. For sndcat, the only important switches are at index 0 and 1.
         * switches[0] contains information about the -h switch, 0 if it is not present, 1 if it is.
         * switches[1] contains information about the -w switch, o if it is not present, 1 if it is.
         *
         * param soundFiles- filled with file names that are opened and read inside this constructor.
         *
         * param numberSoundFiles - number of files passed in as arguments
         *
         * param outputFileName- contains the desired outputfile name if the -o switch is specified. If the switch isn't
         * present, it will default to " "
         *
         * If the help switch is present, the constructor does not read the input files
         */
        ConcatService(int switches[], vector<string*> & soundFiles,int numberOfSoundsFiles, string outputFileName);
        /**
         * Prints out information about the sndcat service, and lists the acceptable switches
         */
        virtual void helperMessage();
        /**
         * Inherited method from the Service class . It checks to see if protected variable 'help' equals one, and if it is,
         * it calls helperMessage(). Otherwise, it continues with the concatenation and calls concatFiles()
         */
        virtual void run();
    };


#endif //CS327PROJECT4_CONCATSERVICE_H
