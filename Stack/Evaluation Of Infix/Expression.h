//
// Created by vivek on 22-10-2022.
//

#ifndef EVALUATION_OF_INFIX_EXPRESSION_H
#define EVALUATION_OF_INFIX_EXPRESSION_H


#include <string>
#include <vector>

class Expression {
    std::string text;
public:
    void setInfix(const std::string &infixExp) {
        Expression::text = infixExp;
    }

    static bool isOpening(char x);

    static bool isClosing(char x);

    bool isBalanced();

    unsigned bracketCount();

    static unsigned int outPrecedence(char x);

    static int inPrecedence(char x);

    static bool isOperand(char x);

    static std::string StringBuilder(std::vector<char> exp);

    std::basic_string<char> infixToPostfix();

    int eval();

};


#endif //EVALUATION_OF_INFIX_EXPRESSION_H
