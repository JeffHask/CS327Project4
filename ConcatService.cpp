//
// Created by jeffrey on 11/7/15.
//

#include "headers/ConcatService.h"

ConcatService::ConcatService(int helpSwitch, int toWav, char **soundFiles, char *outputFileName) {
    this->helpMessage = helpSwitch;
    this->toWav = toWav;
    this->soundFiles = soundFiles;
    this->outputFileName = outputFileName;
}

ConcatService::ConcatService() {

}

void ConcatService ::helperMessage() {
}