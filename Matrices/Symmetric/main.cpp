#include <iostream>
#include "Symmetric.h"

using namespace std;

int main() {
    Symmetric matrix(3);
    for (int i{1}; i <= 3; i++) {
        for (int j{1}; j <= 3; j++) {
            if (i >= j) {
                cout << i << " " << j << endl;
                int values;
                std::cin >> values;
                matrix.set(i, j, values);
            }
        }
    }
    std::cout << matrix;
}
