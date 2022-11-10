//
// Created by vivek on 08-11-2022.
//

#include <iostream>
#include <stack>
#include "BST.h"

BST::BST() {
    root = nullptr;
}

void BST::sprout(int key) {
    Node *temp = root, *tail, *p;

    if (!this->root) {
        p = new Node(key);
        root = p;
        return;
    }
    while (temp) {
        tail = temp;
        if (key < temp->data)
            temp = temp->lChild;
        else if (key > temp->data)
            temp = temp->rChild;
        else
            return;
    }
    p = new Node(key);
    if (key < tail->data)
        tail->lChild = p;
    else
        tail->rChild = p;
}

void BST::Inorder(Node *p) {
    if (p) {
        Inorder(p->lChild);
        std::cout << p->data << " ";
        Inorder(p->rChild);
    }
}

Node *BST::search(int key) {
    Node *t = root;
    while (t) {
        if (t->data == key)
            return t;
        else if (t->data > key)
            t = t->lChild;
        else
            t = t->rChild;
    }
    return nullptr;
}

Node *BST::sproutR(Node *p, int key) {
    Node *t = nullptr;
    if (!p) {
        t = new Node(key);
        return t;
    }
    if (key < p->data)
        p->lChild = sproutR(p->lChild, key);
    else if (key > p->data)
        p->rChild = sproutR(p->rChild, key);
    return p;
}

static int lk = 0;

Node *BST::sproutR(int key) {
    if (lk < 1) {
        this->root = this->sproutR(root, key);
    }
    this->sproutR(root, key);
    lk++;
}

Node *BST::search(Node *t, int key) {
    if (!t)
        return nullptr;
    if (t->data == key)
        return t;
    else if (key < t->data)
        return search(t->lChild, key);
    else
        return search(t->rChild, key);
}

unsigned BST::Height(Node *p) {     // height of tree
    if (!p)
        return 0;
    int x, y;
    x = Height(p->lChild);
    y = Height(p->rChild);
    return x > y ? x + 1 : y + 1;
}

Node *BST::InPre(Node *p) {         // finds In order predecessor, rightmost child of left subtree
    while (p && p->rChild)
        p = p->rChild;
    return p;
}

Node *BST::InSucc(Node *p) {            // leftmost child of right subtree
    while (p && p->lChild)
        p = p->lChild;
    return p;
}

void BST::destroy(Node *p) {
    if (p) {
        destroy(p->lChild);
        destroy(p->rChild);
        delete p;
    }
}

BST::~BST() {
    destroy(root);
}

Node *BST::remove(Node *p, int key) {

    if (p == nullptr)
        return nullptr;

    Node *q;

    if (!p->lChild && !p->rChild && (p->data == key)) {
        if (p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }

    if (key < p->data)
        p->lChild = remove(p->lChild, key);
    else if (key > p->data)
        p->rChild = remove(p->rChild, key);
    else {
        if (Height(p->lChild) > Height(p->rChild)) {
            q = InPre(p->lChild);
            p->data = q->data;
            p->lChild = remove(p->rChild, q->data);
        } else {
            q = InSucc(p->rChild);
            p->data = q->data;
            p->rChild = remove(p->rChild, q->data);
        }
    }
    return p;
}

BST::BST(int *pre, int n) {
   // TODO: learn creation of binary search tree from given preorder traversal.
}
