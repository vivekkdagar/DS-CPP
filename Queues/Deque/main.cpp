#include <iostream>
#include "Deque.h"

using namespace std;

int main() {
    Deque<int> dq;
    dq.insert_front(1);
    dq.insert_front(2);
    dq.insert_front(3);
    dq.insert_back(2);
    dq.insert_back(6);
    cout << dq.last();
    return 0;
}
