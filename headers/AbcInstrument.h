//
// Created by jeffrey on 12/8/15.
//

#ifndef CS327PROJECT4_ABCINSTRUMENT_H
#define CS327PROJECT4_ABCINSTRUMENT_H

#include <vector>
#include <string>
#include "Note.h"

using namespace std;
/**
 * Class used in as a data store for the AbcFile class. A new one is created everytime there is an instrument section in
 * an abc229 file.
 */
class AbcInstrument {
private:
    int waveform;
    float volume;
    float attack;
    float decay;
    float release;
    float sustain;
    /**
     * A vector of all the notes contained. They are stored with their frequency and count
     */
    vector<Note *> score;
    float handleScores(string note, double & freq, int hasSharp);
public:
    AbcInstrument(){};
    void addScore(string note);
    int findTotalCount();
    int getWaveform() const {
        return waveform;
    }

    void setWaveform(string waveform) {
        int c;
        if(!waveform.compare("SINE")) {
            c = 1;
        } else if (!waveform.compare("SAWTOOTH")) {
            c = 2;
        } else if (!waveform.compare("TRIANGLE")) {
            c = 3;
        } else if (!waveform.compare("PULSE")) {
            c = 4;
        } else {
            __throw_invalid_argument("Unkown wave type");
        }
        AbcInstrument::waveform = c;
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
