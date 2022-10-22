#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<std::string> queue(5);
    queue.enqueue("Hello");
    queue.enqueue("my");
    queue.enqueue("son");
    queue.enqueue("God");
    queue.enqueue("worldd");
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    std::cout << queue.super().front;
}
