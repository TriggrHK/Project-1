//
// Created by trevo on 9/13/2021.
//
#include "Q_MarkAuto.h"

void Q_MarkAuto::S0(const std::string& input) {
    if (input[index] == '?') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}

