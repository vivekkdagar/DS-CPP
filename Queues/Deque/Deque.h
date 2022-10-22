//
// Created by vivek on 21-10-2022.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H

#include <ostream>

template<class T>
struct Node {
    T data;
    Node *next;

    explicit Node(T data) : data(data) {}
};

template<class T>
class Deque {
public:
    Node<T> *front;
    Node<T> *rear;
public:
    explicit Deque();

    // Operations
    void insert_front(T key);

    void insert_back(T key);

    void delete_front();

    void delete_back();

    bool empty();

    T first();

    T last();

    friend std::ostream &operator<<(std::ostream &os, const Deque &deque) {
        auto *temp = deque.front;
        while (temp) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }

    virtual ~Deque();
};

template
class Deque<int>;


#endif //DEQUE_DEQUE_H
