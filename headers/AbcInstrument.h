//
// Created by jeffrey on 12/8/15.
//

#ifndef CS327PROJECT4_ABCINSTRUMENT_H
#define CS327PROJECT4_ABCINSTRUMENT_H

#include <vector>
#include <string>
#include "Note.h"

using namespace std;

class AbcInstrument {
private:
    string waveform;
    float volume;
    float attack;
    float decay;
    float release;
    float sustain;
    vector<Note *> score;
    float handleScores(string note, double & freq, int hasSharp);
public:
    AbcInstrument(){};
    void addScore(string note);
    int findTotalCount();
    string getWaveform() const {
        return waveform;
    }

    void setWaveform(string waveform) {
        if(!waveform.compare("SINE")) {
            waveform = 1;
        } else if (!waveform.compare("SAWTOOTH")) {
            waveform = 2;
        } else if (!waveform.compare("TRIANGLE")) {
            waveform = 3;
        } else if (!waveform.compare("PULSE")) {
            waveform = 4;
        } else {
            __throw_invalid_argument("Unkown wave type");
        }
        AbcInstrument::waveform = waveform;
    }

    float getVolume() const {
        return volume;
    }

    void setVolume(float volume) {
        AbcInstrument::volume = volume;
    }

    float getAttack() const {
        return attack;
    }

    void setAttack(float attack) {
        AbcInstrument::attack = attack;
    }

    float getDecay() const {
        return decay;
    }

    void setDecay(float decay) {
        AbcInstrument::decay = decay;
    }

    float getRelease() const {
        return release;
    }

    void setRelease(float release) {
        AbcInstrument::release = release;
    }


    float getSustain() const {
        return sustain;
    }

    void setSustain(float sustain) {
        AbcInstrument::sustain = sustain;
    }


    const vector<Note *> &getScore() const {
        return score;
    }

    void setScore(const vector<Note *> &score) {
        AbcInstrument::score = score;
    }

    const int getNumberOfNotes() {
        return (int)score.size();
    }
};


#endif //CS327PROJECT4_ABCINSTRUMENT_H
