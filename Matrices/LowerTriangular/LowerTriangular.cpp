//
// Created by vivek on 22-10-2022.
//

#include "LowerTriangular.h"

void LowerTriangular::set(unsigned int i, unsigned int j, int value) {
    if (i >= j)
        array.at(i * (i - 1) / 2 + (j - 1)) = value;         // row major mapping formula
}

int LowerTriangular::get(unsigned int i, unsigned int j) const {
    if (i >= j)
        return array.at(i * (i - 1) / 2 + (j - 1));
    return 0;
}

std::ostream &operator<<(std::ostream &os, const LowerTriangular &triangular) {
    for (int i{1}; i <= triangular.getDimensions(); i++) {
        for (int j{1}; j <= triangular.getDimensions(); j++) {
            os << triangular.get(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}

unsigned int LowerTriangular::getDimensions() const {
    return dimensions;
}

LowerTriangular::~LowerTriangular() {
    array.clear();
}
