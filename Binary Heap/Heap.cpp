//
// Created by vivek on 11-11-2022.
//

#include "Heap.h"

Heap::Heap(int val) {
    array.push_back(-1);            // Handling index 0
    array.push_back(val);
}

void Heap::insert(int key) {
    auto i = array.size();
    int temp = key;
    array.push_back(key);

    while (i > 1 && temp > array.at(i / 2)) {
        array.at(i) = array.at(i / 2);
        i /= 2;
    }
    array.at(i) = key;
}

int Heap::remove() {
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
    return x;
}

void Heap::heapify(std::vector<int> arr) {

}

std::ostream &operator<<(std::ostream &os, const Heap &heap) {
    os << "Max Heap: [" << std::flush;
    for (int i = 1; i < heap.array.size(); i++) {
        os << heap.array.at(i) << std::flush;
        if (i < heap.array.size() - 1) {
            os << ", " << std::flush;
        }
    }
    os << "]" << std::endl;
    return os;
}
