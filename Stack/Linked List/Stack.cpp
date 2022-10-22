//
// Created by vivek on 22-10-2022.
//

#include <iostream>
#include "Stack.h"

template<class T>
void Stack<T>::push(T x) {          // Push an element onto the stack
    if (!top) {
        top = new Node<T>(x);       // if top doesn't exist, create it and make it point to null
        top->next = nullptr;
    } else {
        auto *t = new Node<T>(x);           // create new node, make it point to top
        t->next = top;
        top = t;        // move top to new node
    }
}

template<class T>
void Stack<T>::pop() {          // Pop element from stack
    if (!top) {
        std::cerr << "Stack underflow!\n";
    } else {
        auto *t = top;
        top = top->next;
        delete t;
    }
}

template<>
int Stack<int>::peek() {            // Get top element without removing it
    return this->empty() ? -1 : top->data;
}

template<>
char Stack<char>::peek() {
    return this->empty() ? ' ' : top->data;
}

template<>
std::string Stack<std::string>::peek() {
    return this->empty() ? "" : top->data;
}

template<class T>
unsigned Stack<T>::size() {         // get size of stack
    Node<T> *temp = this->top;
    unsigned int count{0};
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

template<class T>
Stack<T>::~Stack() {            // Destructor
    Node<T> *temp = this->top;
    while (temp) {
        this->top = top->next;
        delete temp;
        temp = this->top;
    }
}


