//
// Created by trevo on 9/15/2021.
//
#ifndef PROJECT_1_FACTSAUTO_H
#define PROJECT_1_FACTSAUTO_H
#include "Automaton.h"

class FactsAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    FactsAuto() : Automaton(TokenType::FACTS) {}
    void S0(const std::string& input);
};


#endif //PROJECT_1_FACTSAUTO_H
