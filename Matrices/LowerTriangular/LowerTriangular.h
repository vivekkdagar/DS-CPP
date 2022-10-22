//
// Created by vivek on 22-10-2022.
//

#ifndef LOWERTRIANGULAR_LOWERTRIANGULAR_H
#define LOWERTRIANGULAR_LOWERTRIANGULAR_H


#include <vector>
#include <ostream>

class LowerTriangular {
    unsigned dimensions;
    std::vector<int> array;
public:
    explicit LowerTriangular(unsigned int dimensions) : dimensions(dimensions) {
        array.resize(dimensions * (dimensions + 1) /
                     2);         // n * (n+1)/2 non 0 elements are in a lower triangular matrix
    }

    unsigned int getDimensions() const;

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const LowerTriangular &triangular);

    virtual ~LowerTriangular();

};


#endif //LOWERTRIANGULAR_LOWERTRIANGULAR_H
