//
// Created by vivek on 22-10-2022.
//

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <ostream>

template<class T>
struct Node {
    T data;
    Node<T> *next;

    explicit Node(T data) : data(data) {}
};

template<class T>
class Stack {
    Node<T> *top;
public:
    explicit Stack(Node<T> *top) : top(top) {}          // Constructor 1

    Stack() : top(nullptr) {}            // Constructor 2

    void push(T x);

    void pop();

    T peek();

    unsigned size();

    bool empty() const {            // Check if stack is empty
        return top == nullptr;
    }

    friend std::ostream &operator<<(std::ostream &os, const Stack &stack) {         // Printing the stack
        Node<T> *temp = stack.top;
        while (temp) {
            os << temp->data << "\n";
            temp = temp->next;
        }
        return os;
    }

    virtual ~Stack();
};

template
class Stack<int>;

template
class Stack<char>;

template
class Stack<std::string>;

#endif //LINKED_LIST_STACK_H
