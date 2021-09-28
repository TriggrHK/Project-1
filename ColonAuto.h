#ifndef COLONAUTO_H
#define COLONAUTO_H

#include "Automaton.h"

class ColonAuto : public Automaton
{
public:
    ColonAuto() : Automaton(TokenType::COLON) {}  // Call the base constructor

    void S0(const std::string& input) {
        if (input[index] == ':') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};

#endif // COLONAUTO_H

