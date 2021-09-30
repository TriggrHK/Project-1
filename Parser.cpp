//
// Created by trevo on 9/27/2021.
//

#include "Parser.h"

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
        this->match(TokenType::SCHEMES);
        this->match(TokenType::COLON);
        this->parseScheme();
        this->parseSchemeList();

        //if(tokens[tokenIndex]->match(TokenType::FACTS)){}
        this->match(TokenType::FACTS);
        this->match(TokenType::COLON);
        this->parseFactList();

        //if(tokens[tokenIndex]->match(TokenType::RULES)){}
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
        std::cout << "Failure!\n  (" << a->codeToString() << ",\"" << a->getDesc() << "\"," << a->getLineNum() << ")";
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
   std::cout << "Schemes(" << schemes.size() << "):\n";
   for(int i = 0; i < schemes.size(); i++){
       std::cout << "  ";
       schemes[i].to_String();
       std::cout << "\n";
   }
    std::cout << "Facts(" << facts.size() << "):\n";
    for(int i = 0; i < facts.size(); i++){
        std::cout << "  ";
        facts[i].to_String();
        std::cout << "\n";
    }
    std::cout << "Rules(" << rules.size() << "):\n";
    for(int i = 0; i < rules.size(); i++){
        std::cout << "  ";
        rules[i].to_String();
        std::cout << "\n";
    }
    std::cout << "Queries(" << queries.size() << "):\n";
    for(int i = 0; i < queries.size(); i++){
        std::cout << "  ";
        queries[i].to_String();
        std::cout << "?\n";
    }
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
    std::string tempID;
    std::vector<Parameter> tempParam;
    this->match(TokenType::ID);
    tempID = tokens[tokenIndex-1]->getDesc();
    this->match(TokenType::LEFT_PAREN);
    this->match(TokenType::ID);
    tempParam.push_back(tokens[tokenIndex-1]->getDesc());
    tempParam = this->parseIdList(tempParam);
    Predicate a(tempID, tempParam);
    schemes.push_back(a);
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
    std::string tempID;
    std::vector<Parameter> tempParam;
    this->match(TokenType::ID);
    tempID = tokens[tokenIndex-1]->getDesc();
    this->match(TokenType::LEFT_PAREN);
    this->match(TokenType::STRING);
    tempParam.push_back(tokens[tokenIndex-1]->getDesc());
    tempParam = this->parseStringList(tempParam);
    Predicate a(tempID, tempParam);
    facts.push_back(a);
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
    std::vector<Predicate> tempPred;
    Predicate headPred = this->parseHeadPredicate();
    this->match(TokenType::COLON_DASH);
    tempPred.push_back(this->parsePredicate());
    tempPred = this->parsePredicateList(tempPred);
    this->match(TokenType::PERIOD);
    Rule a(headPred,tempPred);
    rules.push_back(a);
}
std::vector<Parameter> Parser::parseStringList(std::vector<Parameter> inParam) {
    std::vector<Parameter> tempParam = inParam;
    this->match(TokenType::COMMA);
    this->match(TokenType::STRING);
    tempParam.push_back(tokens[tokenIndex-1]->getDesc());
    if(tokens[tokenIndex]->getToken() != TokenType::RIGHT_PAREN) {
        tempParam = this->parseStringList(tempParam);
    }
    return tempParam;
}
std::vector<Parameter> Parser::parseIdList(std::vector<Parameter> inParam) {
    std::vector<Parameter> tempParam = inParam;
    this->match(TokenType::COMMA);
    this->match(TokenType::ID);
    tempParam.push_back(tokens[tokenIndex-1]->getDesc());
    if(tokens[tokenIndex]->getToken() != TokenType::RIGHT_PAREN) {
        tempParam = this->parseIdList(tempParam);
    }
    return tempParam;
}
Predicate Parser::parseHeadPredicate() {
    //just have it run a scheme lol
    std::vector<Parameter> tempParam;
    std::string tempID;
    this->match(TokenType::ID);
    tempID = tokens[tokenIndex-1]->getDesc();
    this->match(TokenType::LEFT_PAREN);
    this->match(TokenType::ID);
    tempParam.push_back(tokens[tokenIndex-1]->getDesc());
    tempParam = this->parseIdList(tempParam);
    Predicate a(tempID, tempParam);
    this->match(TokenType::RIGHT_PAREN);
    return a;
}
Predicate Parser::parsePredicate() {
    std::string tempID;
    std::vector<Parameter> tempParam;
    this->match(TokenType::ID);
    tempID = tokens[tokenIndex-1]->getDesc();
    this->match(TokenType::LEFT_PAREN);
    tempParam.push_back(this->parseParameter());
    tempParam = this->parseParameterList(tempParam);
    this->match(TokenType::RIGHT_PAREN);
    Predicate tempPred(tempID,tempParam);
    return tempPred;
}
std::vector<Predicate> Parser::parsePredicateList(std::vector<Predicate> inPred) {
    std::vector<Predicate> tempPred = inPred;
    if(tokens[tokenIndex]->getToken() != TokenType::PERIOD) {
        this->match(TokenType::COMMA);
        tempPred.push_back(this->parsePredicate());
    }
    if(tokens[tokenIndex]->getToken() != TokenType::PERIOD) {
        tempPred = this->parsePredicateList(tempPred);
    }
    return tempPred;
}
Parameter Parser::parseParameter() {
    if(tokens[tokenIndex]->getToken() == TokenType::STRING) {
        this->match(TokenType::STRING);
        return tokens[tokenIndex-1]->getDesc();
    }
    else{
        this->match(TokenType::ID);
        return tokens[tokenIndex-1]->getDesc();
    }
}
std::vector<Parameter> Parser::parseParameterList(std::vector<Parameter> inParam) {
    std::vector<Parameter> tempParam = inParam;
    this->match(TokenType::COMMA);
    tempParam.push_back(this->parseParameter());
    if(tokens[tokenIndex]->getToken() != TokenType::RIGHT_PAREN) {
        this->parseParameterList(tempParam);
    }
    return tempParam;
}
void Parser::parseQuery() {
    std::vector<Predicate> tempPred;
    queries.push_back(this->parsePredicate());
    this->match(TokenType::Q_MARK);
}
void Parser::parseQueryList() {
    this->parseQuery();
    if (tokens[tokenIndex]->getToken() != TokenType::EOF_CP) {
        this->parseQueryList();
    }
}