//
// Created by trevo on 9/13/2021.
//
#include "StringAuto.h"

void StringAuto::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void StringAuto::S1(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
}

void StringAuto::S2(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
}