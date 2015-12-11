//
// Created by jeffrey on 12/8/15.
//

#ifndef CS327PROJECT4_ABCFILE_H
#define CS327PROJECT4_ABCFILE_H


#include "Sound.h"
#include "AbcInstrument.h"
#include "SoundFile.h"

using namespace std;
/**
 * Class for handling .abc229 files. It's main function is to parse through a .abc229 file, perform operations based on
 * the file, and then send it back to the user as a .cs229 file.
 */
class AbcFile {

private:
    int tempo;
    int help;
    string outputfile;
    string inputFile;
    vector<AbcInstrument *> instruments;
    int bitRate;
    int sampleRate;
    vector<int> mute;
    int toWav;
    /**
     * The big method for this class. It goes through each instrument, determines wave type, then adds all the instruments
     * to a single SoundFile.
     */
    SoundFile *createSoundFile();
    /**
     * Used to create sine waves, one note at a time
     */
    int sineWave(Note *note, int numSamplesPerCount, SoundFile * soundFile);
    /**
     * Used to create triangle waves, one note at a time
     */
    int triangleWave(Note *note, int numSamplesPerCount, SoundFile * soundFile);
    /**
     * Used to create sawtooth waves, one note at a time
     */
    int sawtoothWave(Note *note, int numSamplesPerCount, SoundFile * soundFile);
    /**
     * Used to create pulse waves, one note at a time. The pulse rate is set at .5
     */
    int pulseWave(Note *note, int numSamplesPerCount, SoundFile * soundFile);

public:
    AbcFile(int help, string outputFile,  vector<int> mute, int toWav, string inputFile, int bits, int sampleRate);
    void writeToCs229File(string outputFile);
//    void writeToWavFile(string outputFile);
    int const getNumberOfInstruments() {
        return (int)instruments.size();
    }
private:
    /**
     * Method to parse abc file. Sets the header information into this class, and sets instrument data into the
     * AbcInstrument  class
     */
    void readAbcFile(string inputfile);
    /**
     * Used to create uniform channels, it finds which instrument has the highest amount of samples. This info is then
     * used inside the createSoundFile() method, where all instruments that don't have that many samples are loaded with
     * 0s for every samples they are short of the max channels.
     */
    int getMaxSamples(vector<AbcInstrument*> instrument);
};


#endif //CS327PROJECT4_ABCFILE_H
