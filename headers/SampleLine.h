//
// Created by jeffrey on 11/7/15.
//

#ifndef CS327PROJECT4_SAMPLELINE_H
#define CS327PROJECT4_SAMPLELINE_H

#include <iostream>
#include <vector>

using namespace std;
/**
 * Sample line is a component for the Sound/SoundFile classes that keeps track of a single sample's channels and number
 * of channels.
 */
class SampleLine {
private:
    vector<int> channels;
    int numberOfChannels;
    /**
     * handleSamples() is used to parse through a sample line in a cs229 file, making sure that there are enough
     * channels in the row, and also that all values are between the values for the related bit depth. If the sample
     * is not in the range, it will set it either to the max or min value, depending on what direction it is out of range.
     * It also checks for errors in the sample data, it will throw out invalid argument exceptions if a character besides a
     * number is present, or if the number of channels do not match up with the samplesNeeded parameter.
     */
    void handleSamples(std::string samples, int samplesNeeded, int bitRes);
public:
    SampleLine(){};
    ~SampleLine() {
        channels.clear();
    };
    /**
     * Simple copy constructor. It copies over the values of the samples.
     */
    SampleLine(const SampleLine &copy);
    /**
     * Constructor used with handleSamples.
     */
    SampleLine(std::string, int samplesNeeded, int bitRes);
    /**
     * Constructor that creates a SampleLine with one channel with the value specified.
     */
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
};


#endif //CS327PROJECT4_SAMPLELINE_H
