#include <iostream>
using namespace std;

#include "headers/SoundGenerator.h"

int main(int argc, char* argv[]) {
    int switchArgs[10];
    fill(switchArgs, switchArgs+10,0);
    int type = 0;
    int helpMessage = 0;
    string outputFileName = " ";
    int i;
//    TODO need to make it so it can receive floats
    for (i = 1; i < argc; i++) {
        if(!string("-h").compare(argv[i])) {
            helpMessage = 1;
            break;
        } else if (!string("-o").compare(argv[i])) {
            string oFile = string(argv[i+1]);
            if(!oFile.substr(oFile.length()-6,oFile.length()-1).compare(".cs229")) {
                outputFileName = oFile;
                i++;
            } else {
//                    ERROR HANDLE
            }
        } else if(!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[0])) {
//                ERROR CHECK
            }
        } else if(!string("--sr").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[1])) {
//                ERROR CHECK
            }
        } else if(!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[2])) {
//                ERROR CHECK
            }
        } else if(!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[3])) {
//                ERROR CHECK
            }
        } else if (!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[4])) {
//                ERROR CHECK
            }
        } else if (!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[5])) {
//                ERROR CHECK
            }
        } else if (!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[6])) {
//                ERROR CHECK
            }
        } else if (!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[7])) {
//                ERROR CHECK
            }
        } else if (!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[8])) {
//                ERROR CHECK
            }
        } else if (!string("--bits").compare(argv[i])) {

        } else if (!string("--bits").compare(argv[i])) {

        } else if (!string("--bits").compare(argv[i])) {

        } else if (!string("--bits").compare(argv[i])) {

        } else if (!string("--bits").compare(argv[i])) {
            if(!sscanf(argv[i],"%d",&switchArgs[9])) {
//                ERROR CHECK
            }
        }


        else {
//                ERROR HANDLE
        }
    }

    SoundGenerator::SoundBuilder builder = SoundGenerator::SoundBuilder().setFrequency(732);
//    cout << "Hello World!" << endl;
    SoundGenerator gen = builder.build();
    gen.print();
    cout << "Hello World!" << endl;
    cout << "Hello World!" << endl;
    cout << "Hello World!" << endl;

}