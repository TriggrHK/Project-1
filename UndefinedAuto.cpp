//
// Created by trevo on 9/16/2021.
//

#include "UndefinedAuto.h"
void UndefinedAuto::S0(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '\'') {
            inputRead++;
            index++;
            S1(input.substr(1));
        }
        else if (input[0] == '#'){
            inputRead++;
            index++;
            S3(input.substr(1));
        }
        else {
            inputRead = 1;
        }
    }
}

void UndefinedAuto::S1(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '\'') {
            inputRead++;
            index++;
            S2(input.substr(1));
        }
        else {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S1(input.substr(1));
        }
    }
}

void UndefinedAuto::S2(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '\'') {
            inputRead++;
            index++;
            S1(input.substr(1));
        }
        else {
            Serr();
        }
    }
}

void UndefinedAuto::S3(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '|') {
            inputRead++;
            index++;
            S4(input.substr(1));
        }
    }
}

void UndefinedAuto::S4(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '|') {
            inputRead++;
            index++;
            S5(input.substr(1));
        } else {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S4(input.substr(1));
        }
    }
}

void UndefinedAuto::S5(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '#') {
            Serr();
        } else if (input[0] == '|') {
            inputRead++;
            index++;
            S5(input.substr(1));
        } else {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S4(input.substr(1));
        }
    }
}