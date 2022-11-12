//
// Created by vivek on 08-11-2022.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef struct Node {
    Node *lChild{};
    int data{};
    Node *rChild{};

    explicit Node(int data) : data(data) {
        this->lChild = this->rChild = nullptr;
    }

    Node() = default;
} Node;

#include <iostream>
#include <queue>

using namespace std;


class Tree {
private:
    Node *root;
    queue<Node *> q;
public:
    explicit Tree(int val);

    void grow();

    void Preorder() { Preorder(root); }  // Passing Private Parameter

    void PreorderItr() { Preorder(root); }

    void Inorder() { Inorder(root); }

    void InorderItr() { Inorder(root); }

    void Postorder() { Postorder(root); }

    void PostOrderItr() { PostOrderItr(root); }

    void Levelorder() { Levelorder(root); }

    int Height() { return Height(root); }

    unsigned short count() { return count(root); }

    int sum() { return sum(root); }

    unsigned short countD2nodes() { return countD2nodes(root); }

    unsigned short countLeafs() { return countLeafs(root); }

    bool isStrictBinary();

    bool exists(Node *p, int key);

    bool exists(int key) { return exists(root, key); }

    void destroy(Node *p);

    ~Tree();

private:
    void Preorder(Node *p);

    void PreorderItr(Node *rt);

    void Inorder(Node *p);

    void InorderItr(Node *p);

    void Postorder(Node *p);

    void Levelorder(Node *p);

    int Height(Node *p);

    void PostOrderItr(Node *p);

    unsigned short count(Node *p);

    unsigned short countD2nodes(Node *p);

    int sum(Node *p);

    unsigned short countLeafs(Node *p);
};

#endif //TREE_TREE_H
