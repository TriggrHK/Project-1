//
// Created by trevo on 9/13/2021.
//

#ifndef STRINGAUTO_H
#define STRINGAUTO_H
#include "Automaton.h"

class StringAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
public:
    StringAuto() : Automaton(TokenType::STRING) {}
    void S0(const std::string& input);
};
#endif //STRINGAUTO_H
