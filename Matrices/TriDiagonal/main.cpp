#include <iostream>
#include "TriDiagonal.h"

using namespace std;

int main() {
    TriDiagonal matrix(3);
    for(int i {1}; i <= 3; i++){
        for(int j {1}; j <= 3; j++){
            if(i - j == 0){
                cout << "Pair: [" << i << ", " << j << "]\n";
                int values;
                cout << "Enter value now: ";
                std::cin >> values;
                matrix.set(i,j,values);
            } else if(i-j == 1){
                cout << "Pair: [" << i << ", " << j << "]\n";
                int values;

                cout << "Enter value now: ";
                std::cin >> values;
                matrix.set(i,j,values);
            } else if(i-j == -1){
                cout << "Pair: [" << i << ", " << j << "]\n";
                int values;

                cout << "Enter value now: ";
                std::cin >> values;
                matrix.set(i,j,values);
            }
        }
    }
    cout << matrix;
    cout << endl;
}
