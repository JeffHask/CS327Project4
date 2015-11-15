//
// Created by jeffrey on 11/11/15.
//

#include "headers/Utils.h"

int handleCommandArgs(char ** &inputFiles, char *args[], int index , int numArgs) {
    int i;
    int inputIndex = 0;
    for (i = index; i < numArgs; ++i) {
        if(string(args[i]).find(string(".cs229")) != string::npos) {
            inputFiles[inputIndex] = args[i];
            inputIndex++;
        } else {
//                ERROR HANDLE
        }
    }
    return inputIndex;
}

int handleSwitches(char* args[],int numArgs, int switches[], int executable, string &outputFile) {


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
            } else if (string(args[i]).find(string(".cs229")) != string::npos) {
                return i;
            } else {
//                ERROR HANDLE
            }
    }
    return 0;
}
