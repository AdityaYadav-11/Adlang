// lexer.h
#pragma once
#include <string>
#include <vector>
#include "token.h"

class Lexer {
    std::string source;
    size_t pos;
    char currentChar;

    void advance();
    void skipWhitespace();
    Token number();
    Token identifier();

public:
    Lexer(const std::string& src);
    Token getNextToken();
};
