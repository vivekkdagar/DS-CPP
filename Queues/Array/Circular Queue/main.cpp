#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<std::string> q(5);
    q.enqueue("10");
    q.enqueue("20");

    q.enqueue("10");
    q.enqueue("20");
    cout << q << endl;
}
