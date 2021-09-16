#ifndef COLONDASHAUTO_H
#define COLONDASHAUTO_H

#include "Automaton.h"

class ColonDashAuto : public Automaton
{
private:
    void S1(const std::string& input);

public:
    ColonDashAuto() : Automaton(TokenType::COLON_DASH) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif // COLONDASHAUTO_H

