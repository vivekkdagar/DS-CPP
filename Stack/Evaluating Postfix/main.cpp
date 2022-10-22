#include <iostream>
#include <stack>

using namespace std;

bool isOperand(char x) {
    switch(x) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')': return false;
        default : return true;
    }
}

int eval(std::string postfix) {
    stack<int> stk;
    int x1, x2, result;
    for(int i = 0; postfix[i] != '\0'; ++i) {
        if(isOperand(postfix[i]))
            stk.push(postfix[i] - '0');
        else {
            x2 = stk.top(); stk.pop();
            x1 = stk.top(); stk.pop();
            switch(postfix[i]) {
                case '+':  result = x1 + x2; break;
                case '-':  result = x1 - x2; break;
                case '*':  result = x1 * x2; break;
                case '/':  result = x1 / x2; break;
            } stk.push(result);
        }
    } return stk.top();
}

int main() {
    string postfix = "34*82/-";
    cout << eval(postfix);
}
