//
// Created by jeffrey on 11/30/15.
//

#ifndef CS327PROJECT4_SOUNDGENERATOR_H
#define CS327PROJECT4_SOUNDGENERATOR_H

#include "iostream"
#include "SoundFile.h"
/**
 * SoundGenerator is a class used for sndgen. The idea for this class was to try some different design pattern, so I went with
 * the builder pattern. It actually worked nicely, as I could used it seamlessly with sndplay, atleast the handleEnvelop()
 * function.
 */
class SoundGenerator {
public:
    class SoundBuilder;
    /**
     * Function not used for anything too cool, just something to check everything was getting set. Not sure why I don't
     * just delete it, maybe someday.
     */
    void print();
    /**
     * Kept the same function name as the other 3 main programs for some reason. It handles everything about this class,
     * calling helper methods. Also just prints out the helpermessage if the -h switch is present.
     */
    void run(int helpMessage);
    /**
     * Method to handle applying the envelop to the soundfile. Made public to be able to use with sndplay.
     */
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
    /**
     * Creates a sine wave
     */
    void create_sine_wave(SoundFile* soundFile);
    /**
     * Creates a triangle wave
     */
    void create_triangle_wave(SoundFile * soundFile);
    /**
     * Creates a sawtooth wave
     */
    void create_sawtooth_wave(SoundFile * soundFile);
    /**
     * Creates a pulse wave
     */
    void create_pulse_wave(SoundFile * soundFile);

    /**
     * Giant constructor, but everything has default values and it is private, so nothing to worry about. The class is created
     * with the help of the SoundBuilder inner class
     */
    SoundGenerator(const int bitDepth, const int sampleRate, const float frequency, const float duration, const float volume, const float attack,
                   const float decay, const float sustain, const float release, const int type, string outputFileName, const float pulseTime) :
            bitDepth(bitDepth), sampleRate(sampleRate), frequency(frequency),duration(duration),volume(volume), attack(attack), decay(decay), sustain(sustain),
            release(release),type(type), outputFileName(outputFileName), pulseTime(pulseTime){};
};

/**
 * This is the builder for sound generator. It was many default values, and all of its setters are made public, so this
 * is how to cut back on the giant constructor if someone might need to only set a few values.
 */
class SoundGenerator::SoundBuilder {
private:
    int bitDepth = 8;
    int sampleRate = 20;
    float frequency = 5;
    float duration = 10;
    float volume = 1;
    float attack = 0;
    float decay = 0;
    float sustain = 1;
    float release = 0;
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

/**
 * A cool union that I wanted to use cause I finally found a reason to use them. Some parameters will be ints and some floats,
 * and I wanted to have one storage for both, so I made this cute little union.
 */
union sndgen_handler {
    float f;
    int i;
};

#endif //CS327PROJECT4_SOUNDGENERATOR_H
