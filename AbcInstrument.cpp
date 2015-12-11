//
// Created by jeffrey on 12/8/15.
//

#include <cmath>
#include <iostream>
#include "headers/AbcInstrument.h"


void AbcInstrument::addScore(string note) {
    double val = 0;
    long length = note.length();
    double s = pow(2, 1.0/12);
    float count = 1;
    if((note[0] == 'z' || note[0] == 'Z') || (note[0] >= 'a' && note[0] <= 'g') || (note[0] >= 'A' && note[0] <= 'G' )) {

        if(note[0] == 'a') {
            val = 440;
            count = handleScores(note,val,1);
        } else if(note[0] == 'b') {
            val = 440 * pow(s,2);
            count = handleScores(note,val,0);
        } else if (note[0] == 'c') {
            val = 440 * pow(s,-9);
            count = handleScores(note,val,1);
        } else if (note[0] == 'd') {
            val = 440 * pow(s,-7);
            count = handleScores(note,val,1);
        } else if (note[0] == 'e') {
            val = 440 * pow(s,-5);
            count = handleScores(note,val,0);
        } else if (note[0] == 'f') {
            val = 440 * pow(s,-4);
            count = handleScores(note,val,1);
        } else if (note[0] == 'g') {
            val = 440 * pow(s,-2);
            count = handleScores(note,val,1);
        } else if (note[0] == 'z') {
            val = 0;
            count = handleScores(note,val,1);
        } else if (note[0] == 'A') {
            val = 220;
            count = handleScores(note,val,1);
        } else if (note[0] == 'B') {
            val = 220 * pow(s,2);
            count = handleScores(note,val,1);
        } else if (note[0] == 'C') {
            val = 220 * pow(s,-9);
            count = handleScores(note,val,1);
        } else if (note[0] == 'D') {
            val = 220 * pow(s,-7);
            count = handleScores(note,val,1);
        } else if (note[0] == 'E') {
            val = 220 * pow(s,-5);
            count = handleScores(note,val,1);
        } else if (note[0] == 'F') {
            val = 220 * pow(s,-4);
            count = handleScores(note,val,1);
        } else if (note[0] == 'G') {
            val = 220 * pow(s,-2);
            count = handleScores(note,val,1);
        } else if (note[0] == 'Z') {
            val = 0;
            count = handleScores(note,val,1);
        }
        else {
            __throw_invalid_argument("Invalid character in score");
        }
        cout << val << endl;
        score.push_back(new Note((int)val,count));
    } else {
        __throw_invalid_argument("Invalid score");
    }
}

float AbcInstrument::handleScores(string note, double & freq, int hasSharp) {
    double s = pow(2, 1.0/12);
    float d = 1;
    float n = 1;
    if(note.length() == 1) return 1;

    int i = 1;
    while(note.length() != i) {
        if(note[i] == '#') {
            if(hasSharp && i == 1) {
                freq = freq * s;
            } else {
                __throw_invalid_argument("Error: Illegal use of sharp. Please place it right after a note in which the sharp is valid");
            }
        } else if (note[i] == ',') {
            freq = freq * .5;
        } else if (note[i] == '\'') {
            freq = freq * 2;
        } else if (isdigit(note[i])) {
            n = note[i] - '0';
            if(note.length()-1 != i && isdigit(note[i+1])) {
                n = 10 * n + note[i+1] - '0';
                i++;
            }
            if(n > 16 || n < 1) {
                __throw_invalid_argument("ERROR: count numerator is invalid. Please select value between 1 and 16");
            }
            if(i == note.length() -1) {
                return n;
            } else {
                if(note[i+1] == '/' && i+1 != note.length() - 1) {
                    if(note[i+2] == '1') {
                        if(i+2 != note.length() - 1) {
                            d = 1;

                            if (note.length() -1 == i+3 && note[i+3] == '6') {
                                d = 16;
                                return n/d;
                            } else {
                                __throw_invalid_argument("ERROR: invalid count muliplyer. Valid denominator values are 1, 2, 4, 8, or 16.");
                            }
                        }else {
                           __throw_invalid_argument("ERROR: invalid setup of count. Nothing after the '/'");
                        }
                    } else if((note[i+2] == '2' || note[i+2] == '4' || note[i+2] == '8') && i+2 == note.length()-1) {
                        d = note[i+2] - '0';
                        return n/d;
                    } else {
                        __throw_invalid_argument("ERROR: invalid count muliplyer. Valid denominator values are 1, 2, 4, 8, or 16.");
                    }
                } else {
                    __throw_invalid_argument("ERROR: invalid count muliplyer. Valid denominator values are 1, 2, 4, 8, or 16.");

                }
            }
        } else {
            __throw_invalid_argument("ERROR: invalid count muliplyer. Valid denominator values are 1, 2, 4, 8, or 16.");
        }
        i++;
    }
    return n / d;
}

int AbcInstrument::findTotalCount() {
    int count = 0;
    for(int i = 0; i < score.size(); i++) {
        count += score[i]->getCount();
    }
        return count;
}