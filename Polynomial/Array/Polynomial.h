//
// Created by vivek on 22-10-2022.
//

#ifndef ARRAY_POLYNOMIAL_H
#define ARRAY_POLYNOMIAL_H

#include <vector>
#include <ostream>

struct Term {
    unsigned exponent{};
    int coefficient{};

    Term(unsigned int exponent, int coefficient) : exponent(exponent), coefficient(coefficient) {}

    Term() = default;
};

class Polynomial {
    unsigned length;
    std::vector<Term> list;
public:
    explicit Polynomial(unsigned int length) : length(length) {
        list.resize(length);
    }

    unsigned int size() const {
        return length;
    }

    int eval(int x);

    friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
        for (int i{0}; i < polynomial.length; i++) {
            os << polynomial.list.at(i).coefficient << "x^" << polynomial.list.at(i).exponent;
            if (i != polynomial.length - 1)
                os << " + ";
        }
        return os;
    }

    void set();

    Polynomial add(Polynomial src);

    virtual ~Polynomial();
};


#endif //ARRAY_POLYNOMIAL_H
