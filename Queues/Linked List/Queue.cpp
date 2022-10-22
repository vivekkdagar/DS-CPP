//
// Created by vivek on 21-10-2022.
//

#include <iostream>
#include "Queue.h"

template<class T>
Queue<T>::Queue() {
    front = rear = nullptr;
}

template<class T>
void Queue<T>::enqueue(T x) {
    auto *temp = new Node<T>(x);
    temp->next = nullptr;
    if (!temp)
        std::cerr << "Queue full!\n";
    else {
        if (!front)
            front = rear = temp;
        else {
            rear->next = temp;
            rear = temp;
        }
    }
}

template<>
int Queue<int>::dequeue() {
    int x = -1;
    if (!front) {
        std::cerr << "Queue empty!\n";
    } else {
        x = this->front->data;
        Node<int> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

template<>
char Queue<char>::dequeue() {
    char x = ' ';
    if (!front) {
        std::cerr << "Queue empty!\n";
    } else {
        x = this->front->data;
        Node<char> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

template<>
double Queue<double>::dequeue() {
    double x = -1;
    if (!front) {
        std::cerr << "Queue empty!\n";
    } else {
        x = this->front->data;
        Node<double> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

template<>
std::string Queue<std::string>::dequeue() {
    std::string x;
    if (!front) {
        std::cerr << "Queue empty!\n";
    } else {
        x = this->front->data;
        Node<std::string> *t = front;
        front = front->next;
        delete t;
    }
    return x;
}

template<class T>
Queue<T>::~Queue() {
    Node<T> *p = this->front;
    while (p) {
        front = front->next;
        delete p;
        p = front;
    }
}
