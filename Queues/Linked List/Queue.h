//
// Created by vivek on 21-10-2022.
//

#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <ostream>

template<class T>
struct Node {
    T data;
    Node *next;

    explicit Node(T data) : data(data) {}
};

template<class T>
class Queue {
    Node<T> *front;
    Node<T> *rear;
public:
    Queue();

    void enqueue(T x);

    T dequeue();

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue) {
        Node<T> *p = queue.front;
        while (p) {
            os << p->data << " ";
            p = p->next;
        }
        return os;
    }

    virtual ~Queue();
};

template
class Queue<int>;

template
class Queue<char>;

template
class Queue<double>;

template
class Queue<std::string>;

#endif //LINKED_LIST_QUEUE_H
