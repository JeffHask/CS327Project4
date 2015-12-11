#include <iostream>
#include <stdexcept>
#include "headers/Sound.h"
#include "headers/SoundFile.h"
#include "headers/ReverseDecorator.h"
#include "headers/SampleUpDecorator.h"
#include "headers/EchoDecorator.h"
#include "headers/ShuffleDecorator.h"
#include "headers/SampleDownDecorator.h"
#include "headers/Utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    Sound* soundFile;
    if(string(argv[argc-1]).find(".cs229") != string::npos) {
        soundFile = new SoundFile(string(argv[argc-1]));
    } else {
        cout << "ERROR: invalid last argument. The last argument must be either a .cs229 file" << endl;
        return 0;
    }
//    soundFile->print(" ");
    string outputFile = " ";
    int intVal = 0;
    int i;
    for(i = argc - 2; i > 0 ; i--) {
        if(!string(argv[i]).compare("-h")) {
            cout << "sndfx is a fun little program that you can chain acceptable switches to see what will happen." <<
                    "Valid switches:" <<endl;
            h_helperMessage();
            o_helperMessage();
            cout << "-re: reverse the samples" << endl
            << "-e: creates a kind of 'echo'" << endl
            << "-sh: shuffles the samples around" << endl
            << "-su: up samples all the samples if the bitdepth of the file is 8 or 16. Error if the file's bitdepth is 32"
            << endl << "-sd: down samples all the samples if the bitdeph of the file is 16 or 32. Error if the file's bitdepth is 8";
        } else if(!string(argv[i]).compare("-o")) {
            if (!outputFile.compare(" ")) {
                cout << "ERROR: Please only specify one output file" << endl;
                return 0;
            }
            if (i + 2 != argc && (string(argv[argc - 1]).find(".cs229") != string::npos)) {
                outputFile = string(argv[i + 1]);
                i++;
            } else {
                cout << "ERROR: invalid file after -o, make sure the files is a .cs229 file";
            }
        }else if(!string(argv[i]).compare("-re")) {
            soundFile = new ReverseDecorator(soundFile);
        } else if(!string(argv[i]).compare("-e")) {
            soundFile = new EchoDecorator(soundFile);
        } else if(!string(argv[i]).compare("-sh")) {
            soundFile = new ShuffleDecorator(soundFile);
        } else if(!string(argv[i]).compare("-su")) {
            soundFile = new SampleUpDecorator(soundFile);
        }else if(!string(argv[i]).compare("-sd")) {
            soundFile = new SampleDownDecorator(soundFile);
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