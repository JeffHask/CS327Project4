//
// Created by jeffrey on 11/7/15.
//

#include "headers/SoundFile.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdexcept>

using namespace std;

SoundFile::SoundFile() {
    maxSamples = 2;
    samples = new SampleLine*[maxSamples];
}
SoundFile::SoundFile(string fileName, int wavFile) {
    numberOfChannels = -1;
    numberOfSamples = 0;
    maxSamples = 20;
    bitDepth = -1;
    sampleRate = -1;
    samples = new SampleLine*[maxSamples];
        this->fileName = fileName;
    if(!wavFile) {
        fileType = ".cs229";
        readCS299File(fileName);
    } else {
        readWAVFile(fileName);
        fileType = ".WAV";
    }
}

void SoundFile::readCS299File(string fileName) {
    ifstream input(fileName);
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
    int lineScan;
    int numSamples = -1;
    while(getline( input, line ) ) {
        int keywordVal = -1;
        char keyword[20] = " ";
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
                addSample(new SampleLine(line, numberOfChannels, bitDepth));
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

void SoundFile::writeCS229File(FILE* file) {
    fprintf(file, "CS229\n");
    fprintf(file,"Samples\t\t%d\n", numberOfSamples);
    fprintf(file,"SampleRate\t%d\n", sampleRate);
    fprintf(file,"Channels\t%d\n", numberOfChannels);
    fprintf(file,"BitRes\t\t%d\n", bitDepth);
    fprintf(file,"StartData\n");
    int i;
    for(i=0; i < numberOfSamples; i++) {
        int j;
        for(j = 0; j<numberOfChannels; j++) {
            fprintf(file,"%d\t", samples[i]->getChannels()[j]);
        }
        fprintf(file,"\n");
    }
}

void SoundFile::readWAVFile(string fileName) {
//    TODO
}

void SoundFile::writeWAVFile(FILE* file) {

}

void SoundFile::addSample(SampleLine *soundLine) {
    if(numberOfSamples == maxSamples) {
        SampleLine** pSampleLine = new SampleLine*[maxSamples * 2];
        maxSamples = maxSamples * 2;
        int i;
        for(i = 0; i < numberOfSamples; i++) {
            pSampleLine[i] = new SampleLine(*samples[i]);
        }
        delete[] samples;
        samples = pSampleLine;
    }
    samples[numberOfSamples] = soundLine;
    numberOfSamples++;
}

float SoundFile::lengthOfSound() {
    return  numberOfSamples / (float)sampleRate;
}

void SoundFile::operator+=(SoundFile *soundFile) {
    if(soundFile->getSampleRate() != this->getSampleRate() ||
            soundFile->getNumberOfChannels() != this->getNumberOfChannels() ||
            soundFile->getBitDepth() != this->getBitDepth()) {
        __throw_invalid_argument("ERROR: To concatenate cs229 files together, the sample rate, number of channels, and bit depth all need to be the same.");
    }
    int samplesToAdd = soundFile->getNumberOfSamples();
    int i;
    for(i = 0; i < samplesToAdd; i++) {
        this->addSample(new SampleLine(*soundFile->getSamples()[i]));
    }
}

SoundFile *SoundFile::operator+(SoundFile *soundFile) {
    int i;
    for (i = 0; i < soundFile->getNumberOfSamples(); ++i) {
        if(i >= numberOfSamples) {
            addSample(soundFile->getSamples()[i]);
        } else {
            *samples[i] += soundFile->getSamples()[i];
        }
    }
    return this;
}

SoundFile *SoundFile::operator*(int multi) {
    int i;
    int j;
    for ( i = 0; i < numberOfSamples; ++i) {
        for ( j = 0; j < numberOfChannels; ++j) {
            samples[i]->setChannel(j,samples[i]->getChannels()[j] * multi);
        }
    }
    return this;
}