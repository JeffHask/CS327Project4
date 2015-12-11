//
// Created by jeffrey on 12/8/15.
//

#ifndef CS327PROJECT4_NOTE_H
#define CS327PROJECT4_NOTE_H

/**
 * Note class. It is used to store information about individual notes for the sndplay program.
 */
class Note {
private:
    /**
     * The count of the note, specified in the .abc229 file
     */
    float count;
    /**
     * The frequency of the note
     */
    int frequency;
public:
    /**
     * Creates a note with a stated frequency and count
     */
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
