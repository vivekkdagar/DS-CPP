#include <iostream>
#include "Expression.h"

using namespace std;

int main() {
    Expression s1;
    s1.setInfix("3+(2^3)*4/2");
    cout << s1.eval();
}
