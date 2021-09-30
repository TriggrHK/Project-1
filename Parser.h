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
    datalogProgram vectorList;
    std::vector<Predicate> schemes;
    std::vector<Predicate> facts;
    std::vector<Rule> rules;
    std::vector<Predicate> queries;

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
    std::vector<Parameter> parseIdList(std::vector<Parameter> inParam);
    void parseFact();
    std::vector<Parameter> parseStringList(std::vector<Parameter> inParam);
    void parseRule();
    Predicate parsePredicate();
    Predicate parseHeadPredicate();
    Parameter parseParameter();
    std::vector<Parameter> parseParameterList(std::vector<Parameter> inParam);
    std::vector<Predicate> parsePredicateList(std::vector<Predicate> inPred);
};


#endif //PROJECT_1_PARSER_H
