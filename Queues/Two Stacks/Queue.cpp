//
// Created by vivek on 21-10-2022.
//

#include <vector>
#include <iostream>
#include "Queue.h"

template<class T>
static std::vector<T> elements;

template<class T>
void Queue<T>::enqueue(T x) {
    elements<T>.push_back(x);
    enq.push(x);
}

template<class T>
bool Queue<T>::empty() const {
    return enq.empty() && deq.empty();
}

template<>
int Queue<int>::dequeue() {
    int temp = -1;
    if (this->empty())
        std::cerr << "Queue is empty!\n";
    else {
        if (deq.empty()) {
            while (!enq.empty()) {
                deq.push(enq.top());
                enq.pop();
            }
        }
        temp = deq.top();
        deq.pop();
        elements<int>.erase(elements<int>.begin());
    }
    return temp;
}

template<>
char Queue<char>::dequeue() {
    char temp = ' ';
    if (this->empty())
        std::cerr << "Queue is empty!\n";
    else {
        if (deq.empty()) {
            while (!enq.empty()) {
                deq.push(enq.top());
                enq.pop();
            }
        }
        temp = deq.top();
        deq.pop();
        elements<char>.erase(elements<char>.begin());
    }
    return temp;
}

template<>
std::string Queue<std::string>::dequeue() {
    std::string temp = "";
    if (this->empty())
        std::cerr << "Queue is empty!\n";
    else {
        if (deq.empty()) {
            while (!enq.empty()) {
                deq.push(enq.top());
                enq.pop();
            }
        }
        temp = deq.top();
        deq.pop();
        elements<std::string>.erase(elements<std::string>.begin());
    }
    return temp;
}

template<class T>
void Queue<T>::print() {
    for (int i = 0; i < elements<T>.size(); ++i)
        std::cout << elements<T>[i] << " ";
}

template<class T>
Queue<T>::~Queue() {
    elements<T>.clear();
}
