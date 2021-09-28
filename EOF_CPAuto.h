//
// Created by trevo on 9/13/2021.
//

#ifndef EOF_CPAUTO_H
#define EOF_CPAUTO_H
#include "Automaton.h"

class EOF_CPAuto : public Automaton
{
public:
    EOF_CPAuto() : Automaton(TokenType::EOF_CP) {}
    void S0(const std::string& input) {
        if (input.empty()) {
            inputRead = 1;
            index++;
        }
        else {
            Serr();
        }
    }
};
#endif //EOF_CPAUTO_H
