//
// Created by jeffrey on 11/7/15.
//
#include <iostream>
#include <vector>
#include "headers/AbcFile.h"
#include "headers/Utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    int helpMessage = 0;
    string outputFileName = " ";
    int bitDepth = 8;
    int sampleRate = 10;
    int instrumentNum = 0;
    int type = 0;
    std::vector<int> mute;
    int i;
    string inputFile = " ";
    if(string(argv[argc-1]).find(".abc229") != string::npos) {
        inputFile = string(argv[argc-1]);
    } else {
        cerr << "Missing .abc229 file at the end of the arguments";
        return 0;
    }
    for (i = 1; i < argc - 1; i++) {
        if(!string("-h").compare(argv[i])) {
                cout << "sndplay: a program that accepts .abc229 files and outputs them to .cs229 files" <<
                        endl << "Acceptable switches:" << endl;
            h_helperMessage();
            o_helperMessage();
            cout << "--bits n: use a bit depth n, defaults to 8" << endl << "--sr n: set sampleRate to n. Default is 10"
            << endl << "--mute n: do not play instrument n. Can call this switch multiple times";
            return 0;
        } else if (!string("-o").compare(argv[i])) {
            string oFile = string(argv[i+1]);
            if(!oFile.substr(oFile.length()-6,oFile.length()-1).compare(".cs229")) {
                outputFileName = oFile;
                i++;
            } else {
                fprintf(stderr, "Invalid value for outputfile. Make sure it ends with .cs229");
                return 0;
            }
        } else if(!string("--bits").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&bitDepth)) {
                fprintf(stderr, "No integer value after the --bits switch");
                return 0;
            }
            i++;
        } else if(!string("--sr").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&sampleRate)) {
                fprintf(stderr, "No integer value after the --sr switch");
                return 0;
            }
            i++;
        } else if(!string("--mute").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d", &instrumentNum)) {
                fprintf(stderr, "No integer value after the -f switch");
                return 0;
            } else {
                mute.push_back(instrumentNum);
            }
            i++;
        } else {
            fprintf(stderr,"Unknown argument '%s'",argv[i]);
            return 0;
        }
    }
    AbcFile* file = new AbcFile(helpMessage,outputFileName,mute,inputFile,bitDepth,sampleRate);
    file->writeToCs229File(outputFileName);
}