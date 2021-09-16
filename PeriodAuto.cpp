//
// Created by trevo on 9/13/2021.
//
#include "PeriodAuto.h"

void PeriodAuto::S0(const std::string& input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}

