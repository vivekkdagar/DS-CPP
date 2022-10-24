//
// Created by vivek on 24-10-2022.
//

#ifndef TOEPLITZ_TOEPLITZ_H
#define TOEPLITZ_TOEPLITZ_H


#include <vector>
#include <ostream>

class Toeplitz {
    std::vector<int> array;
    unsigned dimensions;
public:
    explicit Toeplitz(unsigned int dimensions);

    void set(unsigned i, unsigned j, int val);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const Toeplitz &toeplitz);

    unsigned int getDimensions() const;

    virtual ~Toeplitz();
};


#endif //TOEPLITZ_TOEPLITZ_H
