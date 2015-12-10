//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_EFFECTDECORATOR_H
#define CS327PROJECT4_EFFECTDECORATOR_H


#include "Sound.h"
#include "SoundFile.h"

/**
 * Abstract Decorator for sndfx.
 */
class EffectDecorator : public Sound {
protected:
    /**
     * The sound file that it being manipulated
     */
    Sound *soundFile;
public:
    /**
     * The Constructor for this abstract class. It sets the soundFile variable to what is passed
     */
    EffectDecorator(Sound *sound);

    /**
     * Not much cool happening here, as the soundFile's mutate is empty
     */
    virtual void mutate() {
        soundFile->mutate();
    };
    /**
     * It prints the file manipulated to the desired output file
     */
    virtual void print(string outputFile);
    virtual ~EffectDecorator() {
        delete  soundFile;
    };

    virtual void setSampleLine(int index, SampleLine *sampleLine);

    virtual string getFileName() const;

    virtual void setFileName(char *fileName);

    virtual string getFileType() const;

    virtual int getSampleRate() const;

    virtual void setSampleRate(int sampleRate);

    virtual int getBitDepth() const;

    virtual void setBitDepth(int bitDepth);

    virtual int getNumberOfChannels() const;

    virtual void setNumberOfChannels(int numberOfChannels);

    virtual vector<SampleLine*> getSamples() const;

    virtual void setSamples(vector<SampleLine*> samples);

    virtual int getNumberOfSamples() const;

    virtual void setNumberOfSamples(int numberOfSamples);

    virtual void setFileType(const string &fileType);

    virtual void setFileName(const string &fileName);
};


#endif //CS327PROJECT4_EFFECTDECORATOR_H
