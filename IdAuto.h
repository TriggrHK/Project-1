//
// Created by trevo on 9/13/2021.
//

#ifndef IDAUTO_H
#define IDAUTO_H
#include "Automaton.h"

class IdAuto : public Automaton
{
private:
    void S1(const std::string& input);
public:
    IdAuto() : Automaton(TokenType::ID) {}
    void S0(const std::string& input);
};
#endif //IDAUTO_H
