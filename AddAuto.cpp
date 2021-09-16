//
// Created by trevo on 9/15/2021.
//

#include "AddAuto.h"

void AddAuto::S0(const std::string& input) {
    if (input[index] == '+') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
