#include <iostream>
#include <vector>
#include <stack>

using namespace std;

unsigned precedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

bool isOperand(char x) {
    switch (x) {
        case '+':
        case '-':
        case '*':
        case '/':
            return false;
        default:
            return true;
    }
}

std::string StringBuilder(vector<char> exp) {
    string postfix = "";
    for (int i{0}; i < exp.size(); i++) {
        postfix += exp[i];
    }
    return postfix;
}

std::string InToPost(const std::string &infix) {
    std::string postfix;
    stack<char> stk;
    stk.push('#');
    unsigned i = 0, j = 0;
    while (i < infix.length()) {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (precedence(infix[i]) > precedence(stk.top())) {
                stk.push(infix[i++]);
            } else {
                postfix[j++] = stk.top();
                stk.pop();
            }
        }
    }
    while (!stk.empty()) {
        postfix[j++] = stk.top();
        stk.pop();
    }

    std::vector<char> cstr(postfix.c_str(), postfix.c_str() + postfix.size() + infix.size());
    return StringBuilder(cstr);
}

int main() {
    string infix = "a+bc*d/e";
    string postfix = InToPost(infix);
    cout << postfix;
}