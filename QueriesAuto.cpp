//
// Created by trevo on 9/13/2021.
//
#include "QueriesAuto.h"

void QueriesAuto::S0(const std::string& input) {
    if (input[index] == 'Q') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void QueriesAuto::S1(const std::string& input) {
    if (input[index] == 'u') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}
void QueriesAuto::S2(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}
void QueriesAuto::S3(const std::string& input) {
    if (input[index] == 'r') {
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}
void QueriesAuto::S4(const std::string& input) {
    if (input[index] == 'i') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}
void QueriesAuto::S5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}
void QueriesAuto::S6(const std::string& input) {
    if (input[index] == 's') {
        inputRead++;
        index++;
    }
    else {
        Serr();
    }
}
