//
// Created by jeffrey on 11/11/15.
//

#include "headers/Utils.h"

int handleCommandArgs(string ** inputFiles, char *args[], int index , int numArgs, int executable) {
    int i;
    int inputIndex = 0;
    for (i = index; i < numArgs; ++i) {
        if (string(args[i]).find(string(".cs229")) != string::npos || executable == SNDCVT && string(args[i]).find(string(".wav")) != string::npos) {
            inputFiles[inputIndex] = new string(args[i]);
            inputIndex++;
        } else {
            __throw_invalid_argument((std::string("ERROR: Unknown argument '") + std::string(args[i]) + std::string("'")).c_str());
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
                if(i+1 < numArgs || (string(args[i + 1]).find(string(".cs229")) != string::npos || string(args[i + 1]).find(string(".wav")) != string::npos )) {
                    outputFile = args[i+1];
                    i++;
                } else {
                    __throw_invalid_argument((std::string("ERROR: Invalid output file '") + std::string(args[i + 1]) + std::string("'")).c_str());
                }
            } else if(!string("-w").compare(args[i]) && executable == SNDCAT) {
                switches[1] = 1;
            } else if ((string(args[i]).find(string(".cs229")) != string::npos || (SNDMIX == executable && sscanf(args[i],"%d", &mixCheck) == 1)) && executable != SNDCVT) {
                return i;
            } else if(executable == SNDCVT && (string(args[i]).find(string(".cs229")) != string::npos || string(args[i]).find(string(".wav")) != string::npos)) {
                return i;
            }
            else {
                __throw_invalid_argument((std::string("ERROR: Unknown argument '") + std::string(args[i]) + std::string("'")).c_str());
            }
    }
    return 0;
}

int handleSndmixCommandArgs(string**inputFiles, char *args[], int index , int numArgs, int multiples[]) {
    int numFiles = 0;
    int i;
    if((numArgs - index) % 2 != 0) {
        __throw_invalid_argument("Invalid number of arguments, make sure you have an integer value followed by a string");
    }
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
            __throw_invalid_argument("Invalid arguments, make sure you have an integer value followed by a string");
        }
    }
    return numFiles;

}

int littleEndianInt(int value) {
    uint x = (uint)value;
    int valueShifted =
            ( x << 24) |                // Move 4th byte to 1st
            ((x << 8) & 0x00ff0000) |  // Move 2nd byte to 3rd
            ((x >> 8) & 0x0000ff00) |  // Move 3rd byte to 2nd
            ( x >> 24);                 // Move 4th byte to 1st
    return valueShifted;
}

void h_helperMessage() {
    cout << "-h\t: show the help screen" << endl;
}

void o_helperMessage() {
    cout << "-o file\t: specify the output file name; if omitted, write to standard output" << endl;
}

void w_helperMessage() {
    cout << "-w\t: output in .wav format instead of .cs229";
}