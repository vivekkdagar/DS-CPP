//
// Created by vivek on 22-10-2022.
//

#ifndef TOEPLITZ_TOEPLITZ_H
#define TOEPLITZ_TOEPLITZ_H


#include <vector>
#include <ostream>

class Toeplitz {
    unsigned dimensions;
    std::vector<int> array;
public:
    explicit Toeplitz(unsigned int dimensions);

    unsigned int getDimensions() const;

    int get(unsigned i, unsigned j) const;

    void set(unsigned i, unsigned j, int value);

    friend std::ostream &operator<<(std::ostream &os, const Toeplitz &toeplitz);

    virtual ~Toeplitz();
};


#endif //TOEPLITZ_TOEPLITZ_H
