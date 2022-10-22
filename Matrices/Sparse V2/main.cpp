#include <iostream>
#include "Sparse.h"

using namespace std;

int main() {
    Sparse s2(2, 2, 2);
    s2.append(0, 0, 1);
    s2.append(0, 1, 3);
    Node *first = s2.getFirst();
    cout << first->data->val << endl;
    s2.display();
    cout << endl;
//    int row[] = {0, 1, 2, 3};
//    int row2[] = {0, 0, 0, 0};
//    int row3[] = {3, 3, 3, 3};
//    int col[] = {0, 1, 2, 3};
//    int col2[] = {0, 0, 0, 0};
//    int col3[] = {3, 3, 3, 3};
//    int x[] = {1, 2, 3, 4};
//
//    Sparse s(4, 4, 4), k(4, 4, 4), l(4, 4, 4), m(4, 4, 4), n(4, 4, 4);
//    for (int i = 0; i < 4; i++)
//        s.append(row[i], col[i], x[i]);
//    for (int i = 0; i < 4; i++)
//        k.append(row[i], col2[i], x[i]);
//    for (int i = 0; i < 4; i++)
//        l.append(row2[i], col[i], x[i]);
//    for (int i = 0; i < 4; i++)
//        m.append(row[i], col3[i], x[i]);
//    for (int i = 0; i < 4; i++)
//        n.append(row3[i], col[i], x[i]);
//
//    s.display();
//    cout << endl;
//    k.display();
//    cout << endl;
//    l.display();
//    cout << endl;
//    m.display();
//    cout << endl;
//    n.display();
//    cout << endl;
//
//    Sparse s1 = ((((s + k) + l) + m) + n);
//    s1.display();
//    cout << endl;
//    return 0;
}