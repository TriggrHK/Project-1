//
// Created by trevo on 9/13/2021.
//

#ifndef LP_AUTO_H
#define LP_AUTO_H
#include "Automaton.h"

class LP_Auto : public Automaton
{
public:
    LP_Auto() : Automaton(TokenType::LEFT_PAREN) {}
    void S0(const std::string& input) {
        if (input[index] == '(') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};
#endif //LP_AUTO_H
