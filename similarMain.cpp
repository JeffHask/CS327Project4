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
    string** inputFiles = (string**)malloc(sizeof(string*) * 500);
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
    if(executableNumber == SNDMIX) {
        numberOfFiles = handleSndmixCommandArgs(inputFiles,argv,j,argc,multiOrSwitchArgs);
    } else {
//        numberOfFiles = handleCommandArgs(inputFiles, argv, j, argc, executableNumber);
    }
    if(executableNumber == SNDINFO) {
//        service = new InfoService(switches, inputFiles, numberOfFiles);
    } else if (executableNumber == SNDCAT) {
//        service = new ConcatService(switches, inputFiles, numberOfFiles, outputFile);
    } else if (executableNumber == SNDMIX) {
        service = new MixService(switches,inputFiles,numberOfFiles,outputFile, multiOrSwitchArgs);
    } else {

    }
    service->run();
    return 0;
}
