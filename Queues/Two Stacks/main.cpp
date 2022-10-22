#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<std::string> h1;
    h1.enqueue("Super");
    h1.enqueue("Franky");
    h1.enqueue("god");
    h1.dequeue();
    h1.dequeue();
    h1.dequeue();
    h1.dequeue();
    h1.print();
}
