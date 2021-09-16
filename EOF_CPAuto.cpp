//
// Created by trevo on 9/13/2021.
//
#include "EOF_CPAuto.h"
void EOF_CPAuto::S0(const std::string& input) {
    if (input[index] == 'E') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void EOF_CPAuto::S1(const std::string& input) {
    if (input[index] == 'O') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void EOF_CPAuto::S2(const std::string& input) {
    if (input[index] == 'F') {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}
