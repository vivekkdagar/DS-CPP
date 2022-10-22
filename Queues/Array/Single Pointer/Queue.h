//
// Created by vivek on 21-10-2022.
//

#ifndef SINGLE_POINTER_QUEUE_H
#define SINGLE_POINTER_QUEUE_H

typedef struct info {
    unsigned size;
    int rear = -1;

    bool empty() const {
        return rear == -1;
    }

    bool has_space() const {
        return rear != this->size - 1;
    }

} info;

template<class T>
class Queue {
    info space;
    T *array{};
public:
    explicit Queue(const info &space);

    explicit Queue(unsigned size);

    void enqueue(T value);

    void dequeue();

    info super() const;

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue) {
        for (int i = 0; i <= queue.space.rear; ++i)
            os << queue.array[i] << " ";
        return os;
    }

    virtual ~Queue();
};

template
class Queue<int>;

template
class Queue<std::string>;

template
class Queue<char>;

#endif //SINGLE_POINTER_QUEUE_H
