//
// Created by vivek on 21-10-2022.
//

#ifndef CIRCULAR_QUEUE_QUEUE_H
#define CIRCULAR_QUEUE_QUEUE_H

#include <ostream>

typedef struct info {
    unsigned size;
    int front = -1;
    int rear = -1;

    bool full() const {
        return rear == size - 1;
    }

    bool empty() const {
        return front == rear;
    }
} info;

template<class T>
class Queue {
    info pointers;
    T *array;
public:
    explicit Queue(const info &pointers);

    explicit Queue(unsigned size);

    void enqueue(T x);

    T dequeue();

    info super() const;

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue) {
        int i = queue.pointers.front + 1 % queue.pointers.size;
        while (i != (queue.pointers.rear + 1) % queue.pointers.size) {
            os << queue.array[i] << " ";
            i = (i + 1) % queue.pointers.size;
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
class Queue<std::string>;

template
class Queue<double>;

#endif //CIRCULAR_QUEUE_QUEUE_H
