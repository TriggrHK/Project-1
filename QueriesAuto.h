//
// Created by trevo on 9/13/2021.
//

#ifndef QUERIESAUTO_H
#define QUERIESAUTO_H
#include "Automaton.h"

class QueriesAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);
    void S6(const std::string& input);

public:
    QueriesAuto() : Automaton(TokenType::QUERIES) {}
    void S0(const std::string& input);
};
#endif //QUERIESAUTO_H
