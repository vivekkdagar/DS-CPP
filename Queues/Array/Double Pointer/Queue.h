//
// Created by vivek on 21-10-2022.
//

#ifndef DOUBLE_POINTER_QUEUE_H
#define DOUBLE_POINTER_QUEUE_H

typedef struct info {
    int front;
    int rear;
    unsigned size;

    info() : front(-1), rear(-1) {};

    bool full() const {
        return rear == size - 1;
    }

    bool empty() const {
        return front == rear;
    }

} info;

template<class T>
class Queue {
    info pointers{};
    T *array;
public:
    explicit Queue(const info &pointers);

    explicit Queue(unsigned size);

    void enqueue(T x);

    T dequeue();

    info super() const;

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue) {
        for (int i = queue.pointers.front + 1; i <= queue.pointers.rear; ++i)
            os << queue.array[i] << " ";
        os << std::endl;
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

#endif //DOUBLE_POINTER_QUEUE_H
