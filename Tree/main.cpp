#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    Tree bt(25);

    bt.grow();
    cout << endl;

    cout << "Preorder: " << flush;
    bt.PreorderItr();
    cout << endl;

    cout << "Inorder: " << flush;
    bt.InorderItr();
    cout << endl;

    cout << "Postorder: " << flush;
    bt.Postorder();
    cout << endl;

    cout << "Levelorder: " << flush;
    bt.Levelorder();
    cout << endl;

    cout << "count of degree 2: " << bt.isStrictBinary() << endl;
}
