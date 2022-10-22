#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    Polynomial obj1(2), obj2(2);
    obj1.set();

    cout << obj1.eval(1);
}
