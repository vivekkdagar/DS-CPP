//
// Created by vivek on 22-10-2022.
//

#include "TriDiagonal.h"

TriDiagonal::TriDiagonal(unsigned int dimensions) : dimensions(dimensions) {
    unsigned size = 3 * dimensions - 2;
    array.resize(size);
}

unsigned int TriDiagonal::getDimensions() const {
    return dimensions;
}

void TriDiagonal::set(unsigned int i, unsigned int j, int value) {
    if (i - j == 1)
        this->array[i - 2] = value;
    else if (i - j == 0)
        this->array[dimensions + i - 2] = value;
    else if (i - j == -1)
        this->array[2 * dimensions + i - 2] = value;
}

int TriDiagonal::get(unsigned int i, unsigned int j) const {
    if (i - j == 1)
        return this->array[i - 2];
    else if (i - j == 0)
        return this->array[dimensions + i - 2];
    else if (i - j == -1)
        return this->array[2 * dimensions + i - 2];
    else
        return 0;
}

std::ostream &operator<<(std::ostream &os, const TriDiagonal &diagonal) {
    for (int i{1}; i <= 5; i++) {
        for (int j{1}; j <= 5; j++) {
            if (i - j == 1)
                os << diagonal.array[i - 2] << " ";
            else if (i - j == 0)
                os << diagonal.array[diagonal.dimensions + i - 2] << " ";
            else if (i - j == -1)
                os << diagonal.array[2 * diagonal.dimensions + i - 2] << " ";
            else
                os << 0 << " ";
        }
        os << std::endl;
    }
    return os;
}

TriDiagonal::~TriDiagonal() {
    array.clear();
}
