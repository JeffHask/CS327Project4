//
// Created by jeffrey on 12/8/15.
//

#ifndef CS327PROJECT4_ABCFILE_H
#define CS327PROJECT4_ABCFILE_H


#include "Sound.h"
#include "AbcInstrument.h"
#include "SoundFile.h"

using namespace std;

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
    SoundFile *createSoundFile();
    int sineWave(Note *note, int numSamplesPerCount, SoundFile * soundFile, int newChannel);
    int triangleWave(Note note, int numSamplesPerCount, SoundFile * soundFile);
    int sawtoothWave(Note note, int numSamplesPerCount, SoundFile * soundFile);
    int pulseWave(Note note, int numSamplesPerCount, SoundFile * soundFile);

public:
    AbcFile(int help, string outputFile,  vector<int> mute, int toWav, string inputFile, int bits, int sampleRate);
    void writeToCs229File(string outputFile);
    void writeToWavFile(string outputFile);
    int const getNumberOfInstruments() {
        return (int)instruments.size();
    }
private:
    void readAbcFile(string inputfile);
    int getMaxSamples(vector<AbcInstrument*> instrument);
};


#endif //CS327PROJECT4_ABCFILE_H
