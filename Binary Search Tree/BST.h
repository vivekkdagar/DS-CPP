//
// Created by vivek on 08-11-2022.
//

#ifndef BINARY_SEARCH_TREE_BST_H
#define BINARY_SEARCH_TREE_BST_H

typedef struct Node {
    Node *lChild;
    int data;
    Node *rChild;

    explicit Node(int data) : data(data) {
        this->lChild = this->rChild = nullptr;
    }
} Node;

class BST {
    Node *root;
public:
    BST();

    BST(int pre[], int n);          // here pre means the preorder traversal of the tree

    void sprout(int key);

    void Inorder() { Inorder(root); }

    Node *search(int key);

    Node *sproutR(int key);

    Node *InPre(Node *p);

    Node *InSucc(Node *p);

    Node *remove(int key) { remove(root, key); }

    virtual ~BST();

private:
    void Inorder(Node *p);

    Node *search(Node *t, int key);

    Node *sproutR(Node *p, int key);

    Node *remove(Node *p, int key);

    void destroy(Node *p);

    unsigned Height(Node *p);
};


#endif //BINARY_SEARCH_TREE_BST_H
