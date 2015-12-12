//
// Created by jeffrey on 11/7/15.
//

#include "headers/SoundFile.h"
#include "headers/Utils.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdexcept>

using namespace std;

SoundFile::SoundFile() {
    numberOfSamples = 0;
}
SoundFile::SoundFile(string fileName) {
    numberOfChannels = -1;
    numberOfSamples = 0;
    bitDepth = -1;
    sampleRate = -1;
    this->fileName = fileName;
    fileType = ".cs229";
    readCS299File(fileName);
}

void SoundFile::readCS299File(string fileName) {
    ifstream* fin = !fileName.compare(" ") ? NULL : new ifstream(fileName.c_str(),ifstream::in) ;
    istream & input = !fileName.compare(" ") ? cin : *fin;
    string line;

    getline(input, line);
    if(line.size() == 5) {
        line[0] = (char)toupper(line[0]);
        line[1] = (char)toupper(line[1]);
        if(line.compare("CS229")) {
            __throw_invalid_argument("Error: No 'CS229' in the first line, invalid cs229 file.");
        }
    } else {
        __throw_invalid_argument("Error: the first line should just have 'CS229', and nothing else.");
    }


    int i;
    int startData = 0;
    int numSamples = -1;
    while(getline( input, line ) ) {
        int keywordVal = -1;
        char keyword[255] = " ";
        if(!startData) {
            if (line[0] == '#') {

            } else {
                sscanf(line.c_str(), "%s%d", keyword, &keywordVal);
                if(keyword[0] == ' ') {
                    continue;
                }
                for(i = 0; i < strlen(keyword); i++) {
                    keyword[i] = (char)toupper(keyword[i]);
                }
                string kw = string(keyword);
                if(kw.compare("STARTDATA")) {
                    if(keywordVal == -1) {
                        __throw_invalid_argument((string("ERROR: Invalid cs229 file, value needed after header ") + kw).c_str());
                    }
                } else {
                    if(numberOfChannels == -1 || bitDepth == -1 || sampleRate == -1) {
                        __throw_invalid_argument("ERROR: Invalid cs229 file, it is missing a neccesary header. Headers that are needed include 'Channels', 'SampleRate', and 'BitRes'.");
                    }
                    startData = 1;
                    continue;
                }
                if(!kw.compare("SAMPLERATE")) {
                    sampleRate = keywordVal;
                } else if (!kw.compare("SAMPLES")) {
                    if(keywordVal < 0) {
                        __throw_invalid_argument("ERROR: The Samples header should not have a negative value.");
                    }
                    numSamples = keywordVal;
                } else if (!kw.compare("CHANNELS")) {
                    if(keywordVal > 127 || keywordVal < 0) {
                        __throw_invalid_argument("ERROR: The Channels header should be exclusively between 0 and 128.");
                    }
                    numberOfChannels = keywordVal;
                } else if (!kw.compare("BITRES")) {
                    if(!(keywordVal == 8 || keywordVal == 16 || keywordVal == 32)) {
                        __throw_invalid_argument("ERROR: The bit depth must be either 8, 16, or 32");
                    } else {
                        bitDepth = keywordVal;
                    }
                } else {
                    __throw_invalid_argument((string("ERROR:Invalid cs229 file, unknown header ") + kw).c_str());
                }
                keywordVal = -1;
            }
        } else {
            try {
                samples.push_back(new SampleLine(line, numberOfChannels, bitDepth));
                numberOfSamples++;
            } catch (invalid_argument &e) {
                string errorLine = " in sample " +to_string(numberOfSamples + 1) + " in file " + fileName;
                __throw_invalid_argument((string(e.what()) + errorLine).c_str());

            }
        }
    }
    if (numSamples != -1 && numSamples != numberOfSamples) {
        __throw_invalid_argument("Mismatch in the number of samples specifed in the file and the actual number of samples");
    }
}

void SoundFile::writeCS229File(string fileName) {
    ofstream* fout = !fileName.compare(" ") ? NULL : new ofstream(fileName.c_str(),ofstream::out) ;
    ostream & out = !fileName.compare(" ") ? cout : *fout;
    out << "CS229" << endl;
    out <<"SampleRate\t" <<sampleRate << endl;
    out <<"Channels\t" << numberOfChannels << endl;
    out << "BitRes\t\t" << bitDepth << endl;
    out <<"StartData" << endl;
    int i;
    for(i=0; i < numberOfSamples; i++) {
        int j;
        for(j = 0; j<numberOfChannels; j++) {
            out << samples[i]->getChannels()[j];
            if(j != numberOfChannels -1) {
                out << " ";
            }
        }
        if(i != numberOfSamples -1) {
            out << endl;
        }
    }
}

void SoundFile::mutate() {
}

void SoundFile::print(string outputFile) {
    writeCS229File(outputFile);
}

void SoundFile::addSample(SampleLine *soundLine) {
    samples.push_back(soundLine);
    numberOfSamples++;
}

float SoundFile::lengthOfSound() {
    return  numberOfSamples / (float)sampleRate;
}

void SoundFile ::operator+=(SoundFile *soundFile) {
    if(soundFile->getSampleRate() != this->getSampleRate() ||
            soundFile->getNumberOfChannels() != this->getNumberOfChannels() ||
            soundFile->getBitDepth() != this->getBitDepth()) {
        __throw_invalid_argument("ERROR: To concatenate cs229 files together, the sample rate, number of channels, and bit depth all need to be the same.");
    }
    int samplesToAdd = soundFile->getNumberOfSamples();
    int i;
    for(i = 0; i < samplesToAdd; i++) {
        samples.push_back(new SampleLine(*soundFile->getSamples()[i]));
        numberOfSamples++;
    }
}

SoundFile *SoundFile::operator+(SoundFile *soundFile) {
    int i;
    for (i = 0; i < soundFile->getNumberOfSamples(); ++i) {
        if(i >= numberOfSamples) {
            samples.push_back(soundFile->getSamples()[i]);
            numberOfSamples++;
        } else {
            *samples[i] += soundFile->getSamples()[i];
        }
    }
    return this;
}

SoundFile *SoundFile::operator*(float multi) {
    int i;
    int j;
    for ( i = 0; i < numberOfSamples; ++i) {
        for ( j = 0; j < numberOfChannels; ++j) {
            samples[i]->setChannel(j,(int)(samples[i]->getChannels()[j] * multi));
        }
    }
    return this;
}

void SoundFile::operator|(SoundFile *soundFile) {
    for (int i = 0; i < numberOfSamples && i < soundFile->getNumberOfSamples(); ++i) {
        samples[i]->addNewChannel(soundFile->getSampleLine(i)->getChannels()[0]);
    }
}