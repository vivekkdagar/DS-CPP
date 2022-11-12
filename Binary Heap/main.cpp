#include <iostream>
#include "Heap.h"

using namespace std;

int main() {
    Heap pile(5);
    pile.insert(7);
    pile.insert(3);
    pile.insert(6);

    vector<int> array = pile.array;
    int x = array[0];  // Max element
    array[0] = array[array.size()-1];

    int i = 0;
    int j = 2 * i + 1;

    while (j < array.size()-1){
        // Compare left and right children
        if (array[j] < array[j+1]){
            j = j+1;
        }

        // Compare parent and largest child
        if (array[i] < array[j]){
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i = j;
            j = 2 * i + 1;
        } else {
            break;
        }
    }
    cout << "Em " << array[array.size() - 1 ];
    for(int i {1}; i < array.size() - 1; i++) {
        cout << array[i] << " ";
    }
}
