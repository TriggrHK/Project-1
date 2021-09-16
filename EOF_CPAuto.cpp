//
// Created by trevo on 9/13/2021.
//
#include "EOF_CPAuto.h"
void EOF_CPAuto::S0(const std::string& input) {
    if (input[index] == ' ') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
