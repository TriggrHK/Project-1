#ifndef TOKEN_H
#define TOKEN_H
#include <string>


enum class TokenType {
    // TODO: add the other types of tokens queries, id, left paren, string, comma, right paren, qmark, rules, period, eof, comment, schemes, undefined
    COLON,
    COLON_DASH,
    QUERIES,
    ID,
    MULTIPLY,
    ADD,
    FACTS,
    LEFT_PAREN,
    RIGHT_PAREN,
    STRING,
    COMMA,
    Q_MARK,
    RULES,
    PERIOD,
    COMMENT,
    SCHEMES,
    EOF_CP,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    TokenType inType;
    std::string inDesc;
    int inLineNum;

public:
    Token(TokenType type, std::string description, int line);
    // TODO: add other needed methods
    std::string codeToString();
    std::string getDesc();
    int getLineNum();
};

#endif // TOKEN_H

