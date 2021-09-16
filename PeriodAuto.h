//
// Created by trevo on 9/13/2021.
//

#ifndef PERIODAUTO_H
#define PERIODAUTO_H
#include "Automaton.h"

class PeriodAuto : public Automaton
{
public:
    PeriodAuto() : Automaton(TokenType::PERIOD) {}
    void S0(const std::string& input);
};
#endif //PERIODAUTO_H
