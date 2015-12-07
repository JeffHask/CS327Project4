#include <iostream>
#include <stdexcept>
#include "headers/Sound.h"
#include "headers/SoundFile.h"
#include "headers/ReverseDecorator.h"
#include "headers/SampleUpDecorator.h"
#include "headers/EchoDecorator.h"
#include "headers/ShuffleDecorator.h"
#include "headers/ChannelDecorator.h"
#include "headers/SampleDownDecorator.h"

using namespace std;

int main(int argc, char* argv[]) {
    Sound* soundFile;
    int writeToWav;
    if(string(argv[argc-1]).find(".cs229") != string::npos) {
        soundFile = new SoundFile(string(argv[argc-1]), 0);
    } else if (string(argv[argc-1]).find(".wav") != string::npos) {
        soundFile = new SoundFile(string(argv[argc-1]),1);
    } else {
        cout << "ERROR: invalid last argument. The last argument must be either a .cs229 file or .wav file" << endl;
        return 0;
    }
//    soundFile->print(" ");
    string outputFile = " ";
    int intVal = 0;
    int i;
    for(i = argc - 2; i > 0 ; i--) {
        if(!string(argv[i]).compare("-h")) {
//            TODO
        } else if(!string(argv[i]).compare("-o")) {
            if(!outputFile.compare(" ")) {
                cout << "ERROR: Please only specify one output file" << endl;
                return 0;
            }
            if(i + 2 != argc && (string(argv[argc-1]).find(".cs229") != string::npos || string(argv[argc-1]).find(".wav") != string::npos) ) {
                outputFile = string(argv[i+1]);
                i++;
            } else {
                cout << "ERROR: invalid file after -o, make sure the files is either a .cs229 or .wav file";
            }
        } else if(!string(argv[i]).compare("-w")) {
            if(writeToWav) {
                fprintf(stderr,"ERROR: duplicate -w switches");
                return 0;
            }
            writeToWav = 1;
        } else if(!string(argv[i]).compare("-re")) {
            soundFile = new ReverseDecorator(soundFile);
        } else if(!string(argv[i]).compare("-e")) {
            soundFile = new EchoDecorator(soundFile);
        } else if(!string(argv[i]).compare("-sh")) {
            soundFile = new ShuffleDecorator(soundFile);
        } else if(!string(argv[i]).compare("-su")) {
            soundFile = new SampleUpDecorator(soundFile);
        }else if(!string(argv[i]).compare("-sd")) {
            soundFile = new SampleDownDecorator(soundFile);
        }
        else if(!string(argv[i]).compare("-ch")) {
            if(i + 2 != argc && sscanf(argv[i+1],"%d",&intVal)) {
                soundFile = new ChannelDecorator(soundFile, intVal);
            } else {
                fprintf(stderr, "ERROR: no integer value after --ch");
            }
        } else {
            cout << "ERROR: unknown argument '"<< argv[i] << "'" << endl;
            return 0;
        }
    }
    try {
        soundFile->mutate();
        soundFile->print(outputFile);
    } catch (invalid_argument & e) {
        fprintf(stderr, e.what());
    }

}