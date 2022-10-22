//
// Created by vivek on 22-10-2022.
//

#include "Sparse.h"

//
// Created by Vivek on 28-08-2022.
//

#include "Sparse.h"
#include <iostream>

Sparse::Sparse(unsigned int row, unsigned int col, unsigned int nonZeroCount) : row(row), col(col),
                                                                                nonZeroCount(nonZeroCount) {
    array = new Element[nonZeroCount];
}


int Sparse::get(unsigned int row, unsigned int col) const {
    int k{0};
    for (int i{0}; i < row; i++) {
        for (int j{0}; j < col; j++) {
            if (this->array[k].i == i && this->array[k].j == j) {
                return this->array[k].value;
            } else {
                k++;
            }
        }
    }
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Sparse &sparse) {
    int k{0};
    for (int i{0}; i < sparse.row; i++) {
        for (int j{0}; j < sparse.col; j++) {
            if (sparse.array[k].i == i && sparse.array[k].j == j) {
                os << sparse.array[k++].value << " ";
            } else {
                os << 0 << " ";
            }
        }
        os << "\n";
    }
    return os;
}

unsigned int Sparse::getRow() const {
    return row;
}

unsigned int Sparse::getCol() const {
    return col;
}

unsigned int Sparse::getNonZeroCount() const {
    return nonZeroCount;
}

std::istream &operator>>(std::istream &is, const Sparse &sparse) {
    for (int i{0}; i < sparse.nonZeroCount; i++) {
        std::cout << "Enter row, col & value of non 0 element #" << i + 1 << ": ";
        is >> sparse.array[i].i >> sparse.array[i].j >> sparse.array[i].value;
        std::cout << std::endl;
    }
    return is;
}

Sparse Sparse::operator+(Sparse &s) {
    unsigned int c1{0}, c2{0}, c3{0};
    if (this->row != s.row || this->col != s.col)
        return Sparse(0, 0, 0);

    Sparse *sum = new Sparse(this->row, this->col, this->nonZeroCount + s.nonZeroCount);

    while (c1 < this->nonZeroCount && c2 < s.nonZeroCount) {
        if (this->array[c1].i < s.array[c2].j)
            sum->array[c3++] = this->array[c1++];
        else if (this->array[c1].i > s.array[c2].i)
            sum->array[c3++] = s.array[c2++];
        else {
            if (this->array[c1].j < s.array[c2].j)
                sum->array[c3++] = this->array[c1++];
            else if (this->array[c1].j < s.array[c2].j)
                sum->array[c3++] = s.array[c2++];
            else {
                sum->array[c3] = this->array[c1];
                sum->array[c3++].value = this->array[c1++].value + s.array[c2++].value;
            }
        }
    }
    for (; c1 < this->nonZeroCount; c1++)
        sum->array[c3++] = this->array[c1];
    for (; c2 < s.nonZeroCount; c2++)
        sum->array[c3++] = s.array[c2];
    sum->nonZeroCount = c3;
    return *sum;

}


Sparse::~Sparse() {
    delete[]array;
}