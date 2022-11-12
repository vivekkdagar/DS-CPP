//
// Created by vivek on 08-11-2022.
//

#include <stack>
#include "Tree.h"

Tree::Tree(int val) {               // Constructor that takes in value of root node and creates it.
    root = new Node(val);
    q.emplace(root);
}

void Tree::grow() {             // Takes more values and makes the tree grow.
    Node *cur, *temp;
    int x;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        cout << "Enter left child data of " << cur->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            temp = new Node(x);
            cur->lChild = temp;
            q.emplace(temp);
        }

        cout << "Enter right child data of " << cur->data << ": " << flush;
        cin >> x;
        if (x != -1) {
            temp = new Node(x);
            cur->rChild = temp;
            q.emplace(temp);
        }
    }
}

/* Preorder traversal of the tree
 * Algorithm: visit current node
 * Traverse left child
 * Traverse right child */
void Tree::Preorder(Node *p) {
    if (p) {
        cout << p->data << ", " << flush;
        Preorder(p->lChild);
        Preorder(p->rChild);
    }
}

/* Iterative version of pre-order traversal
 * A stack is needed for this process. We take the ptr to root as input
 * Algorithm:
 * Take a stack of node * type. if root ptr is valid, print the data, push the address onto the stack
 * and move to the left child
 * if the pointer is not valid, get the address from stack, pop the top off the stack and move to right child as the recursive algo goes like:
 * Visit current node, go left, then go right. This happens iteratively under the condition "stk is not empty || root pointer is valid". If either of them
 * becomes false, the loop ends as there would be no new addresses to process upon. */
void Tree::PreorderItr(Node *rt) {
    std::stack<Node *> st;
    while (rt || !st.empty()) {
        if (rt) {
            std::cout << rt->data << " ";
            st.push(rt);
            rt = rt->lChild;
        } else {
            rt = st.top();
            st.pop();
            rt = rt->rChild;
        }
    }
}

/* Inorder traversal of the tree
 * Algorithm: Traverse left node
 * Visit current node
 * Traverse right node */
void Tree::Inorder(Node *p) {
    if (p) {
        Inorder(p->lChild);
        cout << p->data << ", " << flush;
        Inorder(p->rChild);
    }
}

// Iterative version of in-order traversal
void Tree::InorderItr(Node *p) {
    std::stack<Node *> st;
    while (p || !st.empty()) {
        if (p) {
            st.push(p);
            p = p->lChild;
        } else {
            p = st.top();
            st.pop();
            std::cout << p->data << " ";
            p = p->rChild;
        }
    }
}

/* Postorder traversal of the tree
 * Algorithm: Traverse left node
 * Traverse right node
 * Visit current node */
void Tree::Postorder(Node *p) {
    if (p) {
        Postorder(p->lChild);
        Postorder(p->rChild);
        cout << p->data << ", " << flush;
    }
}

void Tree::PostOrderItr(Node *p) {
    // TODO: Implement iterative version of Postorder function
}

void Tree::Levelorder(Node *p) {
    queue<Node *> q;
    cout << root->data << ", " << flush;
    q.emplace(root);

    while (!q.empty()) {
        p = q.front();
        q.pop();

        if (p->lChild) {
            cout << p->lChild->data << ", " << flush;
            q.emplace(p->lChild);
        }

        if (p->rChild) {
            cout << p->rChild->data << ", " << flush;
            q.emplace(p->rChild);
        }
    }
}

unsigned short Tree::count(Node *p) {       // Counts all nodes in a tree
    if (!p)
        return 0;
    return count(p->lChild) + count(p->rChild) + 1;
}

unsigned short Tree::countD2nodes(Node *p) {            // Counts degree 2 nodes only
    int x, y;
    if (p) {
        x = countD2nodes(p->lChild);
        y = countD2nodes(p->rChild);
        if (p->lChild && p->rChild)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

int Tree::sum(Node *p) {            // sum of all elements in the tree
    if (!p)
        return 0;
    return sum(p->lChild) + sum(p->rChild) + p->data;
}

unsigned short Tree::countLeafs(Node *p) {          // Counts leaf nodes in the tree, a.k.a. nodes with degree 0
    int x, y;
    if (p) {
        x = countLeafs(p->lChild);
        y = countLeafs(p->rChild);
        if (!p->lChild && !p->rChild)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

/* Height of a null subtree is -1. So we recursively traverse the
 * left subtree and the right subtree of the root node and when we hit null, we compare which one is bigger
 * and return the bigger amount + 1.*/
int Tree::Height(Node *p) {
    if (!p)
        return 0;

    int l = 0;
    int r = 0;
    l = Height(p->lChild);
    r = Height(p->rChild);

    return ((l > r) ? l : r) + 1;
}

bool Tree::isStrictBinary() {
    return (countLeafs() + countD2nodes() == count());
}

bool Tree::exists(Node *p, int key) {
    if (p) {
        if (p->data == key)
            return true;

        /* then recur on left subtree */
        bool res1 = exists(p->lChild, key);
        // node found, no need to look further
        if (res1) return true;

        /* node is not found in left,
        so recur on right subtree */
        bool res2 = exists(p->rChild, key);

        return res2;
    }
    return false;
}

void Tree::destroy(Node *p) {
    if (p) {
        destroy(p->lChild);
        destroy(p->rChild);
        delete p;
    }
}

Tree::~Tree() {
    destroy(root);
}





