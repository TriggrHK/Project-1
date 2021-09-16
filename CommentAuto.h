//
// Created by trevo on 9/13/2021.
//

#ifndef COMMENTAUTO_H
#define COMMENTAUTO_H
#include "Automaton.h"

class CommentAuto : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
public:
    CommentAuto() : Automaton(TokenType::COMMENT) {}
    void S0(const std::string& input);
};
#endif //COMMENTAUTO_H
