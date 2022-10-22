#include <iostream>
#include <stack>

using namespace std;

bool isOpening(char x) {
    return (x == '(') || (x == '[') || (x == '{');
}

bool isClosing(char x) {
    return (x == ')') || (x == ']') || (x == '}');
}

bool isBalanced(string text) {
    stack<char> exp;
    for (int i = 0; i < text.length(); i++) {           // Traverse the string
        if (isOpening(text[i]))         // if you encounter an opening
            exp.push(text[i]);              // push
        else if (isClosing(text[i])) {          // if closing
            if (exp.empty())                    // return true is stack is empty
                return false;

            int currentlyPopped = static_cast<int>(exp.top());          // get ascii value of el currently on top of stack
            exp.pop();                                                                  // remove top
            int currentlyScanning = static_cast<int>(text[i]);          //  get ascii value of el currently scanning in the parameter text

            switch (currentlyPopped) {
                case 123: {     // Curly braces
                    if (abs(currentlyPopped - currentlyScanning) !=
                        2)          // if the differences don't equal to 2, it's not a curly closing brace
                        return false;
                }
                    break;
                case 91: {      // Square braces
                    if (abs(currentlyPopped - currentlyScanning) != 2)
                        return false;
                }
                    break;
                case 40: {      // Round braces
                    if (currentlyPopped - currentlyScanning != 1)
                        return false;
                }
                    break;
            }
        }
    }
    return exp.empty();         // at the end return true if stack is not empty
}

int main() {
    std::string text = "[{}]";
    cout << boolalpha << isBalanced(text);
}
