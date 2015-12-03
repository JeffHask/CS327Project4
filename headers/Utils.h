//
// Created by jeffrey on 11/11/15.
//

#ifndef CS327PROJECT4_UTILS_CPP_H
#define CS327PROJECT4_UTILS_CPP_H

#define SNDINFO 1
#define SNDCAT 2
#define SNDMIX 3
#define SNDGEN 4
#define SNDCVT 5
#define SNDFX 6
#define SNDPLAY 7

#include <iostream>
using namespace std;

int handleCommandArgs(string** inputfiles, char*args[], int index, int numArgs, int executable);
int handleSndmixCommandArgs(string** inputFiles, char *args[], int index , int numArgs, int multiples[]);

int handleSwitches(char* args[], int numArgs, int switches[], int executable, string &outputFile);

void h_helpermessage();
void h_helperMessage();
void o_helperMessage();
void w_helperMessage();
#endif //CS327PROJECT4_UTILS_CPP_H
