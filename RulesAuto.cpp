//
// Created by trevo on 9/13/2021.
//
#include "RulesAuto.h"

void RulesAuto::S0(const std::string& input) {
    if (input[index] == 'R') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void RulesAuto::S1(const std::string& input) {
    if (input[index] == 'U') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void RulesAuto::S2(const std::string& input) {
    if (input[index] == 'L') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void RulesAuto::S3(const std::string& input) {
    if (input[index] == 'E') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void RulesAuto::S4(const std::string& input) {
    if (input[index] == 'S') {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}

