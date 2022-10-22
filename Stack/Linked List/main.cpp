#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    auto *t = new Stack<int>;
    t->push(1);
    t->push(2);
    cout << t->peek();
    delete t;
}
