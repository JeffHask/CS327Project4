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
    int tempAttack = attack;
    int tempSustain = 0;
    int tempDecay = decay;
    int timeLeft = duration;
    if(release >= timeLeft) {
        *soundFile = *(*soundFile * 0);
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
    double attackSlope = (1.0*volume / attack) * (1.0 / sampleRate);
    double decaySlope = -1;
    int i;
    for(i = 0; i < sampleRate * tempAttack; i++) {
        SampleLine * sampleLine= soundFile->getSamples()[i];
        int newVal = (int)(sampleLine->getChannels()[0] * attackSlope * i);
        sampleLine->setChannel(0,newVal);
    }
    int j;
    for(j = 1; j < sampleRate * tempDecay + 1; j++) {
        decaySlope = (volume) - (j*sustain)/( 1.0 *sampleRate * decay);
        SampleLine * sampleLine= soundFile->getSamples()[i];
        int newVal = (int)(sampleLine->getChannels()[0] * (decaySlope));
        sampleLine->setChannel(0,newVal);
        i++;
    }
    if(decaySlope == -1) {
        decaySlope = sustain;
    }
    int k;
    for(k = 0; k < tempSustain * sampleRate; k++) {
        SampleLine * sampleLine= soundFile->getSamples()[i];
        int newVal = (int)(sampleLine->getChannels()[0] * (decaySlope));
        sampleLine->setChannel(0,newVal);
        i++;
    }
    double l;
    double releaseSlope = decaySlope / (sampleRate * release);
    for(l = release * sampleRate; l > 0; l--) {
        SampleLine * sampleLine= soundFile->getSamples()[i];
        int newVal = (int)(sampleLine->getChannels()[0] * (releaseSlope * l) );
        sampleLine->setChannel(0,newVal);
        i++;
    }
    soundFile->writeCS229File(" ");
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
    double maxVal = (pow(2,bitDepth-1) - 1);
    double period = (frequency * 2 * M_PI) / sampleRate;
    int i;
    for(i = 0; i < numSamples; i++) {
//        TODO: remove test code
        SampleLine *newSample = new SampleLine((int)(maxVal*sin(period * i)));
//        SampleLine *newSample = new SampleLine(100);

        soundFile->addSample(newSample);
    }
}

void SoundGenerator::create_triangle_wave(SoundFile * soundFile) {
    int numSamples = duration * sampleRate;
    double  maxVal = pow(2,bitDepth - 1) - 1;
    double slope = maxVal * frequency * 4 / numSamples;
    int i;
//    Set first value, as not doing so will screw up the pattern
    soundFile->addSample(new SampleLine((int)maxVal * -1));
    int j = 1;
    int direction = 1;
    for(i = 1; i < numSamples;i++) {
        int sampleValue = (int)round(slope * j) - (int)maxVal;
        SampleLine *sampleLine = new SampleLine(sampleValue);
        soundFile->addSample(sampleLine);
        if(sampleValue <= -1 * maxVal || sampleValue >= (int)maxVal) {
            direction = (direction == 1) ? 0 : 1;
        }
        (direction) ? j++ : j--;
    }
}

//TODO: slope
void SoundGenerator::create_sawtooth_wave(SoundFile* soundFile) {
    int numSamples = duration * sampleRate;
    int maxVal = (int)pow(2,bitDepth) - 1;

    double slope =  (maxVal * frequency) / sampleRate;
    int i;
    for(i = 0; i < numSamples; i++) {
        int sampleVal = (int)((slope + slope * (i % ((int)(round(sampleRate / frequency * 1.0))))));
        SampleLine * sampleLine = new SampleLine(sampleVal - (int)(((maxVal)*.5)));
        soundFile->addSample(sampleLine);
    }
}

void SoundGenerator::create_pulse_wave(SoundFile * soundFile) {
    int numSamples = duration * sampleRate;
    int maxVal = (int)pow(2,bitDepth - 1) - 1;
    double interval = round(numSamples / duration  / frequency * 1.0);
    int samplesUp = (int)round(interval * pulseTime);
    int i;
    int samplesDown = (int)interval - samplesUp;
    for(i = 0; i < frequency * duration; i++) {
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
