//
// Created by jeffrey on 11/11/15.
//

#ifndef CS327PROJECT4_UTILS_CPP_H
#define CS327PROJECT4_UTILS_CPP_H

#define SNDINFO 1
#define SNDCAT 2
#define SNDMIX 3

#include <iostream>
using namespace std;

/**
 * This handles all the input files for sndinfo and sndcat, making sure they are all .cs229 files
 */
int handleCommandArgs(vector<string*> &inputFiles, char*args[], int index, int numArgs, int executable);
/**
 * This is a specialized command args handler, as sndmix also has float values that are passed in with a file name.
 */
int handleSndmixCommandArgs(vector<string*> & inputFiles, char *args[], int index , int numArgs, vector<float>& multiples);
/**
 * This handles switches for  sndinfo, sndmix, and sndcat.
 */
int handleSwitches(char* args[], int numArgs, int switches[], int executable, string &outputFile);

/**
 * Simple little function to set return an uppercased string.
 */
string toUpperCase(string keyword);
/**
 * Help message for the -h switch
 */
void h_helperMessage();
/**
 * Help message for the -o switch
 */
void o_helperMessage();
/**
 * Help message for the -w switch
 */
void w_helperMessage();
/**
 * Prints out all the switches for sndgen
 */
void sndgen_helperMessage();
#endif //CS327PROJECT4_UTILS_CPP_H
