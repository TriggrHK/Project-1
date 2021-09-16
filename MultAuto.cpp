//
// Created by trevo on 9/15/2021.
//

#include "MultAuto.h"
void MultAuto::S0(const std::string& input) {
    if (input[index] == '*') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}
