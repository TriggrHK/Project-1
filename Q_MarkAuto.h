//
// Created by trevo on 9/13/2021.
//

#ifndef Q_MARKAUTO_H
#define Q_MARKAUTO_H
#include "Automaton.h"

class Q_MarkAuto : public Automaton
{
public:
    Q_MarkAuto() : Automaton(TokenType::Q_MARK) {}
    void S0(const std::string& input) {
        if (input[index] == '?') {
            inputRead = 1;
        }
        else {
            Serr();
        }
    }
};
#endif //Q_MARKAUTO_H
