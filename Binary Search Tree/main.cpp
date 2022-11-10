#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    int arr[] = {10,5,20,8,30,10};
    BST tree(arr, 6);
    tree.Inorder();
}
