#include <iostream>
using namespace std;

#include "headers/SoundGenerator.h"

int main(int argc, char* argv[]) {
    int switchArgs[10];
    fill(switchArgs, switchArgs+10,-1);
    int type = 0;
    int helpMessage = 0;
    string outputFileName = " ";
    int i;
//    TODO need to make it so it can receive floats
//    TODO check for duplicate switches
//    TODO check bitdepth, negative numbers
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
                fprintf(stderr, "Invalid value for outputfile. Make sure it ends with .cs229");
                return 0;
            }
        } else if(!string("--bits").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[0])) {
                fprintf(stderr, "No integer value after the --bits switch");
                return 0;
            }
            i++;
        } else if(!string("--sr").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[1])) {
                fprintf(stderr, "No integer value after the --sr switch");
                return 0;
            }
            i++;
        } else if(!string("-f").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[2])) {
                fprintf(stderr, "No integer value after the -f switch");
                return 0;
            }
            i++;
        } else if(!string("-t").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[3])) {
                fprintf(stderr, "No integer value after the -t switch");
                return 0;
            }
            i++;
        } else if (!string("-v").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[4])) {
                fprintf(stderr, "No integer value after the -v switch");
                return 0;
            }
            i++;
        } else if (!string("-a").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[5])) {
                fprintf(stderr, "No integer value after the -a switch");
                return 0;
            }
            i++;
        } else if (!string("-d").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[6])) {
                fprintf(stderr, "No integer value after the -d switch");
                return 0;
            }
            i++;
        } else if (!string("-s").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[7])) {
                fprintf(stderr, "No integer value after the -s switch");
                return 0;
            }
            i++;
        } else if (!string("-r").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[8])) {
                fprintf(stderr, "No integer value after the -r switch");
                return 0;
            }
            i++;
        } else if (!string("--sine").compare(argv[i])) {
            if(type != 0) {
                fprintf(stderr, "Only select one type of wave");
                return 0;
            } else {
                type = 1;
            }
        } else if (!string("--triangle").compare(argv[i])) {
            if(type != 0) {
                fprintf(stderr, "Only select one type of wave");
                return 0;
            } else {
                type = 2;
            }
        } else if (!string("--sawtooth").compare(argv[i])) {
            if(type != 0) {
                fprintf(stderr, "Only select one type of wave");
                return 0;
            } else {
                type = 3;
            }
        } else if (!string("--pulse").compare(argv[i])) {
            if(type != 0) {
                fprintf(stderr, "Only select one type of wave");
                return 0;
            } else {
                type = 4;
            }
        } else if (!string("--pf").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[9])) {
                fprintf(stderr, "No integer value after the --pf switch");
                return 0;
            }
            i++;
        }


        else {
            fprintf(stderr,"Unknown argument '%s'",argv[i]);
            return 0;
        }
    }
    SoundGenerator::SoundBuilder builder = SoundGenerator::SoundBuilder();
    if(switchArgs[0] != -1) {
        builder.setBitDepth(switchArgs[0]);
    }
    if(switchArgs[1] != -1) {
        builder.setSampleRate(switchArgs[1]);
    }
    if(switchArgs[2] != -1) {
        builder.setFrequency(switchArgs[2]);
    }
    if(switchArgs[3] != -1) {
        builder.setDuration(switchArgs[3]);
    }
    if(switchArgs[4] != -1) {
        builder.setVolume(switchArgs[4]);
    }
    if(switchArgs[5] != -1) {
        builder.setAttack(switchArgs[5]);
    }
    if(switchArgs[6] != -1) {
        builder.setDecay(switchArgs[6]);
    }
    if(switchArgs[7] != -1) {
        builder.setSustain(switchArgs[7]);
    }
    if(switchArgs[8] != -1) {
        builder.setRelease(switchArgs[8]);
    }
    if(switchArgs[9] != -1) {
        if(type == 4) {
            builder.setPulseTime(switchArgs[9]);
        } else {
            fprintf(stderr,"Can't use -p without specifying --pulse");
            return 0;
        }
    }
    if(outputFileName.compare(" ")) {
       FILE * file = fopen(outputFileName.c_str(),"w");
        builder.setOutputFile(file);
    }
    SoundGenerator gen = builder.build();
    gen.print();
    cout << "Hello World!" << endl;
    cout << "Hello World!" << endl;
    cout << "Hello World!" << endl;
    return 0;
}