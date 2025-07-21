// token.h
#pragma once
#include <string>

enum class TokenType {
    LET, IDENTIFIER, EQUAL, NUMBER, PLUS, MINUS, STAR, SLASH, SEMICOLON,
    LPAREN, RPAREN,
    PRINT,
    END_OF_FILE,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;

    Token(TokenType t, const std::string& v) : type(t), value(v) {}
};
