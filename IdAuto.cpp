//
// Created by trevo on 9/13/2021.
//
#include "IdAuto.h"

void IdAuto::S0(const std::string& input) {
    if (isalpha(input[index])) { //need a value of some sort
        inputRead = 1;
        index = 1;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAuto::S1(const std::string& input) {
    if (isalpha(input[index]) || isalnum(input[index])){
        inputRead++;
        index++;
        S1(input);
    }
}
