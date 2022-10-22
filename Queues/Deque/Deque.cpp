//
// Created by vivek on 21-10-2022.
//
#include <iostream>
#include "Deque.h"

template<class T>
Deque<T>::Deque() {
    front = rear = nullptr;
}

template<class T>
void Deque<T>::insert_front(T key) {
    auto *t = new Node<T>(key);
    t->next = nullptr;
    if (!front) {
        front = rear = t;
    } else {
        t->next = front;
        front = t;
    }
}

template<class T>
void Deque<T>::insert_back(T key) {
    auto *t = new Node<T>(key);
    t->next = nullptr;
    if (!front)
        front = rear = t;
    else {
        rear->next = t;
        rear = t;
    }
}

template<class T>
void Deque<T>::delete_front() {
    if (!front)
        std::cerr << "Queue empty!\n";
    else {
        auto *t = front;
        front = front->next;
        delete t;
    }
}

template<class T>
void Deque<T>::delete_back() {
    if (!front)
        std::cerr << "Queue empty!\n";
    else {
        auto *secondlast = front, *temp = front;
        if (front->next == nullptr) {
            delete front;
            front = nullptr;
            return;
        }
        while (temp->next != nullptr && temp) {
            secondlast = temp;
            temp = temp->next;
        }
        secondlast->next = nullptr;
        delete temp;
    }
}

template<class T>
bool Deque<T>::empty() {
    return front == nullptr;
}

template<>
int Deque<int>::first() {
    return this->front ? this->front->data : -1;
}

template<>
char Deque<char>::first() {
    return this->front ? this->front->data : ' ';
}

template<>
std::string Deque<std::string>::first() {
    return this->front ? this->front->data : "";
}

template<>
int Deque<int>::last() {
    return this->rear ? this->rear->data : -1;
}

template<>
char Deque<char>::last() {
    return this->rear ? this->rear->data : ' ';
}

template<>
std::string Deque<std::string>::last() {
    return this->rear ? this->rear->data : "";
}

template<class T>
Deque<T>::~Deque() {
    auto *temp = front;
    while (temp) {
        front = front->next;
        delete temp;
        temp = front;
    }
}
