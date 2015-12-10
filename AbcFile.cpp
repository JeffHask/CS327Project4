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

AbcFile::AbcFile(int help, string outputFile, vector<int> mute, int toWav, string inputFile, int bits,
                 int sampleRate) : help(help), outputfile(outputFile), mute(mute), toWav(toWav), inputFile(inputFile),
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
//    cout << line << endl;
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
//            cout << "Comment/WhiteSpace"  << endl;
            continue;
        }
        if(sscanf(line.c_str(),"%s%f", temp, &keywordVal) == 2) {
            keyword = toUpperCase(string(temp));
//            cout << keyword << endl;
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
//                cout << line << endl;
                if(isspace(line[0])) {
                    getline(input,line);
                    continue;
                }
                int varSet = sscanf(line.c_str(),"%s%f", temp, &keywordVal);
                if(varSet == 2) {
                   keyword = toUpperCase(string(temp));
//                    cout << keyword << endl;
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
//                        ERROR
                    }
                } else if( varSet == 1) {
                    keyword = toUpperCase(string(temp));
                    if(!keyword.compare("WAVEFORM")) {
                        sscanf(line.c_str(),"%s%s",temp, temp2);
                        instrument->setWaveform(toUpperCase(string(temp2)));
                    } else if(!keyword.compare("SCORE")) {
                        getline(input,line);
                        if(line[0] != '[') {
//                            ERROR
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
//    cout <<"bitrate: " << bitRate << endl;
//    cout << "sampleRate: " <<sampleRate << endl;
//    cout <<"waveform: " << instruments[0]->getWaveform() << endl;
//    cout << "Number of notes: " << instruments[0]->getNumberOfNotes() << endl;
//    for(int j = 0; j < instruments.size(); j++) {
//        cout << endl << endl << "Instrument " << j <<  endl;
//        for (int i = 0; i < instruments[j]->getNumberOfNotes(); i++) {
//            cout << "Frequency: " << instruments[j]->getScore()[i]->getFrequency() << endl;
//            cout << "Count: " << instruments[j]->getScore()[i]->getCount() << endl;
//        }
//    }
    SoundFile * soundFile = createSoundFile();
    soundFile->writeCS229File(" ");
}

void AbcFile::writeToWavFile(string outputFile) {

}

SoundFile* AbcFile::createSoundFile() {
    SoundFile * soundFile = new SoundFile();
    SoundFile * otherChannels = new SoundFile();
    soundFile->setBitDepth(bitRate);
    soundFile->setSampleRate(sampleRate);
    soundFile->setNumberOfChannels((int)instruments.size());
    otherChannels->setBitDepth(bitRate);
    otherChannels->setSampleRate(sampleRate);
    otherChannels->setNumberOfChannels((int)instruments.size());
    cout << getMaxSamples(instruments) <<endl;
    int samplesPerCount = (int)ceil(60.0*sampleRate/tempo);
    cout << instruments.size() << endl;
    for(int i = 0; i < instruments.size(); i++) {
        SoundGenerator::SoundBuilder builder;
        builder.setAttack(instruments[i]->getAttack()).setDecay(instruments[i]->getDecay()).setRelease(instruments[i]->getRelease()).setDuration((instruments[i]->findTotalCount() * 60 / tempo)).setSampleRate(sampleRate);
        int numSamples = 0;
        for(int j = 0; j < instruments[i]->getScore().size(); j++) {
            SoundFile * tempFile = new SoundFile();
            tempFile->setBitDepth(bitRate);
            tempFile->setSampleRate(sampleRate);
            SoundGenerator soundGenerator = builder.setDuration((instruments[i]->getScore()[j]->getCount() * 60 / tempo)).build();
            tempFile->setNumberOfChannels((int)instruments.size());
            numSamples +=sineWave(instruments[i]->getScore()[j],samplesPerCount,tempFile,i);
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

int AbcFile::sineWave(Note *note, int numSamplesPerCount, SoundFile * soundFile, int newChannel) {
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

int AbcFile::triangleWave(Note note, int numSamplesPerCount, SoundFile * soundFile) {
    int numSamples = (int)round(numSamplesPerCount * note.getCount());
    double  maxVal = pow(2,bitRate - 1) - 1;
    double slope = maxVal * note.getFrequency() * 4 / numSamples;
    int i;
//    Set first value, as not doing so will screw up the pattern
    soundFile->addSample(new SampleLine((int)maxVal * -1));
    int j = 1;
    int direction = 1;
    for(i = 1; i < numSamples;i++) {
        int sampleValue = (int)round(slope * j) - (int)maxVal;
        SampleLine *sampleLine = new SampleLine(sampleValue);
        soundFile->addSample(sampleLine);
        if(sampleValue <= -1 * maxVal || sampleValue >= (int)maxVal) {
            direction = (direction == 1) ? 0 : 1;
        }
        (direction) ? j++ : j--;
    }

return -1;
}

int AbcFile::pulseWave(Note note, int numSamplesPerCount, SoundFile * soundFile) {
return -1;
}

int AbcFile::sawtoothWave(Note note, int numSamplesPerCount, SoundFile * soundFile) {
return -1;
}

int AbcFile::getMaxSamples(vector<AbcInstrument *> instruments) {
    int max = -1;
    for(int i = 0 ; i < instruments.size(); i++) {
        int instrumentMax = instruments[i]->findTotalCount() * (int)ceil(60.0*sampleRate/tempo);
        max = instrumentMax > max ? instrumentMax : max;
    }
    return max;
}
