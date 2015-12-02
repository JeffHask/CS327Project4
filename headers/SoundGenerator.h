//
// Created by jeffrey on 11/30/15.
//

#ifndef CS327PROJECT4_SOUNDGENERATOR_H
#define CS327PROJECT4_SOUNDGENERATOR_H

#include "iostream"
#include "SoundFile.h"

class SoundGenerator {
public:
    class SoundBuilder;
    void print();

private:
    int bitDepth;
    int sampleRate;
    int frequency;
    int duration;
    int volume;
    int attack;
    int decay;
    int sustain;
    int release;
    int type;
    FILE * outputFile;
    SoundFile setupFile();

    SoundGenerator(const int bitDepth, const int sampleRate, const int frequency, const int duration, const int volume, const int attack,
                   const int decay, const int sustain, const int release, const int type, FILE * outputFile) :
            bitDepth(bitDepth), sampleRate(sampleRate), frequency(frequency),duration(duration),volume(volume), attack(attack), decay(decay), sustain(sustain),
            release(release),type(type), outputFile(outputFile){};
};

class SoundGenerator::SoundBuilder {
private:
    int bitDepth = 16;
    int sampleRate = 4;
    int frequency;
    int duration = 10;
    int volume = 1;
    int attack = 3;
    int decay = 2;
    int sustain = 3;
    int release = 2;
    int type = 1;
    FILE *outputFile;

public:
    SoundBuilder(){};

    SoundBuilder& setBitDepth(const int bitDepth) {
        this->bitDepth = bitDepth;
        return  *this;
    };

    SoundBuilder& setSampleRate(const int sampleRate) {
        this->sampleRate = sampleRate;
        return *this;
    };

    SoundBuilder& setFrequency(const int frequency) {
        this->frequency = frequency;
        return *this;
    };

    SoundBuilder& setVolume(const int volume) {
        this->volume = volume;
        return *this;
    };

    SoundBuilder& setAttack(const int attack) {
        this->attack = attack;
        return *this;
    };

    SoundBuilder& setDecay(const int decay) {
        this->decay = decay;
        return *this;
    };
    SoundBuilder& setSustain(const int sustain) {
        this->sustain = sustain;
        return *this;
    };
    SoundBuilder& setRelease(const int release) {
        this->release = release;
        return *this;
    };
    SoundBuilder& setType(const int type) {
        this->type = type;
        return *this;
    };
    SoundBuilder& setOutputFile(const int duration) {
        this->duration = duration;
        return *this;
    };

    SoundGenerator build() {
        return SoundGenerator(bitDepth,sampleRate,frequency,duration,volume,attack,decay,sustain,release,type,outputFile);
    };
};


#endif //CS327PROJECT4_SOUNDGENERATOR_H