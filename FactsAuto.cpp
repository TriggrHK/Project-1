//
// Created by trevo on 9/15/2021.
//

#include "FactsAuto.h"

void FactsAuto::S0(const std::string& input) {
    if (input[index] == 'F') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void FactsAuto::S1(const std::string& input) {
    if (input[index] == 'a') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void FactsAuto::S2(const std::string& input) {
    if (input[index] == 'c') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void FactsAuto::S3(const std::string& input) {
    if (input[index] == 't') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void FactsAuto::S4(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}