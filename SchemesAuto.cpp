//
// Created by trevo on 9/13/2021.
//
#include "SchemesAuto.h"

void SchemesAuto::S0(const std::string& input) {
    if (input[index] == 'S') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void SchemesAuto::S1(const std::string& input) {
    if (input[index] == 'C') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void SchemesAuto::S2(const std::string& input) {
    if (input[index] == 'H') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void SchemesAuto::S3(const std::string& input) {
    if (input[index] == 'E') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void SchemesAuto::S4(const std::string& input) {
    if (input[index] == 'M') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}
void SchemesAuto::S5(const std::string& input) {
    if (input[index] == 'E') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}
void SchemesAuto::S6(const std::string& input) {
    if (input[index] == 'S') {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}

