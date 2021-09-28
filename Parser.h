//
// Created by trevo on 9/27/2021.
//

#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "Token.h"
#include <vector>

class Parser {
private:
    int tokenIndex;
public:
    Parser(std::vector<Token*> tokenList);
    void parse();
};


#endif //PROJECT_1_PARSER_H
