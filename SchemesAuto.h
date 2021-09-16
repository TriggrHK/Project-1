//
// Created by trevo on 9/13/2021.
//

#ifndef SCHEMESAUTO_H
#define SCHEMESAUTO_H
#include "Automaton.h"

class SchemesAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);

public:
    SchemesAuto() : Automaton(TokenType::SCHEMES) {}
    void S0(const std::string& input);
};
#endif //SCHEMESAUTO_H
