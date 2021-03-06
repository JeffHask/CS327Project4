//
// Created by jeffrey on 11/11/15.
//

#include <vector>
#include "headers/Utils.h"

int handleCommandArgs(vector<string*> & inputFiles, char *args[], int index , int numArgs, int executable) {
    int i;
    int inputIndex = 0;
    for (i = index; i < numArgs; ++i) {
        if (string(args[i]).find(string(".cs229")) != string::npos) {
            inputFiles.push_back(new string(args[i]));
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
                if(i+1 < numArgs || (string(args[i + 1]).find(string(".cs229")) != string::npos )) {
                    outputFile = args[i+1];
                    i++;
                } else {
                    __throw_invalid_argument((std::string("ERROR: Invalid output file '") + std::string(args[i + 1]) + std::string("'")).c_str());
                }
            } else if ((string(args[i]).find(string(".cs229")) != string::npos || (SNDMIX == executable && sscanf(args[i],"%d", &mixCheck) == 1))) {
                return i;
            } else if((string(args[i]).find(string(".cs229")) != string::npos)) {
                return i;
            }
            else {
                __throw_invalid_argument((std::string("ERROR: Unknown argument '") + std::string(args[i]) + std::string("'")).c_str());
            }
    }
    return 0;
}

int handleSndmixCommandArgs(vector<string*> & inputFiles, char *args[], int index , int numArgs, vector<float> & multiples) {
    int numFiles = 0;
    int i;
    if((numArgs - index) % 2 != 0) {
        __throw_invalid_argument("Invalid number of arguments, make sure you have an integer value followed by a string");
    }
    for (i = index; i < numArgs - 1; i+=2) {
        int numberSet;
        float val;
        char fileName[20];

        numberSet = sscanf(args[i], "%f", &val) + sscanf(args[i+1], "%s", fileName);

        if(numberSet == 2) {
            multiples.push_back(val);
            inputFiles.push_back(new string(fileName));
            numFiles++;
        } else {
            __throw_invalid_argument("Invalid arguments, make sure you have an integer value followed by a string");
        }
    }
    return numFiles;

}

string toUpperCase(string keyword) {
    int i;
    for(i = 0; i < keyword.length(); i++) {
        keyword[i] = (char)toupper(keyword[i]);
    }
    return keyword;
}

void h_helperMessage() {
    cout << "-h\t: Show the help screen" << endl;
}

void o_helperMessage() {
    cout << "-o file\t: Specify the output file name; if omitted, write to standard output" << endl;
}

void w_helperMessage() {
    cout << "-w\t: write the output in .wav format instead of .cs229" << endl;
}
void sndgen_helperMessage() {
    cout  << "--bits n\t : use a bit depth of n. Defaults is 8" << endl;
    cout  << "--sr n\t: use a sample rate of n. Defaults to 4" << endl;
    cout  << "-f r\t: use a frequency of r Hz. Defaults to 5" << endl;
    cout  << "-t r\t: total duration of r seconds, defaults to 10" << endl;
    cout  << "-v p\t: peak volume, between 0 and 1. Defaults to 1" << endl;
    cout  << "-a r\t: release time of r seconds, defaults to 0" << endl;
    cout  << "-d r\t: decay time of r seconds, defaults to 0" << endl;
    cout  << "-s p\t: sustain volume, between 0 and 1. defaults to 1" << endl;
    cout  << "-r r\t: release time of r seconds, defaults to 0" << endl;
    cout << endl << "Wave types: If no wave type is specified, it defaults to sine wave. "
    << "Only one type of wave is allowed at a time." << endl;
    cout  << "--sine\t: generate a sine wave. This is default value if no type of wave is specified" << endl;
    cout  << "--triangle\t: generate a triangle wave" << endl;
    cout  << "--sawtooth\t: generate a sawtooth wave" << endl;
    cout  << "--pulse\t: generate a pulse wave" << endl;
    cout  << "--pf p\t: percentage of time the pulse wave is 'up', defaults to .5" << endl;

}