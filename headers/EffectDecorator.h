//
// Created by jeffrey on 12/5/15.
//

#ifndef CS327PROJECT4_EFFECTDECORATOR_H
#define CS327PROJECT4_EFFECTDECORATOR_H


#include "Sound.h"
#include "SoundFile.h"

class EffectDecorator : public Sound {
protected:
    Sound *soundFile;
public:
    EffectDecorator(Sound *sound);

    virtual void mutate() {
        soundFile->mutate();
    };
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

    virtual SampleLine **getSamples() const;

    virtual void setSamples(SampleLine **Samples);

    virtual int getNumberOfSamples() const;

    virtual void setNumberOfSamples(int numberOfSamples);

    virtual void setFileType(const string &fileType);

    virtual void setFileName(const string &fileName);
//TODO
};


#endif //CS327PROJECT4_EFFECTDECORATOR_H
