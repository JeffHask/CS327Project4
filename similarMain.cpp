#include <iostream>
#include "headers/Service.h"
#include "headers/InfoService.h"
#include "headers/ConcatService.h"
#include "headers/MixService.h"
#include "headers/Utils.h"

using namespace std;

int main(int argc, char*argv[]) {
    int multiOrSwitchArgs[20];
    int switches[20];
    int executableNumber;
    string outputFile = " ";
    char** inputFiles = (char**)malloc(sizeof(char**));
    int numberOfFiles = 0;
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
    int j = handleSwitches(argv,argc,switches,executableNumber,outputFile);
    if(j == 0 && executableNumber != SNDGEN) {
//        ERROR
    }
    numberOfFiles = handleCommandArgs(inputFiles,argv,j,argc);
//    int i;
//    for(i = 1; i < argc; i++) {
//        if(switches) {
//            if(!string("-h").compare(argv[i])) {
//                helpSwitch = 1;
//            } else if (!string("-o").compare(argv[i]) && executableNumber != SNDINFO) {
//                string oFile = string(argv[i+1]);
//                if(!oFile.substr(oFile.length()-6,oFile.length()-1).compare(".cs229")) {
//                    outputFile = oFile;
//                    i++;
//                } else {
////                    ERROR HANDLE
//                }
//            } else if(!string("-w").compare(argv[i]) && executableNumber == SNDCAT) {
//                writeToWav = 1;
//            } else if (string(argv[i]).find(string(".cs229")) != string::npos) {
//                inputFiles[inputFileIndex] = argv[i];
//                inputFileIndex++;
//                switchOn = 0;
//            } else {
////                ERROR HANDLE
//            }
//        }  else {
//            if(string(argv[i]).find(string(".cs229")) != string::npos) {
//                inputFiles[inputFileIndex] = argv[i];
//                inputFileIndex++;
//            } else {
////                ERROR HANDLE
//            }
//        }
//    }
    if(executableNumber == SNDINFO) {
        service = new InfoService(switches, inputFiles, numberOfFiles);
    } else if (executableNumber == SNDCAT) {
        service = new ConcatService(switches, inputFiles, numberOfFiles, outputFile);
    } else if (executableNumber == SNDMIX) {
        service = new MixService(switches,inputFiles,numberOfFiles,outputFile, multiOrSwitchArgs);
    } else {

    }
    service->run();
    return 0;
}
