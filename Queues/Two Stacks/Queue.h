//
// Created by vivek on 21-10-2022.
//

#ifndef TWO_STACKS_QUEUE_H
#define TWO_STACKS_QUEUE_H

#include <stack>
#include <ostream>

template<class T>
class Queue {
    std::stack<T> enq;
    std::stack<T> deq;
public:
    Queue() = default;

    void enqueue(T x);

    bool empty() const;

    T dequeue();

    void print();

    virtual ~Queue();
};

template class Queue<int>;
template class Queue<char>;
template class Queue<std::string>;
#endif //TWO_STACKS_QUEUE_H
