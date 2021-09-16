//
// Created by trevo on 9/16/2021.
//

#ifndef PROJECT_1_UNDEFINEDAUTO_H
#define PROJECT_1_UNDEFINEDAUTO_H


#include "Automaton.h"

class UndefinedAuto : public Automaton
{
public:
    UndefinedAuto() : Automaton(TokenType::UNDEFINED) {}
    void S0(const std::string& input);
};
#endif //PROJECT_1_UNDEFINEDAUTO_H
