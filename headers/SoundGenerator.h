//
// Created by jeffrey on 11/30/15.
//

#ifndef CS327PROJECT4_SOUNDGENERATOR_H
#define CS327PROJECT4_SOUNDGENERATOR_H

#include "iostream"
#include "SoundFile.h"
//TODO documentation

class SoundGenerator {
public:
    class SoundBuilder;
    void print();
    void run(int helpMessage);
    void handleEnvelop(SoundFile* soundFile);


private:
    int bitDepth;
    int sampleRate;
    float frequency;
    float duration;
    float volume;
    float attack;
    float decay;
    float sustain;
    float release;
    int type;
    float pulseTime;
    string outputFileName;
    SoundFile *setupFile();
    void create_sine_wave(SoundFile* soundFile);
    void create_triangle_wave(SoundFile * soundFile);
    void create_sawtooth_wave(SoundFile * soundFile);
    void create_pulse_wave(SoundFile * soundFile);

    SoundGenerator(const int bitDepth, const int sampleRate, const float frequency, const float duration, const float volume, const float attack,
                   const float decay, const float sustain, const float release, const int type, string outputFileName, const float pulseTime) :
            bitDepth(bitDepth), sampleRate(sampleRate), frequency(frequency),duration(duration),volume(volume), attack(attack), decay(decay), sustain(sustain),
            release(release),type(type), outputFileName(outputFileName), pulseTime(pulseTime){};
};

class SoundGenerator::SoundBuilder {
private:
    int bitDepth = 8;
    int sampleRate = 20;
    float frequency = 3;
    float duration = 10;
    float volume = 1;
    float attack = 1;
    float decay = 1;
    float sustain = .5;
    float release = 2;
    float pulseTime = .5;
    int type = 1;
    string outputFileName = " ";

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

    SoundBuilder& setFrequency(const float frequency) {
        this->frequency = frequency;
        return *this;
    };

    SoundBuilder& setDuration(const float duration) {
        this->duration = duration;
        return *this;
    }

    SoundBuilder& setVolume(const float volume) {
        this->volume = volume;
        return *this;
    };

    SoundBuilder& setAttack(const float attack) {
        this->attack = attack;
        return *this;
    };

    SoundBuilder& setDecay(const float decay) {
        this->decay = decay;
        return *this;
    };
    SoundBuilder& setSustain(const float sustain) {
        this->sustain = sustain;
        return *this;
    };
    SoundBuilder& setRelease(const float release) {
        this->release = release;
        return *this;
    };

    SoundBuilder& setPulseTime(const float pulseTime) {
        this->pulseTime = pulseTime;
        return *this;
    }

    SoundBuilder& setType(const int type) {
        this->type = type;
        return *this;
    };
    SoundBuilder& setOutputFile(string outputFileName) {
        this->outputFileName = outputFileName;
        return *this;
    };

    SoundGenerator build() {
        return SoundGenerator(bitDepth,sampleRate,frequency,duration,volume,attack,decay,sustain,release,type,outputFileName, pulseTime);
    };
};

union sndgen_handler {
    float f;
    int i;
};

#endif //CS327PROJECT4_SOUNDGENERATOR_H
