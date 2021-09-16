//
// Created by trevo on 9/13/2021.
//

#ifndef RULESAUTO_H
#define RULESAUTO_H
#include "Automaton.h"

class RulesAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    RulesAuto() : Automaton(TokenType::RULES) {}
    void S0(const std::string& input);
};
#endif //RULESAUTO_H
