//
// Created by vivek on 24-10-2022.
//

#include "Toeplitz.h"

Toeplitz::Toeplitz(unsigned int dimensions) : dimensions(dimensions) {
    array.resize((2 * dimensions) - 1);
}

void Toeplitz::set(unsigned int i, unsigned int j, int val) {
    if (i <= j)
        this->array.at(j - i) = val;
    if (i > j)
        this->array.at(this->dimensions + i - j - 1) = val;
}

int Toeplitz::get(unsigned int i, unsigned int j) const {
    if (i <= j)
        return this->array.at(j - i);
    if (i > j)
        return this->array[this->dimensions + i - j - 1];
}

std::ostream &operator<<(std::ostream &os, const Toeplitz &toeplitz) {
    printf ("\nMatrix is: \n");
    for (int i = 1; i <= toeplitz.dimensions; i++) {
        for (int j = 1; j <= toeplitz.dimensions; j++) {
            os << toeplitz.get(i,j) << " ";
        }
        os << std::endl;
    } return os;
}

unsigned int Toeplitz::getDimensions() const {
    return dimensions;
}

Toeplitz::~Toeplitz() {
    array.clear();
}
