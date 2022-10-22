#include <iostream>
#include "UpperTriangular.h"

using namespace std;

int main() {
    UpperTriangular matrix(3);

    for(int i {1}; i <= 3; i++){
        for(int j {1}; j <= 3; j++){
            int values;
            cin >> values;
            matrix.set(i,j,values);
        }
    }

    cout << matrix;
}
