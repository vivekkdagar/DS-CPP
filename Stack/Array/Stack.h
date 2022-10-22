//
// Created by vivek on 22-10-2022.
//

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <deque>
#include <ostream>

typedef struct info {
    int top = -1;            // pointer to top
    unsigned size;

    unsigned int capacity() const {
        return size;
    }

    bool empty() const {
        return top == -1;
    }

    bool full() const {
        return top == size - 1;
    }
} info;

template<class T>
class Stack {
    info space;
    std::deque<T> array;
public:
    explicit Stack(const info &space);

    explicit Stack(unsigned size);

    info super() const {            // return the structure
        return space;
    }

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack) {         // printing the stack
        for (int i = stack.space.top; i >= 0; i--)
            os << stack.array.at(i) << std::endl;
        return os;
    }

    void push(T x);

    void pop();

    T peek();

    virtual ~Stack() = default;         // Destructor
};

template
class Stack<int>;

template
class Stack<char>;

template
class Stack<std::string>;


#endif //ARRAY_STACK_H
