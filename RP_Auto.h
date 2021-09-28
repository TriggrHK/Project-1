//
// Created by trevo on 9/13/2021.
//

#ifndef RP_AUTO_H
#define RP_AUTO_H
#include "Automaton.h"

class RP_Auto : public Automaton
{
public:
    RP_Auto() : Automaton(TokenType::RIGHT_PAREN) {}
    void S0(const std::string& input) {
        if (input[index] == ')') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};
#endif //RP_AUTO_H
