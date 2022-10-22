//
// Created by vivek on 22-10-2022.
//

#ifndef SPARSE_SPARSE_H
#define SPARSE_SPARSE_H

#include <ostream>

struct Element {
    unsigned i{};
    unsigned j{};
    int value{};

    Element() = default;
};

class Sparse {
    unsigned int row;       // Number of rows the sparse matrix will have
    unsigned int col;       // Number of columns the sparse matrix will have
    unsigned int nonZeroCount;          // number of non zero elements
    Element *array;         // an array of elements
public:
    Sparse(unsigned int row, unsigned int col, unsigned int nonZeroCount);

    int get(unsigned int row, unsigned int col) const;

    friend std::ostream &operator<<(std::ostream &os, const Sparse &sparse);

    friend std::istream &operator>>(std::istream &is, const Sparse &sparse);

    Sparse operator+(Sparse &s);

    unsigned int getRow() const;

    unsigned int getCol() const;

    unsigned int getNonZeroCount() const;

    virtual ~Sparse();
};


#endif //SPARSE_SPARSE_H
