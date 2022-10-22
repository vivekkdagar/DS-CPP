#include <iostream>
#include "Queue.h"

int main() {
    Queue<std::string> h1;
    h1.enqueue("2");
    h1.enqueue("4");
    h1.enqueue("hello");
    std::cout << h1.dequeue();
    std::cout << h1.dequeue();
    std::cout << h1.dequeue();
    std::cout << h1.dequeue();
}
