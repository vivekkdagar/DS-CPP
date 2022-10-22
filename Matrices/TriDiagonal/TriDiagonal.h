//
// Created by vivek on 22-10-2022.
//

#ifndef TRIDIAGONAL_TRIDIAGONAL_H
#define TRIDIAGONAL_TRIDIAGONAL_H


#include <vector>
#include <ostream>

class TriDiagonal {
    unsigned dimensions;
    std::vector<int> array;
public:
    explicit TriDiagonal(unsigned int dimensions);

    unsigned int getDimensions() const;

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const TriDiagonal &diagonal);

    virtual ~TriDiagonal();
};


#endif //TRIDIAGONAL_TRIDIAGONAL_H
