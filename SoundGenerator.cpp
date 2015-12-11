//
// Created by jeffrey on 11/30/15.
//

#include <cmath>
#include "headers/SoundGenerator.h"
#include "headers/Utils.h"

SoundFile *SoundGenerator::setupFile() {
    SoundFile * soundFile = new SoundFile();
    soundFile->setBitDepth(bitDepth);
    soundFile->setSampleRate(sampleRate);
    soundFile->setNumberOfChannels(1);
    if(type == 0 || type == 1) {
        create_sine_wave(soundFile);
    } else if(type == 2) {
        create_triangle_wave(soundFile);
    } else if (type == 3) {
        create_sawtooth_wave(soundFile);
    } else {
        create_pulse_wave(soundFile);
    }
    return soundFile;
}

void SoundGenerator::handleEnvelop(SoundFile *soundFile) {
    float tempAttack = attack;
    float tempSustain = 0;
    float tempDecay = decay;
    float timeLeft = duration;
    if(release >= timeLeft) {
        *soundFile = *(*soundFile * 0);
        return;
    } else {
        timeLeft -=release;
        if(attack >= timeLeft) {
            tempAttack = timeLeft;
            tempDecay = 0;
            tempSustain = 0;
        } else {
            timeLeft -=attack;
            if(decay >= timeLeft) {
                tempDecay = timeLeft;
                tempSustain = 0;
            } else {
                timeLeft -=decay;
                tempSustain = (float)floor(timeLeft);
            }
        }
    }
        double attackSlope = (1.0 * volume / attack) * (1.0 / sampleRate);
        double decaySlope = -1;
        int i;
        for (i = 0; i < sampleRate * tempAttack; i++) {
            SampleLine *sampleLine = soundFile->getSamples()[i];
            int newVal = (int)round(sampleLine->getChannels()[0] * attackSlope * i);
            sampleLine->setChannel(0, newVal);
        }
        double peakSlope = attackSlope * i;
        int j;
        for (j = 1; j < (sampleRate * tempDecay) + 1; j++) {
            decaySlope = (peakSlope) - (j * sustain) / (1.0 * sampleRate * decay);
            SampleLine *sampleLine = soundFile->getSamples()[i];
            int newVal = (int) round(sampleLine->getChannels()[0] * (decaySlope));
            sampleLine->setChannel(0, newVal);
            i++;
        }
        if (decaySlope == -1) {
            decaySlope = sustain;
        }
        int k;
        for (k = 0; k < tempSustain * sampleRate; k++) {
            SampleLine *sampleLine = soundFile->getSamples()[i];
            int newVal = (int) (sampleLine->getChannels()[0] * (decaySlope));
            sampleLine->setChannel(0, newVal);
            i++;
        }
        float l;
        double releaseSlope = decaySlope / (sampleRate * release);
        for (l = release * sampleRate; l > 0; l--) {
            SampleLine *sampleLine = soundFile->getSamples()[i];
            int newVal = (int) (sampleLine->getChannels()[0] * (releaseSlope * l));
            sampleLine->setChannel(0, newVal);

            if(++i == soundFile->getNumberOfSamples()) {
                return;
            };
        }
//    soundFile->writeCS229File(" ");
}

void SoundGenerator::run(int helpMessage) {
    if(helpMessage) {
        cout<<"Sndgen is a program that lets you create different types of waves with a lot of manipulation" <<
              endl << "It uses 4 different types of waves and an adsr envelop to create sound" << endl
        << endl << "Accepted Switches :" << endl;
        h_helperMessage();
        o_helperMessage();
        sndgen_helperMessage();
    } else {
        SoundFile *soundFile = setupFile();
        handleEnvelop(soundFile);
        soundFile->writeCS229File(outputFileName);
    }
}

void SoundGenerator::print() {
    cout << "Bit Rate: " << bitDepth << endl;
    cout << "Sample Rate: " << sampleRate << endl;
    cout <<"Frequency: " << frequency << endl;
    cout << "Duration: " << duration << endl;
    cout << "Peak Volume: " << volume * 100 << endl;
    cout << "Attack Time: " << attack << endl;
    cout << "Decay Time: " << decay << endl;
    cout << "Sustain Time :" << sustain << endl;
    cout << "Release Time :" << release << endl;
    cout << "Type: " << type << endl;
    cout << "Pulse Time: " << pulseTime << endl;

}

void SoundGenerator::create_sine_wave(SoundFile *soundFile) {
    int numSamples = (int)round(duration * sampleRate);
    double maxVal = (pow(2,bitDepth-1) - 1);
    double period = (frequency * 2 * M_PI) / sampleRate;
    int i;
    for(i = 0; i < numSamples; i++) {
        SampleLine *newSample = new SampleLine((int)(maxVal*sin(period * i)));
        soundFile->addSample(newSample);
    }
}

void SoundGenerator::create_triangle_wave(SoundFile * soundFile) {
    int numSamples = (int)round(duration * sampleRate);
    double  maxVal = pow(2,bitDepth) - 1;
    for(int i = 0; i < numSamples;i++) {
        double val8 = maxVal/M_PI*asin(sin(2*i*M_PI/(sampleRate/frequency)));
        int sampleValue = (int)val8;
        SampleLine *sampleLine = new SampleLine(sampleValue);
        soundFile->addSample(sampleLine);
    }
}

void SoundGenerator::create_sawtooth_wave(SoundFile* soundFile) {
    int numSamples = (int)round(duration * sampleRate);
    int maxVal = (int)pow(2,bitDepth) - 1;

    double slope =  (maxVal * frequency) / sampleRate;
    float i;
    for(i = 0; i < numSamples; i++) {
//        int sampleVal = (int)((slope + slope * (i % ((int)(round(sampleRate / frequency * 1.0))))));
        int sampleVal = (int)(maxVal*((i/sampleRate * frequency)-floor(.5+(i/sampleRate * frequency))));
        SampleLine * sampleLine = new SampleLine(sampleVal);
        soundFile->addSample(sampleLine);
    }
}

void SoundGenerator::create_pulse_wave(SoundFile * soundFile) {
    int maxVal = (int)pow(2,bitDepth - 1) - 1;
    int samplesPerPeriod = (int)ceil(sampleRate / frequency);
    int samplesUp = (int)round(sampleRate * pulseTime / frequency);
    int i;
    int samplesDown = samplesPerPeriod - samplesUp;
    for(i = 0; i < frequency * duration; i++) {
        int j = 0;
        while(j < samplesUp) {
            SampleLine *sampleLine = new SampleLine(maxVal);
            soundFile->addSample(sampleLine);
            j++;
        }
        while(j < samplesDown) {
            SampleLine *sampleLine = new SampleLine(maxVal*-1);
            soundFile->addSample(sampleLine);
            j++;
        }
//        double val =  maxVal * (1.0/(sin(2*M_PI*i * frequency /sampleRate )))*abs(sin(2*M_PI * i * frequency / sampleRate));
    }
}
