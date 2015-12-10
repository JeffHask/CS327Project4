//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SAMPLELINE_H
#define CS327PROJECT4_SAMPLELINE_H
//TODO documentation


#include <iostream>
#include <vector>

using namespace std;

class SampleLine {
private:
    vector<int> channels;
    int numberOfChannels;
    void handleSamples(std::string samples, int samplesNeeded, int bitRes);
public:
    SampleLine(){};
    ~SampleLine() {
        channels.clear();
    };
    SampleLine(const SampleLine &copy);
    SampleLine(std::string, int samplesNeeded, int bitRes);
    SampleLine(int val);
    const vector<int> getChannels() {
        return channels;
    };
    int getNumberOfChannels() {
        return numberOfChannels;
    };
    void setChannel(int index, int value) {
        channels[index] = value;
    };
    void setNumberOfChannels(int channels){
        numberOfChannels = channels;
    }
    void addNewChannel(int val) {
        channels.push_back(val);
        numberOfChannels++;
    }
    void operator +=(SampleLine *sampleLine);

//    void operator = (SampleLine * sampleLine);
};


#endif //CS327PROJECT4_SAMPLELINE_H
