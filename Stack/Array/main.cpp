#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<std::string> h1(1);
    h1.push("s");
    cout << h1.super().full();
}
