// main.cpp
#include <iostream>
#include "lexer.h"

int main() {
    std::string source = "let x = 5 + 2;\nprint(x);";
    Lexer lexer(source);

    Token token = lexer.getNextToken();
    while (token.type != TokenType::END_OF_FILE) {
        std::cout << "Token: " << static_cast<int>(token.type)
                  << ", Value: \"" << token.value << "\"" << std::endl;
        token = lexer.getNextToken();
    }

    return 0;
}
