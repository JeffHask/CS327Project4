//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SAMPLELINE_H
#define CS327PROJECT4_SAMPLELINE_H


class SampleLine {
private:
    int samples[];
    int numberOfSamples;
    void handleSamples(char* samples);
public:
    SampleLine();
    SampleLine(char* samples);
    int* getSamples() {
        return samples;
    };
    int getNumberOfSamples() {
        return numberOfSamples;
    };
};


#endif //CS327PROJECT4_SAMPLELINE_H
