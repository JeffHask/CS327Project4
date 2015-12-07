#include <iostream>
#include <bitset>

using namespace std;

#include "headers/SoundGenerator.h"

int main(int argc, char* argv[]) {
    sndgen_handler switchArgs[10];
    int fill;
    for(fill = 0; fill < 10; fill++) {
        switchArgs[fill].i = -1;
    }
    int type = 0;
    int helpMessage = 0;
    string outputFileName = " ";
    int i;
//    TODO: close file pointers
//    TODO check for duplicate switches
//    TODO check bitdepth, negative numbers
//    TODO: how does volume effect the waves? Does it only effect the top, or what?
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
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[0].i)) {
                fprintf(stderr, "No integer value after the --bits switch");
                return 0;
            }
            i++;
        } else if(!string("--sr").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[1].i)) {
                fprintf(stderr, "No integer value after the --sr switch");
                return 0;
            }
            i++;
        } else if(!string("-f").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[2].i)) {
                fprintf(stderr, "No integer value after the -f switch");
                return 0;
            }
            i++;
        } else if(!string("-t").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[3].i)) {
                fprintf(stderr, "No integer value after the -t switch");
                return 0;
            }
            i++;
        } else if (!string("-v").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%f",&switchArgs[4].f)) {
                fprintf(stderr, "No integer value after the -v switch");
                return 0;
            }
            i++;
        } else if (!string("-a").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[5].i)) {
                fprintf(stderr, "No integer value after the -a switch");
                return 0;
            }
            i++;
        } else if (!string("-d").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%d",&switchArgs[6].i)) {
                fprintf(stderr, "No integer value after the -d switch");
                return 0;
            }
            i++;
        } else if (!string("-s").compare(argv[i])) {
            if(i+1 == argc || !sscanf(argv[i + 1],"%f",&switchArgs[7].f)) {
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
            if(i+1 == argc || !sscanf(argv[i + 1],"%f",&switchArgs[9].f)) {
                fprintf(stderr, "No float value after the --pf switch");
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
    if(switchArgs[0].i != -1) {
        builder.setBitDepth(switchArgs[0].i);
    }
    if(switchArgs[1].i != -1) {
        builder.setSampleRate(switchArgs[1].i);
    }
    if(switchArgs[2].i != -1) {
        builder.setFrequency(switchArgs[2].i);
    }
    if(switchArgs[3].i != -1) {
        builder.setDuration(switchArgs[3].i);
    }
    if(switchArgs[4].i != -1) {
        builder.setVolume(switchArgs[4].f);
    }
    if(switchArgs[5].i != -1) {
        builder.setAttack(switchArgs[5].i);
    }
    if(switchArgs[6].i != -1) {
        builder.setDecay(switchArgs[6].i);
    }
    if(switchArgs[7].i != -1) {
        builder.setSustain(switchArgs[7].f);
    }
    if(switchArgs[8].i != -1) {
        builder.setRelease(switchArgs[8].i);
    }
    if(switchArgs[9].i != -1) {
        if(type == 4) {
            builder.setPulseTime(switchArgs[9].f);
        } else {
            fprintf(stderr,"Can't use -p without specifying --pulse");
            return 0;
        }
    }
//    if(outputFileName.compare(" ")) {
//
//    }
    builder.setType(type);
    SoundGenerator gen = builder.build();
    gen.run(helpMessage);
    return 0;
}