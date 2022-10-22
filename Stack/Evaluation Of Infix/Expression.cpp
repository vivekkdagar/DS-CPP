//
// Created by vivek on 22-10-2022.
//

#include <stack>
#include "Expression.h"

bool Expression::isOpening(char x) {
    return (x == '(') || (x == '[') || (x == '{');
}

bool Expression::isClosing(char x) {
    return (x == ')') || (x == ']') || (x == '}');
}

bool Expression::isBalanced() {
    std::stack<char> stk;
    for (int i{0}; i < text.size(); i++) {
        if (text.at(i) == '(')           // if opening bracket, push onto stack
            stk.push(text.at(i));
        else if (text.at(i) == ')') {    // if closing bracket
            if (stk.empty())            // return false if stack empty
                return false;
            stk.pop();  // else pop element
        }
    }
    return stk.empty();     // if stack is empty at the end return true, else return false
}

unsigned Expression::bracketCount() {
    unsigned int count{0};
    for (int i{0}; i < text.length(); i++) {
        if (text[i] == '(' || text[i] == ')')
            count++;
    }
    return count;
}

unsigned int Expression::outPrecedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
        case '(':
            return 7;
        case ')':
            return 0;
    }
}

int Expression::inPrecedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
        default:
            return -1;
    }
}

bool Expression::isOperand(char x) {
    switch (x) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return false;
        default:
            return true;
    }
}

std::string Expression::StringBuilder(std::vector<char> exp) {
    std::string postfix;
    for (int i{0}; i < exp.size(); i++) {
        postfix += exp[i];
    }
    return postfix;
}

std::basic_string<char> Expression::infixToPostfix() {
    unsigned int lengthWithoutBrackets = text.length() - bracketCount();
    std::string postfix;
    int i = 0, j = 0;
    std::stack<char> stk;
    while (text[i] != '\0') {
        if (isOperand(text[i]))
            postfix[j++] = text[i++];
        else {
            if (stk.empty() || outPrecedence(text[i]) > inPrecedence(stk.top()))
                stk.push(text[i++]);

            else if (outPrecedence(text[i]) < inPrecedence(stk.top())) {
                postfix[j++] = stk.top();
                stk.pop();
            } else {
                i++;
                stk.pop();
            }
        }
    }
    while (!stk.empty()) {
        postfix[j++] = stk.top();
        stk.pop();
    }


    std::vector<char> cstr(postfix.c_str(), postfix.c_str() + postfix.size() + lengthWithoutBrackets);
    return StringBuilder(cstr);
}

int Expression::eval() {
    if(isBalanced()) {
        std::string postfix = infixToPostfix();
        std::stack<int> stk;
        int x1, x2, result;
        for (int i = 0; postfix[i] != '\0'; ++i) {
            if (isOperand(postfix[i]))
                stk.push(postfix[i] - '0');
            else {
                x2 = stk.top();
                stk.pop();
                x1 = stk.top();
                stk.pop();
                switch (postfix[i]) {
                    case '+':
                        result = x1 + x2;
                        break;
                    case '-':
                        result = x1 - x2;
                        break;
                    case '*':
                        result = x1 * x2;
                        break;
                    case '/':
                        result = x1 / x2;
                        break;
                    case '^': {
                        int x = x2;
                        result = x1;
                        for(int g = 2; g <= x; g++)
                            result *= x1;
                    } break;
                }
                stk.push(result);
            }
        }
        return stk.top();
    } return -1;
}

