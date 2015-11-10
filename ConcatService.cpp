//
// Created by jeffrey on 11/7/15.
//
#include <iostream>
#include "headers/ConcatService.h"


using namespace std;

ConcatService::ConcatService(int helpSwitch, int toWav, char **soundFiles, char *outputFileName) {
    this->helpMessage = helpSwitch;
    this->toWav = toWav;
    this->soundFiles = soundFiles;
    this->outputFileName = outputFileName;
}

ConcatService::ConcatService() {

}

void ConcatService ::helperMessage() {
    cout << "sndcat: A program that allows you to conatenate .cs227 files together" << endl
    << endl << "Valid switches:" << endl << endl;
    h_helperMessage();
    o_helperMessage();
    w_helperMessage();
}

void ConcatService::run() {
    if(helpMessage) {
        helperMessage();
    } else {
//        TODO
    }
}