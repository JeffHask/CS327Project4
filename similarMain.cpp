#include <iostream>
#include "headers/Service.h"
#include "headers/InfoService.h"
#include "headers/ConcatService.h"

#define SNDINFO 1
#define SNDCAT 2
#define SNDMIX 3
#define SNDCVT 4
using namespace std;

void handleCommandArgs(int& pp);
int main(int argc, char*argv[]) {
    int helpSwitch = 0;
    int switches = 1;
    int executableNumber = -1;
    string outputFile = " ";
    string inputFiles[argc - 1];
    int inputFileIndex = 0;
    int writeToWav = 0;
    Service *service;


    string executable = string(argv[0]);
    executable = executable.substr(executable.length()- 6, executable.length()-1);

    if (!executable.compare("sndcat")) {
        executableNumber = SNDCAT;
    } else if (!executable.compare("sndmix")) {
        executableNumber = SNDMIX;
    }  else if (!executable.compare("sndcvt")) {
        executableNumber = SNDCVT;
    } else {
        executableNumber = SNDINFO;
    }
    int i;
    for(i = 1; i < argc; i++) {
        if(switches) {
            if(!string("-h").compare(argv[i])) {
                helpSwitch = 1;
            } else if (!string("-o").compare(argv[i]) && executableNumber != SNDINFO) {
                string oFile = string(argv[i+1]);
                if(!oFile.substr(oFile.length()-6,oFile.length()-1).compare(".cs227")) {
                    outputFile = oFile;
                    i++;
                } else {
//                    ERROR HANDLE
                }
            } else if(!string("-w").compare(argv[i]) && executableNumber == SNDCAT) {
                writeToWav = 1;
            } else if (string(argv[i]).find(string(".cs227")) != string::npos) {
                inputFiles[inputFileIndex] = argv[i];
                inputFileIndex++;
                switches = 0;
            } else {
//                ERROR HANDLE
            }
        }  else {
            if(string(argv[i]).find(string(".cs227")) != string::npos) {
                inputFiles[inputFileIndex] = argv[i];
                inputFileIndex++;
            } else {
//                ERROR HANDLE
            }
        }
    }
    if(executableNumber == SNDINFO) {
        service = new InfoService(helpSwitch);
        service->run();
    } else if (executableNumber == SNDCAT) {
        service = new ConcatService();
    } else if (executableNumber == SNDMIX) {

    } else {

    }

    return 0;
}
