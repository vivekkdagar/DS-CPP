//
// Created by vivek on 21-10-2022.
//

#include <iostream>
#include "Queue.h"

template<class T>
Queue<T>::Queue(const info &space) : space(space) {}

template<class T>
Queue<T>::Queue(unsigned int size) {
    this->space.size = size;
    array = new T[this->space.size];
}

template<class T>
void Queue<T>::enqueue(T value) {
    if (this->space.has_space()) {
        ++this->space.rear;
        this->array[this->space.rear] = value;
        return;
    }
    std::cerr << "No space left!\n";
}

template<class T>
void Queue<T>::dequeue() {
    if (!this->space.empty()) {
        for (int i{0}; i < this->space.rear; ++i)
            this->array[i] = this->array[i + 1];
        this->space.rear--;
        return;
    }
    std::cerr << "Empty queue!\n";
}

template<class T>
info Queue<T>::super() const {
    return space;
}

template<class T>
Queue<T>::~Queue() {
    delete[]array;
}


