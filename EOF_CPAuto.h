//
// Created by trevo on 9/13/2021.
//

#ifndef EOF_CPAUTO_H
#define EOF_CPAUTO_H
#include "Automaton.h"

class EOF_CPAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);

public:
    EOF_CPAuto() : Automaton(TokenType::EOF_CP) {}
    void S0(const std::string& input);
};
#endif //EOF_CPAUTO_H
