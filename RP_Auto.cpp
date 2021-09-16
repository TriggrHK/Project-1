//
// Created by trevo on 9/13/2021.
//
#include "RP_Auto.h"

void RP_Auto::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}

