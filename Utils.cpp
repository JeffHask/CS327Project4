//
// Created by jeffrey on 11/11/15.
//

#include "headers/Utils.h"

int handleCommandArgs(string ** inputFiles, char *args[], int index , int numArgs, int executable) {
    int i;
    int inputIndex = 0;
    for (i = index; i < numArgs; ++i) {
        if (executable == SNDMIX) {

        } else {
            if (string(args[i]).find(string(".cs229")) != string::npos) {
                inputFiles[inputIndex] = new string(args[i]);
                inputIndex++;
            } else {
//                ERROR HANDLE
            }
        }
    }
    return inputIndex;
}

int handleSwitches(char* args[],int numArgs, int switches[], int executable, string &outputFile) {

    int mixCheck;
    int i;
    for(i = 1; i < numArgs; i++) {
            if(!string("-h").compare(args[i])) {
                switches[0] = 1;
            } else if (!string("-o").compare(args[i]) && executable != SNDINFO) {
                string oFile = string(args[i+1]);
                if(!oFile.substr(oFile.length()-6,oFile.length()-1).compare(".cs229")) {
                    outputFile = oFile;
                    i++;
                } else {
//                    ERROR HANDLE
                }
            } else if(!string("-w").compare(args[i]) && executable == SNDCAT) {
                switches[1] = 1;
            } else if (string(args[i]).find(string(".cs229")) != string::npos || (SNDMIX == executable && sscanf(args[i],"%d", &mixCheck) == 1)) {
                return i;
            } else {
//                ERROR HANDLE
            }
    }
    return 0;
}

int handleSndmixCommandArgs(string**inputFiles, char *args[], int index , int numArgs, int multiples[]) {
    int numFiles = 0;
    int i;
    for (i = index; i < numArgs - 1; i+=2) {
        int numberSet;
        int val;
        char fileName[20];

        numberSet = sscanf(args[i], "%d", &val) + sscanf(args[i+1], "%s", fileName);

        if(numberSet == 2) {
            multiples[numFiles] = val;
            inputFiles[numFiles] = (new string(fileName));
            numFiles++;
        } else {
//            ERROR
        }
    }
    return numFiles;

}
