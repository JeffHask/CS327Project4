//
// Created by jeffrey on 12/8/15.
//

#include <fstream>
#include <stdexcept>
#include "algorithm"
#include <cmath>
#include "headers/AbcFile.h"
#include "headers/Utils.h"
#include "headers/SoundGenerator.h"

AbcFile::AbcFile(int help, string outputFile, vector<int> mute, string inputFile, int bits,
                 int sampleRate) : help(help), outputfile(outputFile), mute(mute), inputFile(inputFile),
                    bitRate(bits), sampleRate(sampleRate) {
    readAbcFile(inputFile);
}

void AbcFile::readAbcFile(string inputFile) {
    ifstream input(inputFile);
    string line;
    char temp[20];
    char temp2[20];
    string keyword;
    float keywordVal;
    getline(input, line);
    if(line.length() == 6) {
        line[0] = (char)toupper(line[0]);
        line[1] = (char)toupper(line[1]);
        line[2] = (char)toupper(line[2]);
        if(line.compare("ABC229")) {
            input.close();
           __throw_invalid_argument("ERROR: Invalid .abc229 file, the first line should just have 'ABC229' in it.");
        }
    } else {
        input.close();
        __throw_invalid_argument("ERROR: Invalid .abc229 file, the first line should just have 'ABC229' in it.");
    }
    while(getline(input,line)) {
        if(line[0] == '%' || isspace(line[0]) || !line.compare("")) {
            continue;
        }
        if(sscanf(line.c_str(),"%s%f", temp, &keywordVal) == 2) {
            keyword = toUpperCase(string(temp));
        } else {
            __throw_invalid_argument("Invalid .abc229 file, in the headers section, make sure everything is keyword, then value");
        }
        if(!keyword.compare("TEMPO")) {
            tempo = (int)keywordVal;
        } else if(!keyword.compare("INSTRUMENT")) {
            AbcInstrument *instrument = new AbcInstrument();
            getline(input,line);
            int notDone = 1;
            while (notDone && !input.eof()) {
                if(isspace(line[0])) {
                    getline(input,line);
                    continue;
                }
                int varSet = sscanf(line.c_str(),"%s%f", temp, &keywordVal);
                if(varSet == 2) {
                   keyword = toUpperCase(string(temp));
                    if(!keyword.compare("VOLUME")) {
                        instrument->setVolume(keywordVal);
                    } else if (!keyword.compare("ATTACK")) {
                        instrument->setAttack(keywordVal);
                    } else if (!keyword.compare("DECAY")) {
                        instrument->setDecay(keywordVal);
                    } else if (!keyword.compare("SUSTAIN")) {
                        instrument->setSustain(keywordVal);
                    } else if (!keyword.compare("RELEASE")) {
                        instrument->setRelease(keywordVal);
                    } else {
                        __throw_invalid_argument(string(string("Invalid header: ") + keyword + string(" is not a valid header")).c_str());
                    }
                } else if( varSet == 1) {
                    keyword = toUpperCase(string(temp));
                    if(!keyword.compare("WAVEFORM")) {
                        sscanf(line.c_str(),"%s%s",temp, temp2);
                        instrument->setWaveform(toUpperCase(string(temp2)));
                    } else if(!keyword.compare("SCORE")) {
                        getline(input,line);
                        if(line[0] != '[') {
                            __throw_invalid_argument("ERROR: line after the keyword 'Score' must start with the '[' character ");
                        }
                        string  note = "";
                        while(notDone) {
                            char c;
                            input.get(c);
                            if(c == ']') {
                                if(note.size() != 0) {
                                    instrument->addScore(note);
                                }
                                instruments.push_back(instrument);
                                notDone = 0;
                            }
                             else if(((c >= 'A' && c <= 'G') ||(c <= 'g' && c >= 'a')) || (c == 'z' || c == 'Z')) {
                                try {
                                    if(note.compare("")) {
                                        instrument->addScore(note);
                                        note.clear();
                                    }
                                        note.push_back(c);
                                } catch (invalid_argument & e) {
                                    __throw_invalid_argument(e.what());
                                }
                            }
                            else if(c != '|' && !isspace(c) && c != '\n' && c !='\r') {
                                if(note.size() == 0) {
                                    __throw_invalid_argument("Error in Score");
                                }
                                note.push_back(c);
                            }
                        }
                    }
                }
                getline(input,line);
            }
        }
    }
}

void AbcFile::writeToCs229File(string outputFile) {
    SoundFile * soundFile = createSoundFile();
    soundFile->writeCS229File(outputFile);
}

