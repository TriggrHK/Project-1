//
// Created by trevo on 9/27/2021.
//

#include "Parser.h"
#include "Token.h"
Parser::Parser(std::vector<Token*> tokensList) {
    tokens = tokensList;
}
void Parser::parse(){
/**
 * First of all write parse that goes through all the tokens
 *
 * Starts with at least 1 scheme
 * can have facts
 * can have rules
 * ends with at least one query
 * lists out domain which is the strings in Facts
 *
 * if is able to read through it all without throwing an exception then print success
 * have datalog program that saves all the info into vectors then after success or failure toString the vectors
 * */
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i]->match(TokenType::COMMENT)){
           tokens.erase(tokens.begin() + i);
           i--;
        }
    }
    try {
        auto start = new datalogProgram();
        this->match(TokenType::SCHEMES);
        this->match(TokenType::COLON);
        this->parseScheme();
        this->parseSchemeList();

        this->match(TokenType::FACTS);
        this->match(TokenType::COLON);
        this->parseFactList();

        this->match(TokenType::RULES);
        this->match(TokenType::COLON);
        this->parseRuleList();

        this->match(TokenType::QUERIES);
        this->match(TokenType::COLON);
        this->parseQuery();
        this->parseQueryList();

        this->match(TokenType::EOF_CP);
    }
    catch(Token* a){
        std::cout << "Failure!\n  (" << a->codeToString() << "," << a->getDesc() << "," << a->getLineNum() << ")";
        return;
    }
    std::cout << "Success!\n";
    //to string the datalogProgram
    //change the recursion part to this part
    /*A good approach is to complete the project in three steps:
First: write a parser that only checks syntax -- this is the recursive-descent part. (Does not build any data structures.)
Second: write classes for data structures. (Rule, Predicate, Parameter, etc.)
Third: add code to the parser to create data structures. This can be done easily without modifying the lines of code that were created in the first step. For example when a parameter is being parsed a Parameter object is created and returned, then saved in the appropriate place.*/
   // while(tokenIndex < tokens.size()){std::cout << tokens[tokenIndex]->codeToString() << "\n";tokenIndex++;}
}
void Parser::match(TokenType a) {
    if(tokens[tokenIndex]->getToken() == a){
        tokenIndex++;
    }
    else{
        throw tokens[tokenIndex];
    }
}
void Parser::parseScheme() {
    this->match(TokenType::ID);
    this->match(TokenType::LEFT_PAREN);
    this->match(TokenType::ID);
    this->parseIdList();
    this->match(TokenType::RIGHT_PAREN);
}
void Parser::parseSchemeList() {
    this->parseScheme();
    if(tokens[tokenIndex]->getToken() != TokenType::FACTS) {
        this->parseSchemeList();
    }
}
void Parser::parseFactList() {
    this->parseFact();
    if(tokens[tokenIndex]->getToken() != TokenType::RULES) {
        this->parseFactList();
    }
}
void Parser::parseFact() {
    this->match(TokenType::ID);
    this->match(TokenType::LEFT_PAREN);
    this->match(TokenType::STRING);
    this->parseStringList();
    this->match(TokenType::RIGHT_PAREN);
    this->match(TokenType::PERIOD);
}
void Parser::parseRuleList() {
    this->parseRule();
    if(tokens[tokenIndex]->getToken() != TokenType::QUERIES) {
        this->parseRuleList();
    }
}
void Parser::parseRule(){
    this->parseHeadPredicate();
    this->match(TokenType::COLON_DASH);
    this->parsePredicate();
    this->parsePredicateList();
    this->match(TokenType::PERIOD);
}
void Parser::parseStringList() {
    this->match(TokenType::COMMA);
    this->match(TokenType::STRING);
    if(tokens[tokenIndex]->getToken() != TokenType::RIGHT_PAREN) {
        this->parseStringList();
    }
}
void Parser::parseIdList() {
    this->match(TokenType::COMMA);
    this->match(TokenType::ID);
    if(tokens[tokenIndex]->getToken() != TokenType::RIGHT_PAREN) {
        this->parseIdList();
    }
}
void Parser::parseHeadPredicate() {
    //just have it run a scheme lol
    this->match(TokenType::ID);
    this->match(TokenType::LEFT_PAREN);
    this->match(TokenType::ID);
    this->parseIdList();
    this->match(TokenType::RIGHT_PAREN);
}
void Parser::parsePredicate() {
    this->match(TokenType::ID);
    this->match(TokenType::LEFT_PAREN);
    this->parseParameter();
    this->parseParameterList();
    this->match(TokenType::RIGHT_PAREN);
}
void Parser::parsePredicateList() {
    if(tokens[tokenIndex]->getToken() != TokenType::PERIOD) {
        this->match(TokenType::COMMA);
        this->parsePredicate();
    }
    if(tokens[tokenIndex]->getToken() != TokenType::PERIOD) {
        this->parsePredicateList();
    }
}
void Parser::parseParameter() {
    if(tokens[tokenIndex]->getToken() == TokenType::STRING) {
        this->match(TokenType::STRING);
    }
    else{
        this->match(TokenType::ID);
    }
}
void Parser::parseParameterList() {
    this->match(TokenType::COMMA);
    this->parseParameter();
    if(tokens[tokenIndex]->getToken() != TokenType::RIGHT_PAREN) {
        this->parseParameterList();
    }
}
void Parser::parseQuery() {
    this->parsePredicate();
    this->match(TokenType::Q_MARK);
}
void Parser::parseQueryList() {
    this->parseQuery();
    if (tokens[tokenIndex]->getToken() != TokenType::EOF_CP) {
        this->parseQueryList();
    }
}