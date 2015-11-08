//
// Created by jeffrey on 11/7/15.
//

#include "headers/InfoService.h"
#include "iostream"

using namespace std;

InfoService ::InfoService() {

}

InfoService ::InfoService(int help) {
    this->help = help;
}

void InfoService::helperMessage() {
    cout << "sndinfo: A program to tell you all about .cs229 files passed in as arguments" << endl << endl <<
            "Legal Switches:" << endl << endl;
    Service::h_helperMessage();
}

void InfoService::printInfo() {
//    TODO
}

void InfoService::run() {
    if(help == 1) {
        helperMessage();
    }
//    TODO
}