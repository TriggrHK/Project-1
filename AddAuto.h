//
// Created by trevo on 9/15/2021.
//

#ifndef PROJECT_1_ADDAUTO_H
#define PROJECT_1_ADDAUTO_H
#include "Automaton.h"

class AddAuto : public Automaton
{
public:
    AddAuto() : Automaton(TokenType::ADD) {}
    void S0(const std::string& input) {
        if (input[index] == '+') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};


#endif //PROJECT_1_ADDAUTO_H
