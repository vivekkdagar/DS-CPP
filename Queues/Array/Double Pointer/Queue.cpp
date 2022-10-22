//
// Created by vivek on 21-10-2022.
//

#include <iostream>
#include "Queue.h"

template<class T>
Queue<T>::Queue(const info &pointers):pointers(pointers) {}

template<class T>
Queue<T>::Queue(unsigned int size) {
    this->pointers.size = size;
    array = new T[this->pointers.size];
}

template<class T>
void Queue<T>::enqueue(T x) {
    if (this->pointers.full()) {
        std::cerr << "Queue full!\n";
        return;
    }
    this->pointers.rear++;
    this->array[this->pointers.rear] = x;
}

template<class T>
info Queue<T>::super() const {
    return pointers;
}

template<>
int Queue<int>::dequeue() {
    int x = -1;
    if (this->pointers.empty()) {
        std::cerr << "Queue empty!\n";
        return x;
    }
    x = array[this->pointers.front + 1];
    this->pointers.front++;
    return x;
}

template<>
char Queue<char>::dequeue() {
    char x = ' ';
    if (this->pointers.empty()) {
        std::cerr << "Queue empty!\n";
        return x;
    }
    x = array[this->pointers.front + 1];
    this->pointers.front++;
    return x;
}

template<>
double Queue<double>::dequeue() {
    double x = -1;
    if (this->pointers.empty()) {
        std::cerr << "Queue empty!\n";
        return x;
    }
    x = array[this->pointers.front + 1];
    this->pointers.front++;
    return x;
}

template<>
std::string Queue<std::string>::dequeue() {
    std::string x;
    if (this->pointers.empty()) {
        std::cerr << "Queue empty!\n";
        return x;
    }
    x = array[this->pointers.front + 1];
    this->pointers.front++;
    return x;
}

template<class T>
Queue<T>::~Queue() {
    delete[]array;
}
