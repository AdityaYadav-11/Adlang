// lexer.cpp
#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src), pos(0) {
    currentChar = source[pos];
}

void Lexer::advance() {
    pos++;
    if (pos < source.size())
        currentChar = source[pos];
    else
        currentChar = '\0';
}

void Lexer::skipWhitespace() {
    while (isspace(currentChar)) advance();
}

Token Lexer::number() {
    std::string num;
    while (isdigit(currentChar)) {
        num += currentChar;
        advance();
    }
    return Token(TokenType::NUMBER, num);
}

Token Lexer::identifier() {
    std::string id;
    while (isalnum(currentChar)) {
        id += currentChar;
        advance();
    }

    if (id == "let") return Token(TokenType::LET, id);
    if (id == "print") return Token(TokenType::PRINT, id);
    return Token(TokenType::IDENTIFIER, id);
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) {
            skipWhitespace();
            continue;
        }

        if (isalpha(currentChar))
            return identifier();

        if (isdigit(currentChar))
            return number();

        if (currentChar == '=') { advance(); return Token(TokenType::EQUAL, "="); }
        if (currentChar == '+') { advance(); return Token(TokenType::PLUS, "+"); }
        if (currentChar == '-') { advance(); return Token(TokenType::MINUS, "-"); }
        if (currentChar == '*') { advance(); return Token(TokenType::STAR, "*"); }
        if (currentChar == '/') { advance(); return Token(TokenType::SLASH, "/"); }
        if (currentChar == ';') { advance(); return Token(TokenType::SEMICOLON, ";"); }
        if (currentChar == '(') { advance(); return Token(TokenType::LPAREN, "("); }
        if (currentChar == ')') { advance(); return Token(TokenType::RPAREN, ")"); }

        // Unknown char
        std::string unknown(1, currentChar);
        advance();
        return Token(TokenType::UNKNOWN, unknown);
    }

    return Token(TokenType::END_OF_FILE, "");
}
