//
// Created by trevo on 9/16/2021.
//

#include "UndefinedAuto.h"
void UndefinedAuto::S0(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '\'' /*|| input[0] == '#'*/) {
            S1(input.substr(1));
        }
        inputRead = 1;
    }
}

void UndefinedAuto::S1(const std::string& input) {
    if (!input.empty()) {
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
}

void UndefinedAuto::S2(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '\'' || input[0] == '\n') {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S1(input.substr(1));
        } else {
            Serr();
        }
    }
}
