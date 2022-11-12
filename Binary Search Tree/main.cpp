#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST tree;
    tree.sprout(45);
    tree.sprout(26);
    tree.sprout(70);
    tree.sprout(30);
    tree.sprout(40);
    tree.Inorder();
}
