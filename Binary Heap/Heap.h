//
// Created by vivek on 11-11-2022.
//

#ifndef BINARY_HEAP_HEAP_H
#define BINARY_HEAP_HEAP_H


#include <vector>
#include <ostream>

class Heap {
public:
    std::vector<int> array;
public:
    explicit Heap(int val);

    void insert(int key);

    int remove();

    void heapify(std::vector<int> arr);

    friend std::ostream &operator<<(std::ostream &os, const Heap &heap);
};


#endif //BINARY_HEAP_HEAP_H
