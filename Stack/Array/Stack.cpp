//
// Created by vivek on 22-10-2022.
//

#include <iostream>
#include "Stack.h"

template<class T> // Constructor 1
Stack<T>::Stack(const info &space):space(space) {}

template<class T>
Stack<T>::Stack(unsigned size) {        // Constructor 2
    this->space.size = size;
}

template<class T>
void Stack<T>::push(T x) {          // Push element onto the stack
    if (this->space.full()) {
        std::cerr << "Stack overflow!\n";
    } else {
        this->space.top++;
        array.push_back(x);
    }
}

template<class T>
void Stack<T>::pop() {          // Pop element from the stack, Last inserted is first to be removed
    if (this->space.empty()) {
        std::cerr << "Stack underflow!\n";
    } else {
        array.pop_back();
        this->space.top--;
    }
}

template<>
int Stack<int>::peek() {            // Get top element without removing it
    return this->space.empty() ? -1 : this->array.back();
}

template<>
char Stack<char>::peek() {
    return this->space.empty() ? ' ' : this->array.back();
}

template<>
std::string Stack<std::string>::peek() {
    return this->space.empty() ? "" : this->array.back();
}