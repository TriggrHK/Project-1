//
// Created by trevo on 9/27/2021.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "Token.h"
#include "datalogProgram.h"
#include <vector>
#include <iostream>

class Parser {
private:
    int tokenIndex = 0;
    std::vector<Token*> tokens;
public:
    Parser(std::vector<Token*> tokenList);
    void parse();
    void match(TokenType a);
    void parseScheme();
    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQuery();
    void parseQueryList();
    void parseIdList();
    void parseFact();
    void parseStringList();
    void parseRule();
    void parsePredicate();
    void parseHeadPredicate();
    void parseParameter();
    void parseParameterList();
    void parsePredicateList();
};


#endif //PROJECT_1_PARSER_H
