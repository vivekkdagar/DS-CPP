#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(const string &exp) {
    stack<char> stk;
    for (int i{0}; i < exp.size(); i++) {
        if (exp.at(i) == '(')           // if opening bracket, push onto stack
            stk.push(exp.at(i));
        else if (exp.at(i) == ')') {    // if closing bracket
            if (stk.empty())            // return false if stack empty
                return false;
            stk.pop();  // else pop element
        }
    }
    return stk.empty();     // if stack is empty at the end return true, else return false
}

int main() {
    string exp = "((a+b)*))";
    cout << boolalpha << isBalanced(exp);
}
