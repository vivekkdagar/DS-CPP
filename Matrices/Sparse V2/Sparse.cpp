//
// Created by vivek on 22-10-2022.
//

#include "Sparse.h"
#include <iostream>

using namespace std;

Sparse::Sparse(int rows, int cols, int nums) : rows(rows), cols(cols), nonZeroCount(nums) {
    first = new Node;
    first->data = new Element(rows, cols, 0);
}

void Sparse::append(int i, int j, int x) {
    Node *temp = new Node;
    temp->data = new Element(i, j, x);

    Node *last = first;
    while (last->next != nullptr)
        last = last->next;
    last->next = temp;
}

Sparse Sparse::operator+(Sparse &s) {
    if (s.rows == rows && s.cols == cols) {

        Sparse *tr = new Sparse(rows, cols, s.nonZeroCount + nonZeroCount);
        Node *p = first->next;
        Node *q = s.first->next;
        Node *r = tr->first;
        Node *temp;
        while (p && q) {
            temp = new Node;
            if (p->data->i < q->data->i) {
                temp->data = p->data;
                temp->next = nullptr;
                r->next = temp;
                r = r->next;
                p = p->next;
            } else if (p->data->i > q->data->i) {
                temp->data = q->data;
                temp->next = nullptr;
                r->next = temp;
                r = r->next;
                q = q->next;
            } else {
                if (p->data->j < q->data->j) {
                    temp->data = p->data;
                    temp->next = nullptr;
                    r->next = temp;
                    r = r->next;
                    p = p->next;
                } else if (p->data->j > q->data->j) {
                    temp->data = q->data;
                    temp->next = nullptr;
                    r->next = temp;
                    r = r->next;
                    q = q->next;
                } else {
                    temp->data = q->data;
                    temp->data->val += p->data->val;
                    temp->next = nullptr;
                    r->next = temp;
                    r = r->next;
                    q = q->next;
                    p = p->next;
                }
            }

        }

        if (p) {
            r->next = p;
            p = p->next;
        }
        if (q) {
            r->next = q;
            q = q->next;
        }

        return *tr;
    }
    return Sparse(0, 0, 0);
}

void Sparse::display() {

    if (first) {
        Node *p = first->next;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (p->data->i == i && p->data->j == j) {
                    cout << p->data->val << " ";
                    if (p->next)
                        p = p->next;
                } else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
}

Node *Sparse::getFirst() const {
    return first;
}

Sparse::~Sparse() {
    auto *temp = first;
    while(temp) {
        first = first->next;
        delete temp;
        temp = first;
    }
}

