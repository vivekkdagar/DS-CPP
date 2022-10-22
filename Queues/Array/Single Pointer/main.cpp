#include <iostream>
#include "Queue.h"

int main() {
    Queue<std::string> myQue(5);
    std::cout << myQue.super().rear;
}
