#include <iostream>
#include <stdexcept>
#include "headers/Service.h"
#include "headers/InfoService.h"
#include "headers/ConcatService.h"
#include "headers/MixService.h"
#include "headers/Utils.h"
using namespace std;

int main(int argc, char*argv[]) {
    try {
        vector<float> multiValues;
        int switches[20];
        fill(switches, switches + 20, 0);
        int executableNumber;
        string outputFile = " ";
        vector<string*> inputFiles;
        int numberOfFiles = 0;
        Service *service;


        string executable = string(argv[0]);
        executable = executable.substr(executable.length() - 6, executable.length() - 1);

        if (!executable.compare("sndcat")) {
            executableNumber = SNDCAT;
        } else if (!executable.compare("sndmix")) {
            executableNumber = SNDMIX;
        } else {
            executableNumber = SNDINFO;
        }
        int j;
        j = handleSwitches(argv, argc, switches, executableNumber, outputFile);
        if(j == 0 && executableNumber == SNDINFO) {
            inputFiles.push_back(new string("STDIN"));
            numberOfFiles = -1;
        }
        else if(!switches[0]) {
            if (executableNumber == SNDMIX) {
                numberOfFiles = handleSndmixCommandArgs(inputFiles, argv, j, argc, multiValues);
            } else {
                numberOfFiles = handleCommandArgs(inputFiles, argv, j, argc, executableNumber);
            }
        }
        if (executableNumber == SNDINFO) {
            service = new InfoService(switches, inputFiles, numberOfFiles);
        } else if (executableNumber == SNDCAT) {
            service = new ConcatService(switches, inputFiles, numberOfFiles, outputFile);
        } else {
            service = new MixService(switches, inputFiles, numberOfFiles, outputFile, multiValues);
        }
        service->run();
        return 0;
    } catch (invalid_argument &e) {
        fprintf(stderr, e.what());
        return 0;
    }
}
