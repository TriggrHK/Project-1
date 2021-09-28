//
// Created by trevo on 9/15/2021.
//

#ifndef PROJECT_1_MULTAUTO_H
#define PROJECT_1_MULTAUTO_H
#include "Automaton.h"

class MultAuto : public Automaton
{
public:
    MultAuto() : Automaton(TokenType::MULTIPLY) {}
    void S0(const std::string& input) {
        if (input[index] == '*') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};


#endif //PROJECT_1_MULTAUTO_H
