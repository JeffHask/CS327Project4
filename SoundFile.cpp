//
// Created by jeffrey on 11/7/15.
//

#include "headers/SoundFile.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

SoundFile::SoundFile() {

}
SoundFile::SoundFile(char *fileName, int wavFile) {
    numberOfChannels = -1;
    bitDepth = -1;
    sampleRate = -1;

        this->fileName = fileName;
    if(!wavFile) {
        fileType = ".cs229";
        readCS299File(fileName);
    } else {
        readWAVFile(fileName);
        fileType = ".WAV";
    }
}

void SoundFile::readCS299File(char *fileName) {
    ifstream input(fileName);
    string line;

    getline(input, line);
    if(line.size() == 5) {
        line[0] = (char)toupper(line[0]);
        line[1] = (char)toupper(line[1]);
        if(line.compare("CS229")) {
//            ERROR
        }
        cout << line << '\n';
    } else {
//        ERROR
    }


    int i;
    int startData = 0;
    int numSamples = 0;
    while(getline( input, line ) ) {
        int keywordVal = -1;
        char keyword[20] = " ";
        if(!startData) {
            if (line[0] == '#') {
//                cout << "Lol thats a comment silly" << endl;

            } else {
                sscanf(line.c_str(), "%s%d", keyword, &keywordVal);
                if(keyword[0] == ' ') {
//                    cout << "Blank line" << endl;
                    continue;
                }
//                cout << keyword << endl;
//                printf("%d\n", keywordVal);
                for(i = 0; i < strlen(keyword); i++) {
                    keyword[i] = (char)toupper(keyword[i]);
                }
                string kw = string(keyword);
                if(kw.compare("STARTDATA")) {
                    if(keywordVal == -1) {
//                        ERROR
                    }
                } else {
                    if(numberOfChannels == -1 || bitDepth == -1 || sampleRate == -1) {
//                        ERROR
                    }
                    startData = 1;
                }
                if(!kw.compare("SAMPLERATE")) {
                    sampleRate = keywordVal;
                } else if (!kw.compare("SAMPLES")) {
                    if(keywordVal < 0) {
//                        ERROR
                    }
                    numberOfSamples = keywordVal;
                } else if (!kw.compare("CHANNELS")) {
                    if(keywordVal > 127) {
//                        ERROR
                    }
                    numberOfChannels = keywordVal;
                } else if (!kw.compare("BITRES")) {
                    if(keywordVal != 8 || keywordVal != 16 || keywordVal != 32) {
//                        ERROR
                    }
                } else {
//                    ERROR
                }
            }
        } else {
                unsigned long p = 0l;
            while((p = line.find(' '), p) != string::npos) {
//                cout << p << endl;
                cout << line.substr(0,p) << endl;
                line = line.substr(p+1);
//                TODO
            }
        }
    }
}

void SoundFile::writeCS229File(char *outputFile) {
//    TODO
}

void SoundFile::readWAVFile(char *fileName) {
//    TODO
}

void SoundFile::writeWAVFile(char *outputFile) {

}