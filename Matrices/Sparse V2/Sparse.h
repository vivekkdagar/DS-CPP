//
// Created by vivek on 22-10-2022.
//

#ifndef SPARSE_V2_SPARSE_H
#define SPARSE_V2_SPARSE_H

struct Element {
    int i{};
    int j{};
    int val{};

    Element() = default;

    Element(int i, int j, int val) : i(i), j(j), val(val) {}
};

struct Node {
    Element *data{};
    Node *next{};

    explicit Node(Element *ele) : data(ele) {
        next = nullptr;
    }

    Node() = default;
};

class Sparse {
    int rows;
    int cols;
    int nonZeroCount;
    Node *first;
public:
    Sparse(int rows, int cols, int nums);

    Sparse operator+(Sparse &s);

    void append(int i, int j, int x);

    void display();

    Node *getFirst() const;

    virtual ~Sparse();
};


#endif //SPARSE_V2_SPARSE_H
