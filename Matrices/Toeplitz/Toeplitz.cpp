//
// Created by vivek on 22-10-2022.
//

#include "Toeplitz.h"

Toeplitz::Toeplitz(unsigned int dimensions) : dimensions(dimensions) {
    array.resize(2 * dimensions - 1);       // number of non 0 elements
}

unsigned int Toeplitz::getDimensions() const {
    return dimensions;
}

int Toeplitz::get(unsigned int i, unsigned int j) const {
    if (i <= j)
        return array[j - i];
    else if (i > j)
        return array[this->dimensions + i - j - 1];
}

void Toeplitz::set(unsigned int i, unsigned int j, int value) {
    if (i <= j)
        array[j - i] = value;
    else if (i > j)
        array[this->dimensions + i - j - 1] = value;
}

std::ostream &operator<<(std::ostream &os, const Toeplitz &toeplitz) {
    for (int i{1}; i <= toeplitz.dimensions; i++) {
        for (int j{1}; j <= toeplitz.dimensions; j++) {
            os << toeplitz.get(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

Toeplitz::~Toeplitz() {
    array.clear();
}
