#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

unsigned int bracketCount(string infix) {
    unsigned int count{0};
    for (int i{0}; i < infix.length(); i++) {
        if (infix[i] == '(' || infix[i] == ')')
            count++;
    }
    return count;
}

unsigned int outPrecedence(char x) {            // out stack precedence
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

int inPrecedence(char x) {         // in stack precedences
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

bool isOperand(char x) {
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

std::string StringBuilder(std::vector<char> exp) {
    std::string postfix = "";
    for (int i{0}; i < exp.size(); i++) {
        postfix += exp[i];
    }
    return postfix;
}


basic_string<char> infixToPostfix(std::string infix) {
    unsigned int lengthWithoutBrackets = infix.length() - bracketCount(infix);
    std::string postfix;
    int i = 0, j = 0;
    stack<char> stk;
    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (stk.empty() || outPrecedence(infix[i]) > inPrecedence(stk.top()))
                stk.push(infix[i++]);

            else if (outPrecedence(infix[i]) < inPrecedence(stk.top())) {
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

int main() {
    string infix = "((a+b)*c)-d^e^f";
    cout << infixToPostfix(infix);
}