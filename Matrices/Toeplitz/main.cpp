#include <iostream>
#include "Toeplitz.h"

using namespace std;

int main() {
    Toeplitz matrix(3);
    matrix.set(1,1,1);
    matrix.set(1,2,2);
    matrix.set(1,3,3);
    matrix.set(2,1,4);
    matrix.set(3,1,5);
    cout << matrix;
}
