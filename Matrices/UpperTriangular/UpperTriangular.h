//
// Created by vivek on 22-10-2022.
//

#ifndef UPPERTRIANGULAR_UPPERTRIANGULAR_H
#define UPPERTRIANGULAR_UPPERTRIANGULAR_H

#include <ostream>

class UpperTriangular {
    unsigned dimensions;
    int *array;
public:
    explicit UpperTriangular(unsigned int dimensions);

    void set(unsigned i, unsigned j, int value);

    int get(unsigned i, unsigned j) const;

    friend std::ostream &operator<<(std::ostream &os, const UpperTriangular &triangular);

    unsigned int getDimensions() const;

    virtual ~UpperTriangular();
};


#endif //UPPERTRIANGULAR_UPPERTRIANGULAR_H