SoundFile* AbcFile::createSoundFile() {
    SoundFile * soundFile = new SoundFile();
    soundFile->setBitDepth(bitRate);
    soundFile->setSampleRate(sampleRate);
    soundFile->setNumberOfChannels((int)instruments.size());
    int samplesPerCount = (int)ceil(60.0*sampleRate/tempo);
    for(int i = 0; i < instruments.size(); i++) {
        SoundFile * otherChannels = new SoundFile();
        otherChannels->setBitDepth(bitRate);
        otherChannels->setSampleRate(sampleRate);
        otherChannels->setNumberOfChannels((int)instruments.size());
        SoundGenerator::SoundBuilder builder;
        builder.setAttack(instruments[i]->getAttack()).setDecay(instruments[i]->getDecay()).setRelease(instruments[i]->getRelease()).setDuration((instruments[i]->findTotalCount() * 60 / tempo)).setSampleRate(sampleRate).setSustain(instruments[i]->getSustain());
        int numSamples = 0;
        for(int j = 0; j < instruments[i]->getScore().size(); j++) {
            SoundFile * tempFile = new SoundFile();
            tempFile->setBitDepth(bitRate);
            tempFile->setSampleRate(sampleRate);
            SoundGenerator soundGenerator = builder.setDuration((instruments[i]->getScore()[j]->getCount() * 60 / tempo)).setBitDepth(bitRate).build();
            tempFile->setNumberOfChannels((int)instruments.size());
            int waveForm = instruments[i]->getWaveform();
            if(waveForm == 1) {
                numSamples +=sineWave(instruments[i]->getScore()[j],samplesPerCount,tempFile);
            } else if(waveForm == 2) {
                numSamples +=sawtoothWave(instruments[i]->getScore()[j],samplesPerCount,tempFile);
            } else if (waveForm == 3) {
                numSamples +=triangleWave(instruments[i]->getScore()[j],samplesPerCount,tempFile);
            } else {
                numSamples +=pulseWave(instruments[i]->getScore()[j],samplesPerCount,tempFile);
            }
            soundGenerator.handleEnvelop(tempFile);
            if(i == 0) {
                *soundFile += tempFile;
            } else {
                *otherChannels += tempFile;
            }
        }
        for (int k = numSamples + 1; k < getMaxSamples(instruments); ++k) {
            SampleLine *sampleLine = new SampleLine();
            sampleLine->addNewChannel(0);
            if(i == 0) {
                soundFile->addSample(sampleLine);
            } else {
               otherChannels->addSample(sampleLine);
            }
        }
        if(std::find(mute.begin(),mute.end(),i) != mute.end()) {
            if(i == 0) {
                *soundFile * 0;
            } else {
                *otherChannels * 0;
            }
        }
        if(i != 0) {
            *soundFile | otherChannels;
        }
    }

    return soundFile;
}

int AbcFile::sineWave(Note *note, int numSamplesPerCount, SoundFile * soundFile) {
    int numSamples = (int)ceil(numSamplesPerCount * note->getCount());
    double maxVal = (pow(2,bitRate-1) - 1);
    double period = (note->getFrequency() * 2 * M_PI) / sampleRate;
    int i;
    for(i = 0; i < numSamples; i++) {
            SampleLine *newSample = new SampleLine((int) (maxVal * sin(period * i)));
            soundFile->addSample(newSample);
    }
    return numSamples;
}

int AbcFile::triangleWave(Note *note, int numSamplesPerCount, SoundFile * soundFile) {
    int numSamples = (int)ceil(numSamplesPerCount * note->getCount());
    double  maxVal = pow(2,bitRate) - 1;
    for(int i = 0; i < numSamples;i++) {
        double val8 = maxVal/M_PI*asin(sin(note->getFrequency()*2.0*i*M_PI/sampleRate));
        int sampleValue = (int)val8;
        SampleLine *sampleLine = new SampleLine(sampleValue);
        soundFile->addSample(sampleLine);
    }

return numSamples;
}

int AbcFile::pulseWave(Note *note, int numSamplesPerCount, SoundFile * soundFile) {
    int maxVal = (int)pow(2,bitRate - 1) - 1;
    int samplesPerPeriod = (int)ceil(sampleRate / note->getFrequency());
    int samplesUp = (int)round(sampleRate * 0.5 / note->getFrequency());
    int i;
    int numSamples = 0;
    int samplesDown = samplesPerPeriod - samplesUp;
    for(i = 0; i < note->getFrequency() * note->getCount(); i++) {
        int j = 0;
        while (j < samplesUp) {
            SampleLine *sampleLine = new SampleLine(maxVal);
            soundFile->addSample(sampleLine);
            j++;
            numSamples++;
        }
        while (j < samplesPerPeriod) {
            SampleLine *sampleLine = new SampleLine(maxVal * -1);
            soundFile->addSample(sampleLine);
            j++;
            numSamples++;
        }
    }
    return numSamples;
}

int AbcFile::sawtoothWave(Note *note, int numSamplesPerCount, SoundFile * soundFile) {
    int numSamples = (int)ceil(note->getCount()* numSamplesPerCount);
    int maxVal = (int)pow(2,bitRate) - 1;
    float i;
    for(i = 0; i < numSamples; i++) {
        int sampleVal = (int)(maxVal*((i/sampleRate * note->getFrequency())-floor(.5+(i/sampleRate * note->getFrequency()))));
        SampleLine * sampleLine = new SampleLine(sampleVal);
        soundFile->addSample(sampleLine);
    }
return (int)i;
}

int AbcFile::getMaxSamples(vector<AbcInstrument *> instruments) {
    int max = -1;
    for(int i = 0 ; i < instruments.size(); i++) {
        int instrumentMax = instruments[i]->findTotalCount() * (int)ceil(60.0*sampleRate/tempo);
        max = instrumentMax > max ? instrumentMax : max;
    }
    return max;
}
