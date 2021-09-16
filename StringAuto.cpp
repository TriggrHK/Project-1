//
// Created by trevo on 9/13/2021.
//
#include "StringAuto.h"

void StringAuto::S0(const std::string& input) {
    if(!input.empty()) {
        if (input[index] == '\'') {
            inputRead = 1;
            index++;
            S1(input.substr(1));
        }
    }
    else {
        Serr();
    }
}
void StringAuto::S1(const std::string& input) {
    if(!input.empty()) {
        if (input[0] == '\'') {
            inputRead++;
            index++;
            S2(input.substr(1));
        } else {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }
    else {
        Serr();
    }
}

void StringAuto::S2(const std::string& input) {
    if(!input.empty()) {
        if (input[0] == '\'') {
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }
    else {
        Serr();
    }
}