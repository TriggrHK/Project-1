#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"
#include "ColonAuto.h"
#include "ColonDashAuto.h"
#include "CommaAuto.h"
#include "CommentAuto.h"
#include "EOF_CPAuto.h"
#include "IdAuto.h"
#include "LP_Auto.h"
#include "PeriodAuto.h"
#include "Q_MarkAuto.h"
#include "QueriesAuto.h"
#include "RulesAuto.h"
#include "RP_Auto.h"
#include "SchemesAuto.h"
#include "StringAuto.h"
#include "FactsAuto.h"
#include "AddAuto.h"
#include "MultAuto.h"
#include "UndefinedAuto.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    void CreateAutomata();

    // TODO: add any other private methods here (if needed)

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
  //  std::vector<Token*> outputList();
    // TODO: add other public methods here
   // void toString();
   std::vector<Token*> getTokenList();
};

#endif // LEXER_H

