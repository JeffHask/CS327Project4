//
// Created by jeffrey on 11/30/15.
//

#include <math.h>
#include "headers/SoundGenerator.h"

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
//    TODO, how tf does this work?
    int tempAttack;
    int tempSustain;
    int tempDecay;
    int timeLeft = duration;
    if(release >= timeLeft) {
        soundFile = *soundFile * 0;
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
                tempSustain = timeLeft;
            }
        }
    }
}

void SoundGenerator::run(int helpMessage) {
    if(helpMessage) {
//        TODO: print help message
    } else {
        SoundFile *soundFile = setupFile();
        soundFile->writeCS229File(outputFileName);
        handleEnvelop(soundFile);
    }
}

void SoundGenerator::print() {
//todo :NOT NEEDED
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
    int numSamples = duration * sampleRate;
    double maxVal = (pow(2,bitDepth) - 1);
    double period = (frequency * 2 * M_PI) / numSamples;
    int i;
    for(i = 0; i < numSamples; i++) {
        SampleLine *newSample = new SampleLine((int)round(maxVal*sin(period * i)));
        soundFile->addSample(newSample);
    }
}

void SoundGenerator::create_triangle_wave(SoundFile * soundFile) {
    int numSamples = duration * sampleRate;
    double  maxVal = pow(2,bitDepth) - 1;
    double slope = maxVal / (numSamples / (frequency * 4));
    int i;
//    Set first value, as not doing so will screw up the pattern
    soundFile->addSample(new SampleLine((int)maxVal * -1));
    int j = 1;
    int direction = 1;
    for(i = 1; i < numSamples;i++) {
        int sampleValue = (int)round(slope * j) - (int)maxVal;
        SampleLine *sampleLine = new SampleLine(sampleValue);
        soundFile->addSample(sampleLine);
        if(sampleValue == -1 * maxVal || sampleValue == (int)maxVal) {
            direction = (direction == 1) ? 0 : 1;
        }
        (direction) ? j++ : j--;
    }
}

void SoundGenerator::create_sawtooth_wave(SoundFile* soundFile) {
    int numSamples = duration * sampleRate;
    int maxVal = (int)pow(2,bitDepth) - 1;

    double slope = maxVal / (numSamples / frequency);
    int i;
    for(i = 0; i < numSamples; i++) {
        int sampleVal = (int)(slope * (i % ((int)round(numSamples / frequency * 1.0))));
        SampleLine * sampleLine = new SampleLine(sampleVal);
        soundFile->addSample(sampleLine);
    }
}

void SoundGenerator::create_pulse_wave(SoundFile * soundFile) {
    int numSamples = duration * sampleRate;
    int maxVal = (int)pow(2,bitDepth) - 1;
    double interval = round(numSamples / frequency * 1.0);
    int samplesUp = (int)round(interval * pulseTime);
    int i;
    int samplesDown = (int)interval - samplesUp;
    for(i = 0; i < frequency; i++) {
        int j = 0;
        while(j < samplesUp) {
            SampleLine *sampleLine = new SampleLine(maxVal);
            soundFile->addSample(sampleLine);
            j++;
        }
        j = 0;
        while (j < samplesDown) {
            SampleLine *sampleLine = new SampleLine(maxVal * -1);
            soundFile->addSample(sampleLine);
            j++;
        }
    }
}
