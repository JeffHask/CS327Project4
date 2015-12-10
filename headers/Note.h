//
// Created by jeffrey on 12/8/15.
//

#ifndef CS327PROJECT4_NOTE_H
#define CS327PROJECT4_NOTE_H


class Note {
private:
    float count;
    int frequency;
public:
    Note(int frequency, float count):frequency(frequency),count(count){};
    Note(){};
    float getCount() const {
        return count;
    }

    void setCount(float count) {
        Note::count = count;
    }

    int getFrequency() const {
        return frequency;
    }

    void setFrequency(int frequency) {
        Note::frequency = frequency;
    }
};


#endif //CS327PROJECT4_NOTE_H
