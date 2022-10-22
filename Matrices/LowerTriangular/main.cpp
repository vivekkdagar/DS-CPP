#include <iostream>
#include "LowerTriangular.h"

using namespace std;

int main() {
    LowerTriangular matrix(3);

    for (int i{1}; i <= 3; i++) {
        for (int j{1}; j <= 3; j++) {
            if (i >= j) {
                cout << "Enter value for Pair: (" << i << ", " << j << "): ";
                int values;
                cin >> values;
                matrix.set(i, j, values);
            }
        }
    }

    cout << matrix;
}
