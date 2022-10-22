#include <iostream>
#include "Toeplitz.h"

using namespace std;

int main() {
    Toeplitz matrix(3);
    for(int i {1}; i <= 3; i++ ){
        for(int j {1}; j <= 3; j++) {
            matrix.set(i,j, i);
        }
    }
    cout << matrix;
}
